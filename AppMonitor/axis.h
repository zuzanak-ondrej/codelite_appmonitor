/**
 * @file
 * @author zuzanak
 * @date 2017
 * @copyright GNU General Public License v2
 */

#ifndef AXIS_H
#define AXIS_H

#include <wx/graphics.h>
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/panel.h>

#include "charthelpers.h"

/**
 * @enum AXIS_LOCATION
 * @brief enum for determining position of axis
 */
enum AXIS_LOCATION {
    AXIS_LEFT = 1, /**< position on the left of graph */
    AXIS_BOTTOM    /**< position at the bottom of graph */
};

/**
 * @class Axis
 * @brief An axis for displaying and scaling numerical data.
 */
class Axis
{
public:
    /**
     * @param AXIS_LOCATION location
     */
    Axis(AXIS_LOCATION location);
    ~Axis();
    
    /**
     * @brief Returns axis location.
     */
    AXIS_LOCATION GetLocation()
    {
        return m_location;
    }
    
    /**
     * @brief Checks whether axis is vertical.
     * @return true if axis is vertical
     */
    bool IsVertical()
    {
        return m_location == AXIS_LEFT;
    }
    
    /**
     * @brief Checks whether axis is horizontal.
     * @return true if axis is horizontal
     */
    bool IsHorizontal()
    {
        return m_location == AXIS_BOTTOM;
    }

    /**
     * @brief Sets bounds on axis. Recalculates label Interval based on label count.
     * @param double minValue - minimum displayed value on axis
     * @param double maxValue - maximum displayed value on axis
     * @see SetLabelCount
     */
    void SetBounds(double minValue, double maxValue)
    {
        m_minValue = minValue;
        m_maxValue = maxValue;
        m_labelInterval = (m_maxValue - m_minValue) / (double) (m_labelCount - 1);
    }
    
    /**
     * @brief Gets bounds on axis.
     * @param double &minValue - minimum displayed value on axis
     * @param double &maxValue - maximum displayed value on axis
     */
    void GetBounds(double &minValue, double &maxValue)
    {
        minValue = m_minValue;
        maxValue = m_maxValue;
    }
    
    /**
     * @brief Gets minimum value on axis.
     */
    double GetMinValue()
    {
        return m_minValue;
    }

    /**
     * @brief Gets maximum value on axis.
     */
    double GetMaxValue()
    {
        return m_maxValue;
    }
    
    /**
     * @brief Sets maxim value on axis. Recalculates label Interval based on label count.
     * @param double maxValue - maximum displayed value on axis
     * @see SetLabelCount
     */
    void SetMaxValue(double maxValue)
    {
        m_maxValue = maxValue;
        m_labelInterval = (m_maxValue - m_minValue) / (double) (m_labelCount - 1);
    }
    
    /**
     * @brief Sets count of labels. Calculated value for label interval.
     * @param size_t labelCount - labelCount count of labels
     */
    void SetLabelCount(size_t labelCount)
    {
        m_labelCount = labelCount;
        m_labelInterval = (m_maxValue - m_minValue) / (double) (m_labelCount - 1);
    }
    
    /**
     * @brief Gets count of labels.
     */
    size_t GetLabelCount()
    {
        return m_labelCount;
    }
    
    /**
     * @brief Sets label interval. Recalculates value for label count.
     * @param double labelInterval - label interval
     * @see SetBounds, SetMaxValue
     */
    void SetLabelInterval(double labelInterval)
    {
        m_labelInterval = labelInterval;
        m_labelCount = (m_maxValue - m_minValue) / labelInterval + 1;
    }
    
    /**
     * Sets minimal/maximal margins for axis.
     * Eg bottom for vertical axes, left for horizontal.
     * @param wxCoord marginMin - new minimal margin
     * @param wxCoord marginMax - new maximal margin
     */
    void SetMargins(wxCoord marginMin, wxCoord marginMax)
    {
        m_marginMin = marginMin;
        m_marginMax = marginMax;
    }
    
    /**
     * @brief Sets pen to draw grid.
     * @param wxPen pen
     */
    void SetGridLinesPen(wxPen pen)
    {
        m_gridLinesPen = pen;
    }

    /**
     * @brief Sets axis title.
     * @param wxString &title - new axis title
     */
    void SetTitle(const wxString &title)
    {
        m_title = title;
    }
    
    /**
     * @brief Returns axis title.
     * @return wxString - axis title
     */
    const wxString &GetTitle()
    {
        return m_title;
    }
    
    /**
     * New location for axis title,
     * acceptable values wxLEFT, wxCENTER, wxRIGHT for horizontal axes,
     * wxTOP, wxCENTER, wxBOTTOM for vertical axes.
     * @brief Sets axis title location. 
     * @param int location - wxLEFT, wxCENTER, wxRIGHT, wxTOP, wxCENTER, wxBOTTOM
     */
    void SetTitleLocation(int location)
    {
        m_titleLocation = location;
    }
    
    /**
     * @brief Returns axis title location.
     * @return int - wxLEFT, wxCENTER, wxRIGHT, wxTOP, wxCENTER, wxBOTTOM
     */
    int GetTitleLocation()
    {
        return m_titleLocation;
    }
    
    /**
     * @brief Sets new axis title font.
     * @param wxFont &font - axis title font
     */
    void SetTitleFont(wxFont &font)
    {
        m_titleFont = font;
    }
    
    /**
     * @brief Returns axis title font.
     * @return wxFont - axis title font
     */
    const wxFont &GetTitleFont()
    {
        return m_titleFont;
    }

    /**
     * @brief Sets new axis title colour.
     * @param wxColour &colour - axis title colour
     */
    void SetTitleColour(wxColour &colour)
    {
        m_titleColour = colour;
    }
    
    /**
     * @brief Returns axis title colour.
     * @return wxColour - axis title colour
     */
    wxColour GetTitleColour()
    {
        return m_titleColour;
    }

    /**
     * @brief Sets new pen for label lines.
     * @param wxPen labelPen - pen for label lines
     */
    void SetLabelPen(wxPen labelPen)
    {
        m_labelPen = labelPen;
    }
    
    /**
     * @brief Sets new colour for labels.
     * @param wxColour labelTextColour - color for labels
     */
    void SetLabelTextColour(wxColour labelTextColour)
    {
        m_labelTextColour = labelTextColour;
    }

    /**
     * @brief Returns label colour.
     * @return wxColour - label colour
     */
    wxColour GetLabelTextColour()
    {
        return m_labelTextColour;
    }
    
    /**
     * @brief Sets label gap from axis.
     * @param int labelGap - in pixels
     */
    void SetLabelGap(int labelGap)
    {
        m_labelGap = labelGap;
    }
    
    /**
     * @brief Sets label line length.
     * @param int labelLineSize - label line length in pixels
     */
    void SetLabelLineSize(int labelLineSize)
    {
        m_labelLineSize = labelLineSize;
    }
    
    /**
     * @brief Sets format string for labels. Default is "%.2f".
     * @param wxString &labelFormat - format string
     */
    void SetLabelFormat(const wxString &labelFormat)
    {
        m_tickFormat = labelFormat;
    }
    
    /**
     * @brief Sets new font for labels text.
     * @param wxFont labelTextFont - font for labels text
     */
    void SetLabelTextFont(wxFont labelTextFont)
    {
        m_labelTextFont = labelTextFont;
    }

    /**
     * @brief Returns label font.
     * @return wxFont& - label font
     */
    const wxFont& GetLabelTextFont()
    {
        return m_labelTextFont;
    }

    /**
     * @brief Sets whether to draw labels text vertical.
     * @param bool verticalLabelText - true to draw labels text vertical
     */
    void SetVerticalLabelText(bool verticalLabelText)
    {
        m_verticalLabelText = verticalLabelText;
    }
    
    /**
     * @brief Sets whether to draw title text vertical. Valid only for AXIS_LEFT axis.
     * @param bool verticalTitleText - true to draw title text vertical
     */
    void SetVerticalTitleText(bool verticalTitleText)
    {
        m_verticalTitleText = verticalTitleText;
    }

    /**
     * @brief Draws label on calculated place.
     * @param wxGraphicsContext &gc - active wxGraphicsContext for rendering
     * @param wxRect rc - area for rendering
     * @param wxString label
     * @param double value - value for location in graph
     */
    void DrawLabel(wxGraphicsContext &gc, wxRect rc, const wxString &label, double value);
    
    /**
     * @brief Draws all labels in range.
     * @param wxGraphicsContext &gc - active wxGraphicsContext for rendering
     * @param wxRect rc - area for rendering
     */
    void DrawLabels(wxGraphicsContext &gc, wxRect rc);

    /**
     * @brief Draws line on axis side.
     * @param wxGraphicsContext &gc - active wxGraphicsContext for rendering
     * @param wxRect rc - area for rendering
     */
    void DrawBorderLine(wxGraphicsContext &gc, wxRect rc);

    /**
     * @brief Draws grid lines into graph.
     * @param wxGraphicsContext &gc - active wxGraphicsContext for rendering
     * @param wxRect rc - area for rendering
     */
    void DrawGridLines(wxGraphicsContext &gc, wxRect rc);

    /**
     * @brief Draws tittle.
     * @param xGraphicsContext &gc - active wxGraphicsContext for rendering
     * @param wxRect rc - area for rendering
     */
    void DrawTittle(wxGraphicsContext &gc, wxRect rc);

    /**
     * @brief Draws all components.
     * @param xGraphicsContext &gc - active wxGraphicsContext for rendering
     * @param wxRect rc - area for rendering
     */
    void Draw(wxGraphicsContext &gc, wxRect rc);

    /**
     * @brief Returns value on step.
     * @param size_t step - label number
     * @return double - value on step
     */
    double GetValue(size_t step);
    
    /**
     * @brief Checks whether data value is visible.
     * @param double value - value in data space
     * @return bool - true if data value is visible
     */
    bool IsVisible(double value);
    
    /**
     * @brief Calculates area for curve.
     * @param wxGraphicsContext &gc - active wxGraphicsContext for rendering
     * @param wxRect rc - area for rendering
     * @param wxRect &rcData - area for curve
     */
    void CalcDataArea(wxGraphicsContext &gc, wxRect rc, wxRect &rcData);
    
    /**
     * @brief Returns Longest label on axis.
     * @param wxGraphicsContext &gc - active wxGraphicsContext for rendering
     * @return wxSize - length of label
     */
    wxSize GetLongestLabelExtent(wxGraphicsContext &gc);
    
    /**
     * @brief Calculates position on panel for value.
     * @param xGraphicsContext &gc - active wxGraphicsContext for rendering
     * @param int minCoord
     * @param int gRange
     * @param double value
     * @return wxCoord
     */
    wxCoord ToGraphics(wxGraphicsContext& WXUNUSED(gc), int minCoord, int gRange, double value);  
    
protected:

    /**
     * @brief Returns true if step of labels is final.
     * @param size_t step - label number
     * @return bool
     */
    bool IsEnd(size_t step);

    /**
     * @brief Returns label for current step.
     * @param size_t step - label number
     * @param wxString &label
     */
    void GetLabel(size_t step, wxString &label);

    wxCoord GetExtent(wxGraphicsContext &gc);

    AXIS_LOCATION m_location;

    //
    // labels properties
    //
    wxCoord m_labelGap;
    wxCoord m_labelLineSize;

    wxFont m_labelTextFont;
    wxColour m_labelTextColour;
    wxPen m_labelPen;
    
    wxString m_tickFormat;
    
    double m_minValue;
    double m_maxValue;
    
    double m_labelInterval;
    size_t m_labelCount;
    
    wxCoord m_marginMin;
    wxCoord m_marginMax;
    
    bool m_verticalLabelText;
    
    //
    // grid looks
    //
    wxPen m_gridLinesPen;
    
    //
    // label title properties
    //
    bool m_verticalTitleText;
    
    wxString m_title;
    wxFont m_titleFont;
    wxColour m_titleColour;
    int m_titleLocation;
};

#endif // AXIS_H
