/**
 * @file
 * @author zuzanak
 * @date 2017
 * @copyright GNU General Public License v2
 */

#ifndef CHARTHELPER_H
#define CHARTHELPER_H

#include <wx/graphics.h>
#include <wx/gdicmn.h>

/**
 * Checks and fixes rectangle after arithmetical calculations
 * on it's coordinates and size.
 * It either coordinate or size is negative it will be set to zero.
 * @param &rc
 */
inline static void CheckFixRect(wxRect &rc)
{
    if (rc.x < 0)
        rc.x = 0;
    if (rc.y < 0)
        rc.y = 0;
    if (rc.width < 0)
        rc.width = 0;
    if (rc.height < 0)
        rc.height = 0;
}

/**
 * Substracts margins from rectangle.
 * @param rc - rectangle
 * @param left - left margin
 * @param top - top margin
 * @param right - right margin
 * @param bottom - bottom margin
 */
inline static void Margins(wxRect &rc, wxCoord left, wxCoord top, wxCoord right, wxCoord bottom)
{
    if ((left + right) > rc.width) 
    {
        rc.x = left;
        rc.width = 0;
    }
    else 
    {
        rc.x += left;
        rc.width -= (left + right);
    }
    
    if ((top + bottom) > rc.height) 
    {
        rc.y = top;
        rc.height = 0;
    }
    else 
    {
        rc.y += top;
        rc.height -= (top + bottom);
    }
    
    CheckFixRect(rc);
}


#endif // CHARTHELPER_H
