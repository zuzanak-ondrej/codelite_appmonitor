/**
 * @file
 * @author zuzanak
 * @date 2017
 * @copyright GNU General Public License v2
 */

#include "basedynamicchart.h"

BaseDynamicChart::BaseDynamicChart(wxWindow* parent, wxWindowID id, 
                                   const wxPoint& pos, const wxSize& size, long style) 
            : wxPanel(parent, id, pos, size, style)
{
#ifdef __WXMSW__ // Windows;
    SetDoubleBuffered(true);
#endif
    
    m_countCurves = 0;
    
    m_initialCountXLabel = 7;
    m_initialCountYLabel = 11;
    
    PrepareNumLabels();
    m_activeNumLabels = 0;
    
    m_initialMaxYBound = 100;
    
    SetMargin(10);
       
    m_timeStep = DEFAULT_TIME_STEP;
    m_minXBound = DEFAULT_MIN_X_AXIS_BOUND;
    m_maxXBound = DEFAULT_MAX_X_AXIS_BOUND;
    
    m_bottomAxis = new Axis(AXIS_BOTTOM);
    m_bottomAxis->SetBounds(m_minXBound, m_maxXBound);
    m_bottomAxis->SetLabelCount(m_initialCountXLabel);
    m_bottomAxis->SetLabelFormat(wxT("%.1f"));
    m_bottomAxis->SetTitleLocation(wxRIGHT);
    m_bottomAxis->SetTitle(_("Time [s]"));
    
    m_leftAxis = new Axis(AXIS_LEFT);
    m_leftAxis->SetMaxValue(m_initialMaxYBound);
    m_leftAxis->SetLabelCount(m_initialCountYLabel);
    m_leftAxis->SetTitleLocation(wxTOP);
    m_leftAxis->SetVerticalTitleText(true);
    
    m_autoLabelCount = true;
    
    m_stepExtensionRange = m_leftAxis->GetMaxValue() / (double)(m_leftAxis->GetLabelCount() - 1);
    m_autoYRange = false;

    m_titleFont = *wxNORMAL_FONT;
    m_titleFont.SetWeight(wxFONTWEIGHT_BOLD);
    m_titleFont.SetPointSize(12);
    m_titleColour = *wxBLACK;
    
    m_dataBorderBackgroundPen = *wxBLACK_PEN;
    m_dataFillBackgroundBrush = wxColour(227, 227, 227);

    Connect(this->GetId(), wxEVT_PAINT, wxPaintEventHandler(BaseDynamicChart::OnPaint));
    Connect(this->GetId(), wxEVT_SIZE, wxSizeEventHandler(BaseDynamicChart::OnResize));
}

BaseDynamicChart::~BaseDynamicChart()
{
    Disconnect(this->GetId(), wxEVT_PAINT, wxPaintEventHandler(BaseDynamicChart::OnPaint));
    Disconnect(this->GetId(), wxEVT_SIZE, wxSizeEventHandler(BaseDynamicChart::OnResize));
    
    delete m_bottomAxis;
    delete m_leftAxis;
    
    FreeDataset();
}

void BaseDynamicChart::FreeDataset()
{
    for (int i = 0; i < m_countCurves; i ++)
    {
        delete m_data[i];
    }
}

void BaseDynamicChart::PrepareNumLabels()
{
    unsigned int number;
    unsigned int countLabel = m_initialCountYLabel;
    
    m_numbersLabels.push_back(countLabel);
    while ((number = countLabel / 2 + 1) != countLabel)
    {
        countLabel = number;
        m_numbersLabels.push_back(countLabel);
    }
    
    return;
}

void BaseDynamicChart::OnPaint(wxPaintEvent& event)
{
    Draw();
}

void BaseDynamicChart::OnResize(wxSizeEvent& event)
{
    Refresh();
    event.Skip();
}

void BaseDynamicChart::DrawDataBackgroun(wxGraphicsContext &gc, wxRect rc)
{
    gc.SetPen(m_dataBorderBackgroundPen);
    gc.SetBrush(m_dataFillBackgroundBrush);
    gc.DrawRectangle(rc.x, rc.y, rc.width, rc.height);
}

void BaseDynamicChart::DrawTitle(wxGraphicsContext &gc, wxRect rect)
{
    if (m_title.Length() != 0) 
    {
        gc.SetFont(m_titleFont, m_titleColour);
    
        wxDouble descent;
        wxDouble externalLeading;
        wxDouble labelExtentX;
        wxDouble labelExtentY;
        gc.GetTextExtent(m_title, &labelExtentX, &labelExtentY, &descent, &externalLeading);

        rect.height = labelExtentY + 2;
        
        // center
        wxCoord x = rect.x + (rect.GetWidth() - labelExtentX) / 2;
        wxCoord y = rect.y + (rect.GetHeight() - labelExtentY) / 2;
        
        gc.DrawText(m_title, x, y);
    }
}

wxRect BaseDynamicChart::CalcPlotRect(wxGraphicsContext &gc, wxRect rc)
{
    int topMargin = m_marginTop;
    if (m_title.Length() != 0) 
    {
        gc.SetFont(m_titleFont, m_titleColour);
        wxDouble labelExtentX;
        wxDouble labelExtentY;
        gc.GetTextExtent(m_title, &labelExtentX, &labelExtentY, NULL, NULL);
        topMargin += labelExtentY;
    }
    
    Margins(rc, m_marginLeft, topMargin, m_marginRight, m_marginBottom);
    return rc;
}

void BaseDynamicChart::AutoLabelCount(wxGraphicsContext &gc, wxRect rect)
{
    bool change = true;
    for (int t = 0; t < 5 && change; t ++)
    {
        change = false;
        
        wxSize labelExtentLeftAxis = m_leftAxis->GetLongestLabelExtent(gc);
            
        unsigned int countLabel = m_leftAxis->GetLabelCount();
    
        if ((unsigned)labelExtentLeftAxis.y - 1 > rect.height / countLabel)
        {
            if (m_activeNumLabels + 1 <= m_numbersLabels.size() - 1)
            {
                m_activeNumLabels = m_activeNumLabels + 1;
                m_leftAxis->SetLabelCount(m_numbersLabels[m_activeNumLabels]);
                change = true;
            }
        }
        else if (m_initialCountYLabel > countLabel && ((unsigned)labelExtentLeftAxis.y * 2) + 1 < rect.height / countLabel)
        {
            if (m_activeNumLabels - 1 >= 0)
            {
                m_activeNumLabels = m_activeNumLabels - 1;
                m_leftAxis->SetLabelCount(m_numbersLabels[m_activeNumLabels]);
                change = true;
            }
        }
    }
}

void BaseDynamicChart::AutoRange()
{
    double maxValueLeftAxis = m_leftAxis->GetMaxValue();
    double maxValue = GetLargestValue();

    if (maxValueLeftAxis < maxValue)
    {   
        while (maxValueLeftAxis < maxValue)
        {
            maxValueLeftAxis += m_stepExtensionRange;
        }
        
        m_leftAxis->SetMaxValue(maxValueLeftAxis);
    }
    else if (m_initialMaxYBound < maxValueLeftAxis && maxValueLeftAxis - m_stepExtensionRange > maxValue)
    {
        maxValueLeftAxis -= m_stepExtensionRange;
        m_leftAxis->SetMaxValue(maxValueLeftAxis);
    }
}

double BaseDynamicChart::GetLargestValue()
{
    double largestValue = 0;
    double val = 0;
    
    for (int i = 0; i < m_countCurves; i ++)
    {
        val = m_data[i]->GetLargestValue();
        
        if (largestValue < val)
        {
            largestValue = val;
        }
    }
    
    return largestValue;
}

void BaseDynamicChart::ShiftTimeline()
{
    bool isFull = false;
    
    for (int i = 0; i < m_countCurves; i ++)
    {
        if (m_data[i]->IsFull())
        {
            isFull = true;
            break;
        }
    }
    
    if (isFull)
    {
        m_bottomAxis->SetBounds(m_minXBound, m_maxXBound);
        m_minXBound += m_timeStep;
        m_maxXBound += m_timeStep;
    }
}

void BaseDynamicChart::CreateDataset(unsigned int countValues)
{
    for (int i = 0; i < m_countCurves; i ++)
    {
        m_countValues = countValues;
        m_data[i] = new DisplayableRingDataset(m_countValues);
        m_data[i]->Push(0);
        m_data[i]->SetXStep(m_timeStep);
        m_data[i]->SetGraphPen(m_curvePen[i], m_curveColour[i]);
    }
}

void BaseDynamicChart::Clean()
{
    for (int i = 0; i < m_countCurves; i ++)
    {
        m_data[i]->DeleteData();
        m_data[i]->Push(0);
    }
    
    m_leftAxis->SetMaxValue(m_initialMaxYBound);
    
    m_minXBound = DEFAULT_MIN_X_AXIS_BOUND;
    m_maxXBound = DEFAULT_MAX_X_AXIS_BOUND;
    m_bottomAxis->SetBounds(m_minXBound, m_maxXBound);
    
    Refresh();
}

void BaseDynamicChart::Draw()
{
    wxPaintDC pdc(this);
    wxGraphicsContext *gc = wxGraphicsContext::Create(pdc);
    
    wxRect rect = GetClientRect();
    DrawTitle(*gc, rect);
    
    rect = CalcPlotRect(*gc, rect);
    
    wxRect rectData = rect;
    m_bottomAxis->CalcDataArea(*gc, rectData, rectData);
    m_leftAxis->CalcDataArea(*gc, rectData, rectData);

    if (m_autoLabelCount)
    {
        AutoLabelCount(*gc, rectData);
    }
    
    DrawDataBackgroun(*gc, rectData);
    
    m_bottomAxis->Draw(*gc, rectData);
    //m_bottomAxis.DrawGridLines(*gc, rectData);
    m_leftAxis->Draw(*gc, rectData);
    m_leftAxis->DrawGridLines(*gc, rectData);
    
    for (int i = 0; i < m_countCurves; i ++)
    {
        m_data[i]->Draw(*gc, rectData, m_bottomAxis, m_leftAxis);
    }

    delete gc;
}
