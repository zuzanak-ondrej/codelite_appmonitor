/**
 * @file
 * @author zuzanak
 * @date 2017
 * @copyright GNU General Public License v2
 */

#ifndef DISPLAYABLERINGDATASET_H
#define DISPLAYABLERINGDATASET_H

#include <wx/graphics.h>
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/panel.h>
#include <wx/colour.h>

#include "axis.h"
#include "ringdataset.h"

/**
 * @class DisplayableRingDataset
 * @brief Ring dataset displayable to curves, depending on the two axis.
 * @see Axis
 */
class DisplayableRingDataset : public RingDataset
{
public:
    /**
     * @param capacity - dataset capacity
     */
    DisplayableRingDataset(int capacity);
    ~DisplayableRingDataset();

    /**
     * @brief Sets pen and filling colour to draw graph.
     * @param wxPen pen
     * @param wxColour colour
     */
    void SetGraphPen(wxPen pen, wxColour colour)
    {
        m_graphPen = pen;
        
        m_fillingColour = colour;
        
        if (colour.IsOk())
        { 
            m_fillingColour = wxColour(colour.Red(), colour.Green(), colour.Blue(), 100);
        }       
    }

    /**
     * @brief Sets filling curve.
     * @param bool choice - true = filling
     */
    void SetFilling(bool choice)
    {
        m_filling = choice;
    }
    
    /**
     * @brief Sets lenght step for one value on x axis.
     * @param double step
     */
    void SetXStep(double step)
    {
        m_xStep = step;
    }

    /**
     * @brief Draws dataset as graph.
     * @param wxGraphicsContext &gc - active wxGraphicsContext for rendering
     * @param wxRect rc - area for rendering
     * @param Axis horizAxis - horizontal axis for placement values
     * @param Axis vertAxis - vertical axis for placement values
     * @see Axis
     */
    void Draw(wxGraphicsContext &dc, wxRect rc, Axis *horizAxis, Axis *vertAxis);


private:

    /**
     * @brief Returns rank of first visible value.
     * @param Axis horizAxis - horizontal axis for placement values
     * @param Axis vertAxis - vertical axis for placement values
     * @return unsigned int
     */
    unsigned int GetFirstVisibleIndex(Axis *horizAxis, Axis *vertAxis);

    double m_xStep;

    //
    // looks
    //
    wxPen m_graphPen;
    bool m_filling;
    wxColour m_graphColour;
    wxColour m_fillingColour;
};

#endif // DISPLAYABLERINGDATASET_H
