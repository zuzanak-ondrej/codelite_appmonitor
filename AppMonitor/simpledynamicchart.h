/**
 * @file
 * @author zuzanak
 * @date 2017
 * @copyright GNU General Public License v2
 */

#ifndef SIMPLEDYNAMICCHART_H
#define SIMPLEDYNAMICCHART_H

#include "basedynamicchart.h"

/**
 * @class SimpleDynamicChart
 * @brief Dynamic chart with one curve.
 */
class SimpleDynamicChart : public BaseDynamicChart
{
public:
    /**
     * @param parent
     * @param id
     * @param pos
     * @param size
     * @param style
     */
    SimpleDynamicChart(wxWindow* parent, wxWindowID id,
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxNO_BORDER);
    ~SimpleDynamicChart();
    
    /**
     * @brief Enters value into dataset and redraws graph.
     * @param value - double value
     */
    void AddData(double value);
    
    /**
     * @brief Sets pen and filling colour for curve
     * @param pen
     * @param colour - filling colour
     */
    virtual void SetCurvePen(wxPen pen, wxColour colour)
    {
        m_curvePen[0] = pen;
        m_curveColour[0] = colour;
        m_data[0]->SetGraphPen(m_curvePen[0], m_curveColour[0]);
    }

};

#endif // SIMPLEDYNAMICCHART_H
