/**
 * @file
 * @author zuzanak
 * @date 2017
 * @copyright GNU General Public License v2
 */

#ifndef SIGARMANAGER_H
#define SIGARMANAGER_H

#include <unistd.h>
#include <wx/wx.h>

#include "sigar.h"
#include "identifiers.h"
#include "sigar_format.h"

/**
 * @class SigarManager
 * @brief This class handles the communication with the library sigar. It is implemented as singleton.
 */
class SigarManager
{
public:
    /**
     * @brief Get instance of self
     * @return Return unique object of SigarManager
     */
    static SigarManager* Instance();
    
    /**
     * @brief Release object from memory
     */
    static void Release();
    
    /**
     * @brief With SIGAR libraries obtains runtime information.
     * @param PIDProcess
     * @return structProcessState structure with data
     */
    structProcessState GetThreadInfo(int PIDProcess);
    
private:
    /**
     * @brief Private constructor
     */
    SigarManager();
    
    /**
     * @brief Private destructor
     */
    virtual ~SigarManager();
    
    /**
     * @brief Opens sigar.
     */
    void StartSigar();
    
    /**
     * @brief Closes sigar.
     */
    void CloseSigar();
    
    bool m_sigarIsStart; 
    sigar_t *m_sigar;
    static SigarManager* ms_instance;
};

#endif // SIGARMANAGER_H
