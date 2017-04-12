/**
 * @file
 * @author zuzanak
 * @date 2017
 * @copyright GNU General Public License v2
 */

#include "axis.h"

Axis::Axis(AXIS_LOCATION location)
{
    m_location = location;
    
    m_verticalLabelText = false;
    m_verticalTitleText = false;
    
    m_minValue = 0;
	m_maxValue = 50;
    
    m_labelCount = 11;
    
    m_labelInterval = (m_maxValue - m_minValue) / (double) (m_labelCount - 1);
    
    m_tickFormat = wxT("%.2f");
    
    m_labelGap = 2;
    m_labelLineSize = 5;
    
    m_labelTextColour = *wxBLACK;
    m_labelTextFont = *wxNORMAL_FONT;
    m_labelPen = *wxBLACK_PEN;

    m_gridLinesPen = *wxGREY_PEN;

    m_marginMin = 0;
    m_marginMax = 0;
    
    m_titleFont = *wxNORMAL_FONT;
    m_titleFont.SetWeight(wxFONTWEIGHT_BOLD);
    m_titleColour = *wxBLACK;
    m_titleLocation = wxCENTER;

}

Axis::~Axis()
{
}

void Axis::DrawLabel(wxGraphicsContext &gc, wxRect rc, const wxString &label, double value)
{
    wxDouble labelExtentX;
    wxDouble labelExtentY;
    gc.GetTextExtent(label, &labelExtentX, &labelExtentY, NULL, NULL);
    
    if (m_verticalLabelText)
    {    
        wxDouble helper = labelExtentX;
        labelExtentX = labelExtentY;
        labelExtentY = helper;
    }
    
    wxSize labelExtent(labelExtentX, labelExtentY);

    wxCoord x, y;
    wxCoord textX, textY;
    wxCoord lineX1, lineY1;
    wxCoord lineX2, lineY2;
    
    if (IsVertical()) 
    {
        y = ToGraphics(gc, rc.y, rc.height, value);
    
        lineY1 = lineY2 = y;

        lineX1 = rc.x - m_labelLineSize;
        lineX2 = rc.x;

        textX = lineX1 - labelExtent.x - m_labelGap;

        if (m_verticalLabelText) 
        {
            textY = y + labelExtent.y / 2;
        }
        else 
        {
            textY = y - labelExtent.y / 2;
        }
    }
    else 
    {
        x = ToGraphics(gc, rc.x, rc.width, value);
    
        lineX1 = lineX2 = x;
    
        lineY1 = rc.y + rc.height;
        lineY2 = rc.y + rc.height + m_labelLineSize;

        if (m_verticalLabelText) 
        {
            textY = lineY2 + m_labelGap + labelExtent.y;
        }
        else 
        {
            textY = lineY2 + m_labelGap;
        }

        textX = x - labelExtent.x / 2;
    }
    
    gc.StrokeLine(lineX1, lineY1, lineX2, lineY2);
    
    if (m_verticalLabelText) 
    {
        gc.DrawText(label, textX, textY, 1.57);
    }
    else 
    {
        gc.DrawText(label, textX, textY);
    }
}

void Axis::DrawLabels(wxGraphicsContext &gc, wxRect rc)
{
    gc.SetFont(m_labelTextFont, m_labelTextColour);
    gc.SetPen(m_labelPen);
    
    wxString label;
    for (int step = 0; !IsEnd(step) ; step++) 
    {
        double value = GetValue(step);
        if (!IsVisible(value)) 
        {
            continue;
        }
    
        label = wxEmptyString;
        GetLabel(step, label);
    
        DrawLabel(gc, rc, label, value);
    }
}

void Axis::GetLabel(size_t step, wxString &label)
{
    double value = GetValue(step);
    
    if (value == -0) 
    {
        value = 0;
    }
    
    label = wxString::Format(m_tickFormat, value);
}

bool Axis::IsVisible(double value)
{
    return (value >= m_minValue && value <= m_maxValue);
}

double Axis::GetValue(size_t step)
{
    return m_minValue + step * m_labelInterval;
}

bool Axis::IsEnd(size_t step)
{
    return step >= m_labelCount;
}

wxCoord Axis::ToGraphics(wxGraphicsContext& WXUNUSED(gc), int minCoord, int gRange, double value)
{
    minCoord += m_marginMin;
    gRange -= (m_marginMin + m_marginMax);
    if (gRange < 0) 
    {
        gRange = 0;
    }
    
    double k;
    double valueRange = m_maxValue - m_minValue;
    
    if (gRange <= 0) 
    {
        return minCoord;
    }
    
    if (IsVertical()) 
    {
        k = (m_maxValue - value) / valueRange;
    }
    else 
    {
        k = (value - m_minValue) / valueRange;
    }
    
    return (wxCoord) (k * gRange + minCoord);
}

void Axis::DrawBorderLine(wxGraphicsContext &gc, wxRect rc)
{
    wxCoord x1, y1;
    wxCoord x2, y2;
    
    switch (GetLocation()) 
    {
        case AXIS_LEFT:
            x1 = x2 = rc.x;
            y1 = rc.y;
            y2 = rc.y + rc.height;
            break;
        case AXIS_BOTTOM:
            x1 = rc.x;
            x2 = rc.x + rc.width;
            y1 = y2 = rc.y + rc.height;
            break;
        default:
            return;
    }
    
    gc.StrokeLine(x1, y1, x2, y2);
}

void Axis::DrawGridLines(wxGraphicsContext &gc, wxRect rc)
{
    gc.SetPen(m_gridLinesPen);
    
    for (int nStep = 0; !IsEnd(nStep); nStep++) 
    {
        double value = GetValue(nStep);
        if (!IsVisible(value)) 
        {
            continue;
        }
    
        if (IsVertical()) 
        {
            wxCoord y = ToGraphics(gc, rc.y, rc.height, value);
    
            if (y == rc.y || y == (rc.y + rc.height)) {
                continue;
            }
    
            gc.StrokeLine(rc.x, y, rc.x + rc.width, y);
        }
        else 
        {
            wxCoord x = ToGraphics(gc, rc.x, rc.width, value);
    
            if (x == rc.x || x == (rc.x + rc.width)) 
            {
                continue;
            }
    
            gc.StrokeLine(x, rc.y, x, rc.y + rc.height);
        }
    }
}

void Axis::DrawTittle(wxGraphicsContext &gc, wxRect rc)
{
    if (m_title.Length() != 0) 
    {
        wxSize maxLabelExtent = GetLongestLabelExtent(gc);
        wxDouble titleExtentX;
        wxDouble titleExtentY;
        
        gc.SetFont(m_titleFont, m_titleColour);
        gc.GetTextExtent(m_title, &titleExtentX, &titleExtentY, NULL, NULL);
        
        if (IsVertical()) 
        {
            if (m_verticalTitleText)
            {    
                wxDouble helper = titleExtentX;
                titleExtentX = titleExtentY;
                titleExtentY = helper;
            }
            
            wxCoord y;
            switch (m_titleLocation) 
            {
                case wxTOP:
                    y = rc.y + titleExtentY;
                    break;
                case wxCENTER:
                    y = (rc.y + rc.height) / 2 + titleExtentY / 2;
                    break;
                case wxBOTTOM:
                    y = rc.y + rc.height;
                    break;
                default:
                    y = (rc.y + rc.height) / 2 + titleExtentY / 2;
            }
            
            if (m_verticalTitleText)
            {
                gc.DrawText(m_title, rc.x - titleExtentX - maxLabelExtent.x - m_labelLineSize - m_labelGap - 3, y, 1.57);
            }
            else
            {
                gc.DrawText(m_title, rc.x - titleExtentX - maxLabelExtent.x - m_labelLineSize - m_labelGap - 3, y);   
            }
        }
        else
        {   
            wxCoord x;
            switch (m_titleLocation) 
            {
                case wxLEFT:
                    x = rc.x;
                    break;
                case wxCENTER:
                    x = (rc.x + rc.width) / 2 - titleExtentX / 2;
                    break;
                case wxRIGHT:
                    x = rc.x + rc.width - titleExtentX;
                    break;
                default:
                    x = (rc.x + rc.width) / 2 - titleExtentX / 2;
            }
    
            gc.DrawText(m_title, x, rc.y + rc.height + maxLabelExtent.y + m_labelLineSize + m_labelGap);
        }
    }
}

void Axis::Draw(wxGraphicsContext &gc, wxRect rc)
{
    DrawTittle(gc, rc);
    DrawBorderLine(gc, rc);
    DrawLabels(gc, rc);
}


wxCoord Axis::GetExtent(wxGraphicsContext &gc)
{
    wxSize maxLabelExtent = GetLongestLabelExtent(gc);
    wxCoord extent = m_labelLineSize + m_labelGap;
    
    wxDouble titleExtentX = 0;
    wxDouble titleExtentY = 0;
    
    if (m_title.Length() != 0) 
    {
        gc.SetFont(m_titleFont, m_titleColour);
        gc.GetTextExtent(m_title, &titleExtentX, &titleExtentY, NULL, NULL);
        
        if (m_verticalTitleText)
        {    
            wxDouble helper = titleExtentX;
            titleExtentX = titleExtentY;
            titleExtentY = helper;
        }
    }
    
    if (IsVertical()) 
    {
        extent += maxLabelExtent.x;
        extent += titleExtentX;
        extent += m_labelPen.GetWidth();
    }
    else 
    {
        extent += maxLabelExtent.y;
        extent += titleExtentY;
        extent += m_labelPen.GetWidth();
    }
    return extent;
}

wxSize Axis::GetLongestLabelExtent(wxGraphicsContext &gc)
{
    wxSize ret;
    
    gc.SetFont(m_labelTextFont, m_labelTextColour);

    wxDouble minLabelExtentX;
    wxDouble minLabelExtentY;
    wxDouble maxLabelExtentX;
    wxDouble maxLabelExtentY;
    gc.GetTextExtent(wxString::Format(m_tickFormat, m_minValue), &minLabelExtentX, &minLabelExtentY, NULL, NULL);
    gc.GetTextExtent(wxString::Format(m_tickFormat, m_maxValue), &maxLabelExtentX, &maxLabelExtentY, NULL, NULL);
    
    if (m_verticalLabelText)
    {    
        wxDouble helper = minLabelExtentX;
        minLabelExtentX = minLabelExtentY;
        minLabelExtentY = helper;
        
        helper = maxLabelExtentX;
        maxLabelExtentX = maxLabelExtentY;
        maxLabelExtentY = helper;
    }
    
    if (minLabelExtentX > maxLabelExtentX) 
    {
        ret.x = minLabelExtentX;
        ret.y = minLabelExtentY;
        return ret;
    }
    else 
    {
        ret.x = maxLabelExtentX;
        ret.y = maxLabelExtentY;
        return ret;
    }
}

void Axis::CalcDataArea(wxGraphicsContext &gc, wxRect rc, wxRect &rcData)
{
    rcData = rc;
    
    wxCoord ext = GetExtent(gc);
    
    switch (GetLocation()) 
    {
        case AXIS_LEFT:
            rcData.x += ext;
            rcData.width -= ext;
            break;
        case AXIS_BOTTOM:
            rcData.height -= ext;
            break;
        default:
            return;
    }

    CheckFixRect(rcData);
}
