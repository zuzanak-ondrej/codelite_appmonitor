/**
 * @file
 * @author zuzanak
 * @date 2017
 * @copyright GNU General Public License v2
 */

#include "sigarclass.h"

sigarclass::sigarclass()
{
    sigar_open(&sigar);
}

sigarclass::~sigarclass()
{
    sigar_close(sigar);
}

