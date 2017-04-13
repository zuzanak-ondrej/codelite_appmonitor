/**
 * @file
 * @author zuzanak
 * @date 2017
 * @copyright GNU General Public License v2
 */

#include "visualizer.h"

Visualizer::Visualizer(wxWindow* parent) : wxBoxSizer(wxVERTICAL)
{
    m_parent = parent;
    
    m_samplingPeriod = 2000;
    m_counter = 0;
    m_PID = 0;
    m_settings = NULL;
    
    wxBoxSizer *verticalSizer = new wxBoxSizer(wxHORIZONTAL);
    
    m_CPUChart = new SimpleDynamicChart(parent, wxID_ANY);
    m_CPUChart->SetTimeStep(m_samplingPeriod);
    m_CPUChart->SetLeftAxisLabelFormat(_("%.0f"));
    m_CPUChart->SetBottomAxisLabelFormat(_("%.0f"));
    m_CPUChart->SetLeftAxisTittle(_("CPU [%]"));
    m_CPUChart->SetTitle(_("CPU usage"));
    m_CPUChart->SetMargin(4, 0, 0, 30);
    
    verticalSizer->Add(m_CPUChart, 1, wxEXPAND);

    m_MemChart = new SimpleDynamicChart(parent, wxID_ANY);
    m_MemChart->SetTimeStep(m_samplingPeriod);
    m_MemChart->SetmMaxYBound(10);
    m_MemChart->SetAutoRange(true);
    m_MemChart->SetLeftAxisLabelFormat(_("%.0f"));
    m_MemChart->SetBottomAxisLabelFormat(_("%.0f"));
    m_MemChart->SetLeftAxisTittle(_("memory [MiB]"));
    m_MemChart->SetTitle(_("Memory usage"));
    m_MemChart->SetMargin(4, 0, 0, 30);

    verticalSizer->Add(m_MemChart, 1, wxEXPAND);

    this->Add(verticalSizer, 4, wxEXPAND);
    
    m_sizerDiscAndTextInfo = new wxBoxSizer( wxHORIZONTAL );

    m_logToFile = false;    
    m_allowedDiscChart = false;
    m_DiscChart = NULL; 
    m_sizerDiscAndTextInfo->Add( CreateTextInfo(6, false), 0, wxALIGN_TOP|wxALL, 5 );
    this->Add( m_sizerDiscAndTextInfo, 1, wxEXPAND|wxLEFT, 50 );
    
    m_sigarManag = SigarManager::Instance();

    m_timer = new wxTimer(this);

    this->Connect(m_timer->GetId(), wxEVT_TIMER, wxTimerEventHandler(Visualizer::OnTimerTimeout));

    m_isRunning = false;
    m_isPaused = false;
}

Visualizer::~Visualizer()
{
    m_timer->Stop();
    this->Disconnect(m_timer->GetId(), wxEVT_TIMER,wxTimerEventHandler(Visualizer::OnTimerTimeout), NULL, this );
    delete m_timer;
    
    m_sigarManag->Release();
}

wxGridSizer *Visualizer::CreateTextInfo(int numberOfColumns, bool withDiscGraph)
{
    m_sizerTextInfo = new wxGridSizer( 0, numberOfColumns, 0, 0 );
    
    m_titlePID = new wxStaticText( m_parent, wxID_ANY, _("Process PID:"), wxDefaultPosition, wxDefaultSize, 0 );
    m_titlePID->Wrap( -1 );
    m_titlePID->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
    m_sizerTextInfo->Add( m_titlePID, 0, wxALL, 5 );
    
    m_valuePID = new wxStaticText( m_parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), 0 );
    m_valuePID->Wrap( -1 );
    m_sizerTextInfo->Add( m_valuePID, 0, wxALL, 5 );
    
    m_titleState = new wxStaticText( m_parent, wxID_ANY, _("Process state:"), wxDefaultPosition, wxDefaultSize, 0 );
    m_titleState->Wrap( -1 );
    m_titleState->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
    m_sizerTextInfo->Add( m_titleState, 0, wxALL, 5 );
    
    m_valueState = new wxStaticText( m_parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), 0 );
    m_valueState->Wrap( -1 );
    m_sizerTextInfo->Add( m_valueState, 0, wxALL, 5 );
    
    
    if (withDiscGraph)
    {
        m_legendCPUUsage = new ChartLegend(m_parent, wxID_ANY, _("CPU usage:"), m_settings->GetColorCPUUsage());
        m_sizerTextInfo->Add( m_legendCPUUsage, 0, wxALL, 5 );
   
        m_valueCPUUsage = new wxStaticText( m_parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), 0 );
        m_valueCPUUsage->Wrap( -1 );
        m_sizerTextInfo->Add( m_valueCPUUsage, 0, wxALL, 5 );
   
        m_legendMemUsage = new ChartLegend(m_parent, wxID_ANY, _("Memory usage:"), m_settings->GetColorMemoryUsage());
        m_sizerTextInfo->Add( m_legendMemUsage, 0, wxALL, 5 );
   
        m_valueMemUsage = new wxStaticText( m_parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), 0 );
        m_valueMemUsage->Wrap( -1 );
        m_sizerTextInfo->Add( m_valueMemUsage, 0, wxALL, 5 );
        
        m_legendDiscWriting = new ChartLegend(m_parent, wxID_ANY, _("Disc writing:"), m_settings->GetColorDiscWriting());
        m_sizerTextInfo->Add( m_legendDiscWriting, 0, wxALL, 5 );
   
        m_valueDiscUsage = new wxStaticText( m_parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), 0 );
        m_valueDiscUsage->Wrap( -1 );
        m_sizerTextInfo->Add( m_valueDiscUsage, 0, wxALL, 5 );
   
        m_legendDiscReading = new ChartLegend(m_parent, wxID_ANY, _("Disc reading:"), m_settings->GetColorDiscReading());
        m_sizerTextInfo->Add( m_legendDiscReading, 0, wxALL, 5 );
   
        m_valueDiscReading = new wxStaticText( m_parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), 0 );
        m_valueDiscReading->Wrap( -1 );
        m_sizerTextInfo->Add( m_valueDiscReading, 0, wxALL, 5 );
    }
    else
    {
        m_titleDiscUsage = new wxStaticText( m_parent, wxID_ANY, _("Disc writing:"), wxDefaultPosition, wxDefaultSize, 0 );
        m_titleDiscUsage->Wrap( -1 );
        m_titleDiscUsage->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
        m_sizerTextInfo->Add( m_titleDiscUsage, 0, wxALL, 5 );
        
        m_valueDiscUsage = new wxStaticText( m_parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), 0 );
        m_valueDiscUsage->Wrap( -1 );
        m_sizerTextInfo->Add( m_valueDiscUsage, 0, wxALL, 5 );
                
        if (m_settings == NULL)
        {
            m_titleCPUUsage = new wxStaticText( m_parent, wxID_ANY, _("CPU usage:"), wxDefaultPosition, wxDefaultSize, 0 );
            m_titleCPUUsage->Wrap( -1 );
            m_titleCPUUsage->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
            m_sizerTextInfo->Add( m_titleCPUUsage, 0, wxALL, 5 );
        }
        else
        {
            m_legendCPUUsage = new ChartLegend(m_parent, wxID_ANY, _("CPU usage:"), m_settings->GetColorCPUUsage());
            m_sizerTextInfo->Add( m_legendCPUUsage, 0, wxALL, 5 );            
        }
        
        m_valueCPUUsage = new wxStaticText( m_parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), 0 );
        m_valueCPUUsage->Wrap( -1 );
        m_sizerTextInfo->Add( m_valueCPUUsage, 0, wxALL, 5 );
        
        if (m_settings == NULL)
        {
            m_titleMemUsage = new wxStaticText( m_parent, wxID_ANY, _("Memory usage:"), wxDefaultPosition, wxDefaultSize, 0 );
            m_titleMemUsage->Wrap( -1 );
            m_titleMemUsage->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
            m_sizerTextInfo->Add( m_titleMemUsage, 0, wxALL, 5 );
        }
        else
        {
            m_legendMemUsage = new ChartLegend(m_parent, wxID_ANY, _("Memory usage:"), m_settings->GetColorMemoryUsage());
            m_sizerTextInfo->Add( m_legendMemUsage, 0, wxALL, 5 );            
        }
            
        m_valueMemUsage = new wxStaticText( m_parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), 0 );
        m_valueMemUsage->Wrap( -1 );
        m_sizerTextInfo->Add( m_valueMemUsage, 0, wxALL, 5 );
    
        m_titleDiscReading = new wxStaticText( m_parent, wxID_ANY, _("Disc reading:"), wxDefaultPosition, wxDefaultSize, 0 );
        m_titleDiscReading->Wrap( -1 );
        m_titleDiscReading->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
        m_sizerTextInfo->Add( m_titleDiscReading, 0, wxALL, 5 );
    
        m_valueDiscReading = new wxStaticText( m_parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), 0 );
        m_valueDiscReading->Wrap( -1 );
        m_sizerTextInfo->Add( m_valueDiscReading, 0, wxALL, 5 );

    }
    
    return m_sizerTextInfo;
}

void Visualizer::Start(int PID, IManager *mgr)
{
    if (!m_isRunning)
    {
        m_mgr = mgr;
        m_PID = PID;
        Reset();
        PrepareFileForLog();
        
        m_timer->Start(m_samplingPeriod);
        m_isRunning = true;
    }
}

void Visualizer::Stop()
{
    if (m_isRunning)
    {
        m_timer->Stop();
        m_isRunning = false;
    }
}

void Visualizer::Reset()
{
    if (m_isRunning)
    {
        m_timer->Stop();
        m_isRunning = false;
    }
    
    m_CPUChart->Clean();
    m_MemChart->Clean();
    if (m_allowedDiscChart)
    {
        m_DiscChart->Clean();
    }
    
    m_valuePID->SetLabel(wxEmptyString);
    m_valueState->SetLabel(wxEmptyString);
}

void Visualizer::Pause()
{
    if (m_isRunning && !m_isPaused)
    {
        m_timer->Stop();
        m_isPaused = true;
    }
}

void Visualizer::Continue()
{
    if (m_isRunning && m_isPaused)
    {
        m_timer->Start(m_samplingPeriod);
        m_isPaused = false;
    }
}

void Visualizer::ApplySettings(AppMonitorSettings *settings)
{
    m_settings = settings;
    
    if (m_isRunning == true)
    {
        return;
    }

    m_allowedDiscChart = m_settings->GetShowDiscUsage();
    if (m_allowedDiscChart)
    {
        m_sizerTextInfo->Clear(true);
        m_sizerDiscAndTextInfo->Clear(true);
        m_sizerDiscAndTextInfo->Remove(m_sizerTextInfo);
        this->Detach(m_sizerDiscAndTextInfo);
        
        int countCurves = 2; 
        
        m_DiscChart = new MultipleDynamicChart(countCurves, m_parent, wxID_ANY/*frame->GetId()*/);
        m_DiscChart->SetTimeStep(m_samplingPeriod);
        m_DiscChart->SetmMaxYBound(10);
        m_DiscChart->SetAutoRange(true);
        m_DiscChart->SetLeftAxisLabelFormat(_("%.0f"));
        m_DiscChart->SetBottomAxisLabelFormat(_("%.0f"));
        m_DiscChart->SetLeftAxisTittle(_("Disc [MiB]"));
        m_DiscChart->SetTitle(_("Disc usage"));
        m_DiscChart->SetMargin(4, 5, 0, 30);
        
        wxPen arrayCurvePen[countCurves];
        wxColour arrayCurveColour[countCurves];
        
        arrayCurvePen[0] = wxPen(m_settings->GetColorDiscReading());
        arrayCurveColour[0] = m_settings->GetColorDiscReading();        
        arrayCurvePen[1] = wxPen(m_settings->GetColorDiscWriting());
        arrayCurveColour[1] = m_settings->GetColorDiscWriting();
        m_DiscChart->SetCurvePen(arrayCurvePen, arrayCurveColour);

        m_sizerDiscAndTextInfo->Add(m_DiscChart, 1, wxEXPAND);
        m_sizerDiscAndTextInfo->Add( CreateTextInfo(4, true), 1, wxALIGN_CENTER|wxLEFT, 50 );
    
        this->Add( m_sizerDiscAndTextInfo, 4, wxEXPAND);
        this->Layout();
    }
    else
    {
        m_sizerTextInfo->Clear(true);
        m_sizerDiscAndTextInfo->Clear(true);
        m_sizerDiscAndTextInfo->Remove(m_sizerTextInfo);
        this->Detach(m_sizerDiscAndTextInfo);

        m_sizerDiscAndTextInfo->Add( CreateTextInfo(6, false), 0, wxALIGN_TOP|wxLEFT, 50 );
        this->Add( m_sizerDiscAndTextInfo, 1, wxEXPAND|wxLEFT, 15 );
        this->Layout();
    }
    
    
    wxColour colour = m_settings->GetColorCPUUsage();
    m_CPUChart->SetCurvePen(wxPen(colour), colour);
    colour = m_settings->GetColorMemoryUsage();
    m_MemChart->SetCurvePen(wxPen(colour), colour);
    
    m_logToFile = m_settings->GetLogToFile();
    if (m_logToFile)
    {
        m_logFileName = m_settings->GetLogFileName();   
    }
    
    m_samplingPeriod = m_settings->GetRefreshTime();
    m_MemChart->SetTimeStep(m_samplingPeriod);
    m_CPUChart->SetTimeStep(m_samplingPeriod);
    if (m_allowedDiscChart)
    {
        m_DiscChart->SetTimeStep(m_samplingPeriod);;
    }
    
    if (m_samplingPeriod < 1000)
    {
        m_CPUChart->SetBottomAxisLabelFormat(_("%.1f"));
        m_MemChart->SetBottomAxisLabelFormat(_("%.1f"));
        if (m_allowedDiscChart)
        {
            m_DiscChart->SetBottomAxisLabelFormat(_("%.1f"));
        }
    }
    else
    {
        m_CPUChart->SetBottomAxisLabelFormat(_("%.0f"));
        m_MemChart->SetBottomAxisLabelFormat(_("%.0f"));
        if (m_allowedDiscChart)
        {
            m_DiscChart->SetBottomAxisLabelFormat(_("%.0f"));
        }
    }
    
    Reset();
}

void Visualizer::OnTimerTimeout(wxTimerEvent &ev)
{
    updateData();
}

void Visualizer::updateData()
{
    double arrayDiskValues[2];
    
    m_processState = m_sigarManag->GetThreadInfo(m_PID);

    m_MemChart->AddData(m_processState.ResidentMemory);
    
    m_CPUChart->AddData(m_processState.Percent);
    
    if (m_allowedDiscChart)
    {
        arrayDiskValues[0] = m_processState.DiskRead;
        arrayDiskValues[1] = m_processState.DiskWritten;
        m_DiscChart->AddData(arrayDiskValues);
    }
    
    //
    // text informations
    //
    m_valuePID->SetLabel(wxString() << m_processState.PID);
    
    m_valueState->SetLabel(stateToString(m_processState.State));
    
    m_valueCPUUsage->SetLabel(wxString() << wxString::Format(_("%.0f"), m_processState.Percent) << _(" %"));
    m_valueMemUsage->SetLabel(wxString() << wxString::Format(_("%.1f"), m_processState.ResidentMemory) << _(" MiB"));
    m_valueDiscUsage->SetLabel(wxString() << wxString::Format(_("%.1f"), m_processState.DiskWritten) << _(" MiB"));
    m_valueDiscReading->SetLabel(wxString() << wxString::Format(_("%.1f"), m_processState.DiskRead) << _(" MiB"));
    
    //
    // Logging values to file
    //
    LogValuesToFile(m_processState);
    
    m_counter ++;
}

void Visualizer::LogValuesToFile(structProcessState processState)
{
    if (m_logToFile)
    {
        logFile.Open(m_outputLogFileName);
        
        logFile.AddLine(wxString::Format(_("%.0f;%.1f;%.1f;%.1f"), processState.Percent, processState.ResidentMemory, processState.DiskRead, processState.DiskWritten));
        
        logFile.Write();
        logFile.Close();
    }
}

void Visualizer::PrepareFileForLog()
{
    if (m_logToFile)
    {
        ProjectPtr project = m_mgr->GetSelectedProject();
        if(project) 
        {
            m_outputLogFileName = wxFileName(project.Get()->GetProjectPath(), 
                                            m_logFileName).GetFullPath();
        }
        
        if (wxFileExists(m_outputLogFileName))
        {
            wxRemoveFile(m_outputLogFileName);
        }
        logFile.Create(m_outputLogFileName);
        logFile.Close();
    }    
}

wxString Visualizer::stateToString(char state)
{
    switch (state)
    {
        case 'S' :
            return _("Sleep");
        case 'R' :
            return _("Run");
        case 'T' :
            return _("Stop");
        case 'Z' :
            return _("Zombie");
        case 'D' :
            return _("IDLE");
    }
}