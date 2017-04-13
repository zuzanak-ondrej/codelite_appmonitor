/**
 * @file
 * @author zuzanak
 * @date 2017
 * @copyright GNU General Public License v2
 */

#include "simpledynamicchart.h"

SimpleDynamicChart::SimpleDynamicChart(wxWindow* parent, wxWindowID id, 
                                       const wxPoint& pos, const wxSize& size, long style)
                  : BaseDynamicChart(parent, id, pos, size, style)
{
    m_countCurves = 1;
    
    m_curvePen[m_countCurves] = wxPen(wxColour(59, 144, 232));
    m_curveColour[m_countCurves] = wxColour(66, 128, 192, 0);

    CreateDataset(m_maxXBound / m_timeStep + 1);
}

SimpleDynamicChart::~SimpleDynamicChart()
{
}

void SimpleDynamicChart::AddData(double value)
{
    if (!m_autoYRange)
    {
        if (m_leftAxis->GetMaxValue() < value)
        {
            value = m_leftAxis->GetMaxValue();
        }
    }
    m_data[0]->Push(value);
    
    if (m_autoYRange)
    {
        AutoRange();
    }
 
    ShiftTimeline();
    Refresh();
}
