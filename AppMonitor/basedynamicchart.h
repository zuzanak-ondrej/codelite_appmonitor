/**
 * @file
 * @author zuzanak
 * @date 2017
 * @copyright GNU General Public License v2
 */

#ifndef BASEDYNAMICCHART_H
#define BASEDYNAMICCHART_H

#include <wx/graphics.h>
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/panel.h>
#include <memory>
#include <algorithm>
#include <vector>

#include "charthelpers.h"
#include "displayableringdataset.h"
#include "axis.h"


#define DEFAULT_TIME_STEP 1 // second
#define DEFAULT_MAX_X_AXIS_BOUND 60
#define DEFAULT_MIN_X_AXIS_BOUND 0
#define MAX_CURVES 10

/**
 * @class BaseDynamicChart
 * @brief base for dynamic chart, includes Axis, DisplayableRingDataset
 */
class BaseDynamicChart : public wxPanel
{
public:
    /**
     * @param parent
     * @param id
     * @param pos
     * @param size
     * @param style
     */
    BaseDynamicChart(wxWindow* parent, wxWindowID id,
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxNO_BORDER);
    ~BaseDynamicChart();


    /**
     * @brief Sets chart title.
     * @param title - chart title string
     */
    void SetTitle(wxString title)
    {
        m_title = title;
    }
    
    /**
     * @brief Sets font for chart title.
     * @param font - font for chart title
     */
    void SetTitleFont(wxFont font)
    {
        m_titleFont = font;
    }
    
    /**
     * @brief Sets all margins around chart at once.
     * @param margin - size of margin in pixels
     */
    void SetMargin(wxCoord margin)
    {
        m_marginTop = margin;
        m_marginBottom = margin;
        m_marginLeft = margin;
        m_marginRight = margin;
    }
    
    /**
     * @brief Sets margin around graph individually.
     * @param marginTop - top margin
     * @param marginBottom - bottom margin
     * @param marginLeft - left margin
     * @param marginRight - right margin
     */
    void SetMargin(wxCoord marginTop, wxCoord marginBottom, wxCoord marginLeft, wxCoord marginRight)
    {
        m_marginTop = marginTop;
        m_marginBottom = marginBottom;
        m_marginLeft = marginLeft;
        m_marginRight = marginRight;
    }
    
    /**
     * @brief Sets time step and resets dataset.
     * @param timeStep - time step in seconds
     */
    void SetTimeStep(double timeStep)
    {
        m_timeStep = timeStep / 1000.0;
        
        FreeDataset();
        CreateDataset(DEFAULT_MAX_X_AXIS_BOUND / m_timeStep + 1);
    }
    
    /**
     * @brief Sets count values of history and reset dataset.
     * @param countValues
     */
    void SetCountValues(unsigned int countValues)
    {
        FreeDataset();
        CreateDataset(countValues);
        
        m_maxXBound = m_countValues * m_timeStep - m_timeStep;
        
        m_bottomAxis->SetBounds(m_minXBound, m_maxXBound);
    }
    
    /**
     * @brief Sets automatic range for y axis.
     * @param true for automatic
     */
    void SetAutoRange(bool choice)
    {
        m_autoYRange = choice;
    }
    
    /**
     * @brief Sets maximal value on y axis.
     * @param value - maximal value
     */
    void SetmMaxYBound(double value)
    {
        m_initialMaxYBound = value;
        m_leftAxis->SetMaxValue(m_initialMaxYBound);
    }
    
    /**
     * @brief Sets title for y axis.
     * @param title - title string
     */
    void SetLeftAxisTittle(wxString title)
    {
        m_leftAxis->SetTitle(title);
    }
    
    /**
     * @brief Sets title for x axis.
     * @param title - title string
     */
    void SetBottomAxisTittle(wxString title)
    {
        m_bottomAxis->SetTitle(title);
    }
    
    /**
     * @brief Sets format string for y axis labels.
     * @param format - format string, for example "%.2f", "%.0f" 
     */
    void SetLeftAxisLabelFormat(wxString format)
    {
        m_leftAxis->SetLabelFormat(format);
    }
    
    /**
     * @brief Sets format string for x axis labels.
     * @param format - format string, for example "%.2f", "%.0f" 
     */
    void SetBottomAxisLabelFormat(wxString format)
    {
        m_bottomAxis->SetLabelFormat(format);
    }

    /**
     * @brief Cleans graph and sets axes to beginning.
     */
    void Clean();

protected:
    
    /**
     * @brief Calculates area to plot graph.
     */
    wxRect CalcPlotRect(wxGraphicsContext &dc, wxRect rc);

    /**
     * @brief Draws all components.
     */
    void Draw();
    
    /**
     * @brief Draws graph background.
     */
    void DrawDataBackgroun(wxGraphicsContext &gc, wxRect rc);

    /**
     * @brief Draws title above chart.
     */
    void DrawTitle(wxGraphicsContext &gc, wxRect rect);

    /**
     * @brief Calculates new range of values for y axis, if it is small or too big.
     * @see SetAutoRange
     */
    void AutoRange();
    
    /**
     * @brief Shifts timeline x of m_timeStep.
     * @see SetTimeStep
     */
    void ShiftTimeline();
    
    /**
     * @brief Frees dataset from m_data.
     */
    void FreeDataset();
    
    /**
     * @brief Creates dataset for values.
     * @param countValues - max count of values
     */
    void CreateDataset(unsigned int countValues);
    
    /**
     * @brief Calculates number of labels according to length axis.
     */
    void AutoLabelCount(wxGraphicsContext &gc, wxRect rect);
   
    /**
     * @brief Prepares list of ranks number of labels.
     */
    void PrepareNumLabels();
    
    /**
     * @brief Returns largest value of dataset.
     */
    double GetLargestValue();
    
    void OnPaint(wxPaintEvent& event);
    void OnResize(wxSizeEvent& event);
    
    int m_countCurves;
    DisplayableRingDataset *m_data[MAX_CURVES];
    Axis *m_bottomAxis;
    Axis *m_leftAxis;

    //
    // title looks
    //
    wxString m_title;
    wxFont m_titleFont;
    wxColour m_titleColour;
    
    //
    // chart margins
    //
    wxCoord m_marginTop;
    wxCoord m_marginBottom;
    wxCoord m_marginLeft;
    wxCoord m_marginRight;

    //
    //  axes settings
    //
    double m_minXBound;
    double m_maxXBound;
    double m_initialMaxYBound;
    double m_stepExtensionRange;
        
    bool m_autoYRange;
    
    double m_timeStep;
    unsigned int m_countValues;
    
    bool m_autoLabelCount;
    unsigned int m_initialCountXLabel;
    unsigned int m_initialCountYLabel;
    
    //
    // list of ranks number of labels
    //
    std::vector<unsigned int> m_numbersLabels;
    unsigned int m_activeNumLabels;

    //
    // curve looks
    //
    wxPen m_curvePen[MAX_CURVES];
    wxColour m_curveColour[MAX_CURVES];
    
    //
    // data background looks
    //
    wxPen m_dataBorderBackgroundPen;
    wxBrush m_dataFillBackgroundBrush;
};

#endif // BASEDYNAMICCHART_H
