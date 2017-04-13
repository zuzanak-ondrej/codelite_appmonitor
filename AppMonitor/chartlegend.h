/**
 * @file
 * @author zuzanak
 * @date 2017
 * @copyright GNU General Public License v2
 */

#ifndef CHARTLEGEND_H
#define CHARTLEGEND_H

#include <wx/graphics.h>
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/stattext.h>

#include "identifiers.h"

/**
 * @class ChartLegend
 * @brief Displayed label with a coloured icon.
 */
class ChartLegend : public wxPanel
{
public:
    /**
     * @param parent
     * @param id
     * @param text
     * @param colour
     * @param pos
     * @param size
     * @param style
     */
    ChartLegend(wxWindow* parent, wxWindowID id, wxString text, wxColour colour,
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxNO_BORDER); 
    ~ChartLegend();

};

/**
 * @class ColourPanel
 * @brief Displayed coloured icon.
 */
class ColourPanel : public wxPanel
{
public:
    /**
     * @param parent
     * @param colour
     * @param pos
     * @param size
     * @param style
     */
    ColourPanel(wxWindow* parent, wxWindowID id, wxColour colour,
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(15, 15),
        long style = wxNO_BORDER); 
    ~ColourPanel();

protected:

    void OnPaint(wxPaintEvent& event);
    void OnResize(wxSizeEvent& event);
    void Draw();

    wxPen m_pen;
    wxBrush m_brush;
    wxColour m_colour;
    wxColour m_fillingColour;
};

#endif // CHARTLEGEND_H
