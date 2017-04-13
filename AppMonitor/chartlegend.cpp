/**
 * @file
 * @author zuzanak
 * @date 2017
 * @copyright GNU General Public License v2
 */

#include "chartlegend.h"

ChartLegend::ChartLegend(wxWindow* parent, wxWindowID id, wxString text, wxColour colour, 
                         const wxPoint& pos, const wxSize& size, long style) 
            : wxPanel(parent, id, pos, size, style)
{
    wxBoxSizer* bHorizontalSizer;
    bHorizontalSizer = new wxBoxSizer( wxHORIZONTAL );
    
    ColourPanel *m_colourPanel = new ColourPanel( this, wxID_ANY, colour);
    bHorizontalSizer->Add( m_colourPanel, 0, wxALL, 0 );
    
    wxStaticText *m_staticText = new wxStaticText( this, wxID_ANY, text, wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText->Wrap( -1 );
    m_staticText->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
    bHorizontalSizer->Add( m_staticText, 0, wxALIGN_CENTER|wxLEFT, 5 );
    
    this->SetSizer( bHorizontalSizer );
    this->Layout();
}

ChartLegend::~ChartLegend()
{
}

ColourPanel::ColourPanel(wxWindow* parent, wxWindowID id, wxColour colour, 
                         const wxPoint& pos, const wxSize& size, long style) 
            : wxPanel(parent, id, pos, size, style)
{
    m_colour = colour;
    m_pen = wxPen(m_colour);
    
    m_fillingColour = wxColour(colour.Red(), colour.Green(), colour.Blue(), 100);
    m_brush = wxBrush(m_fillingColour);
    
    Connect(this->GetId(), wxEVT_PAINT, wxPaintEventHandler(ColourPanel::OnPaint));
    Connect(this->GetId(), wxEVT_SIZE, wxSizeEventHandler(ColourPanel::OnResize));
}

ColourPanel::~ColourPanel()
{
    Disconnect(this->GetId(), wxEVT_PAINT, wxPaintEventHandler(ColourPanel::OnPaint));
    Disconnect(this->GetId(), wxEVT_SIZE, wxSizeEventHandler(ColourPanel::OnResize));
}

void ColourPanel::OnPaint(wxPaintEvent& event)
{
    Draw();
}

void ColourPanel::OnResize(wxSizeEvent& event)
{
    Refresh();
    event.Skip();
}

void ColourPanel::Draw()
{
    wxPaintDC pdc(this);
    wxGraphicsContext *gc = wxGraphicsContext::Create(pdc);
    wxRect rect = GetClientRect();
        
    wxGraphicsPath path = gc->CreatePath();

    path.MoveToPoint(rect.x, rect.y);
    path.AddLineToPoint(rect.x + rect.GetWidth()-1, rect.y);
    path.AddLineToPoint(rect.x + rect.GetWidth()-1, rect.y + rect.GetHeight()-1);
    path.AddLineToPoint(rect.x, rect.y + rect.GetHeight()-1);
    path.AddLineToPoint(rect.x, rect.y);
    
    gc->SetPen(m_pen);
    gc->SetBrush(m_brush);
    gc->DrawPath(path);
    
    delete gc;
}

