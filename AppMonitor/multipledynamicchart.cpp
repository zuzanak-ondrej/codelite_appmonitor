/**
 * @file
 * @author zuzanak
 * @date 2017
 * @copyright GNU General Public License v2
 */

#include "multipledynamicchart.h"

MultipleDynamicChart::MultipleDynamicChart(int countCurve, wxWindow* parent, wxWindowID id, 
                                           const wxPoint& pos, const wxSize& size, long style)
                  : BaseDynamicChart(parent, id, pos, size, style)
{
    if (countCurve > MAX_CURVES)
    {
        countCurve = MAX_CURVES;
    }
    m_countCurves = countCurve;
    
    for (int i = 0; i < m_countCurves; i ++)
    {
        m_curvePen[i] = wxPen(wxColour(59, 144, 232));
        m_curveColour[i] = wxColour(66, 128, 192, 0);
    }
    
    CreateDataset(m_maxXBound / m_timeStep + 1);
}

MultipleDynamicChart::~MultipleDynamicChart()
{
}

void MultipleDynamicChart::AddData(double *value)
{
    for (int i = 0; i < m_countCurves; i ++)
    {
        if (!m_autoYRange)
        {
            if (m_leftAxis->GetMaxValue() < value[i])
            {
                value[i] = m_leftAxis->GetMaxValue();
            }
        }
        m_data[i]->Push(value[i]);
    }
   
    if (m_autoYRange)
    {
        AutoRange();
    }
   
    ShiftTimeline();
    Refresh();
}
