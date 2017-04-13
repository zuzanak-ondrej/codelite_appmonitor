/**
 * @file
 * @author zuzanak
 * @date 2017
 * @copyright GNU General Public License v2
 */

#ifndef SIGARCLASS_H
#define SIGARCLASS_H

#include "sigar.h"

/**
 * @class sigarclass
 * @brief Class wrapping sigar.
 */
class sigarclass 
{
public:
    sigarclass();
    ~sigarclass();
    
private:
    sigar_t *sigar;
};

#endif // SIGARCLASS_H
