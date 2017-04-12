/**
 * @file
 * @author zuzanak
 * @date 2017
 * @copyright GNU General Public License v2
 */

#include "displayableringdataset.h"

DisplayableRingDataset::DisplayableRingDataset(int capacity) : RingDataset(capacity)
{
    m_graphColour = wxColour(59, 144, 232);
    m_graphPen = wxPen(m_graphColour);
    
    m_fillingColour = wxColour(66, 128, 192, 150);
    
    m_filling = true;
    m_xStep = 1;
}

DisplayableRingDataset::~DisplayableRingDataset()
{
}

unsigned int DisplayableRingDataset::GetFirstVisibleIndex(Axis *horizAxis, Axis *vertAxis)
{
    for (unsigned int n = 1; n <= m_count; n++) 
    {
        double x = horizAxis->GetMinValue();
        double y = GetValue(n);
    
        if (horizAxis->IsVisible(x) && vertAxis->IsVisible(y)) 
        {
            return n;
        }
    }
    return 0; // nothing visible
}

void DisplayableRingDataset::Draw(wxGraphicsContext &gc, wxRect rc, Axis *horizAxis, Axis *vertAxis)
{
    unsigned int firstDataIndex;
    
    if (m_count < 2 || (firstDataIndex = GetFirstVisibleIndex(horizAxis, vertAxis)) == 0)
    {
        return;
    }
    
    gc.SetPen(m_graphPen);
    
    double x, y;
    wxCoord xg, yg;

    double startAtX = horizAxis->GetMinValue();

    x = startAtX;
    y = GetValue(firstDataIndex);

    xg = horizAxis->ToGraphics(gc, rc.x, rc.width, x);
    yg = vertAxis->ToGraphics(gc, rc.y, rc.height, y);

    wxGraphicsPath path = gc.CreatePath();

    path.MoveToPoint(xg, yg);

    for (unsigned int n = firstDataIndex + 1; n <= m_count; n ++) 
    {
        x += m_xStep;
        y = GetValue(n);
        
        if (!horizAxis->IsVisible(x) || !vertAxis->IsVisible(y)) 
        {
            break;
        }
        
        xg = horizAxis->ToGraphics(gc, rc.x, rc.width, x);
        yg = vertAxis->ToGraphics(gc, rc.y, rc.height, y);

        path.AddLineToPoint(xg, yg);
    }
    
    gc.StrokePath(path);
    
    if (m_filling)
    {
        yg = vertAxis->ToGraphics(gc, rc.y, rc.height, vertAxis->GetMinValue());
        path.AddLineToPoint(xg, yg);
        
        xg = horizAxis->ToGraphics(gc, rc.x, rc.width, startAtX);
        path.AddLineToPoint(xg, yg);
        
        wxBrush brush(m_fillingColour);
        gc.SetBrush(brush);
        gc.FillPath(path);
    }
}
