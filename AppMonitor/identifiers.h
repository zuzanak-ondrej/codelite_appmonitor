/**
 * @file
 * @author zuzanak
 * @date 2017
 * @copyright GNU General Public License v2
 */

#ifndef IDENTIFIERS_H
#define IDENTIFIERS_H

#include <wx/wx.h>

/**
 * @struct structProcessState
 * @brief struct for process state - this state is from sigar
 */
struct structProcessState {  
    int PID;                 /**PID process */
    int Processor;           /**Processor id */
    char State;	             /**Process state */
    double StartTime;        /**Start time in seconds*/
    double Percent;	         /**CPU performance in percent */
    double VirualMemory;     /**Virtual memory quantity in MiB */
    double ResidentMemory;   /**Resident memory quantity in MiB */
    double SharedMemory;     /**Shared memory quantity in MiB */
    double DiskRead;         /**Readed disc data quantity in MiB */
    double DiskWritten;      /**Written disc data quantity in MiB */
    double DiskTotal;        /**Total worked disc data in MiB */
};

/*! \brief constant for calculation Kilobite */
const double KiB = 1024.;
/*! \brief constant for calculation Megabite */
const double MiB = KiB * 1024;
/*! \brief constant for calculation Gigabite */
const double GiB = MiB * 1024;

#endif // IDENTIFIERS_H
