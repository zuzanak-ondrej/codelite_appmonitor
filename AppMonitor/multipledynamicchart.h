/**
 * @file
 * @author zuzanak
 * @date 2017
 * @copyright GNU General Public License v2
 */

#ifndef MULTIPLEDYNAMICCHART_H
#define MULTIPLEDYNAMICCHART_H

#include "basedynamicchart.h"

/**
 * @class MultipleDynamicChart
 * @brief Dynamic chart with more curves.
 */
class MultipleDynamicChart : public BaseDynamicChart
{
public:
    /**
     * @param countCurve - count of curves
     * @param parent
     * @param id
     * @param pos
     * @param size
     * @param style
     */
    MultipleDynamicChart(int countCurve, wxWindow* parent, wxWindowID id,
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxNO_BORDER);
    ~MultipleDynamicChart();

    /**
     * @brief Enters values into datasets and redraws curves.
     * @param value - array of double value
     */
    void AddData(double *value);
    
    /**
     * @brief Sets pens and filling colours for curves
     * @param pen - array of wxColour
     * @param colour - array of wxColour
     */
    virtual void SetCurvePen(wxPen *pen, wxColour *colour)
    {
        for (int i = 0; i < m_countCurves; i ++)
        {
            m_curvePen[i] = pen[i];
            m_curveColour[i] = colour[i];
            m_data[i]->SetGraphPen(m_curvePen[i], m_curveColour[i]);
        }
    }

};

#endif // MULTIPLEDYNAMICCHART_H
