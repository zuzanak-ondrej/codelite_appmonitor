/**
 * @file
 * @author zuzanak
 * @date 2017
 * @copyright GNU General Public License v2
 */

#include "sigarmanager.h"

SigarManager* SigarManager::ms_instance = 0;

SigarManager::SigarManager()
{
    m_sigarIsStart = false;
    StartSigar();
}

SigarManager::~SigarManager()
{
    CloseSigar();
}

SigarManager* SigarManager::Instance()
{
    if(ms_instance == 0)
    {
        ms_instance = new SigarManager();
    }
    return ms_instance;
}

void SigarManager::Release()
{
    if(ms_instance)
    {
        delete ms_instance;
    }
    ms_instance = 0;
}

void SigarManager::CloseSigar()
{
    if (m_sigarIsStart == true)
    {
        sigar_close(m_sigar);
        m_sigarIsStart = false;
    }
}

void SigarManager::StartSigar()
{
    if (m_sigarIsStart == false)
    {
        sigar_open(&m_sigar);
        m_sigarIsStart = true;
    }
}

structProcessState SigarManager::GetThreadInfo(int PIDProcess)
{
    structProcessState result = structProcessState();
    
    int status;
    
    sigar_proc_state_t pstate;
    status = sigar_proc_state_get(m_sigar, PIDProcess, &pstate);
    if (status != SIGAR_OK) 
    {
        return result;
    }
        
    result.Processor = pstate.processor;
    result.PID = PIDProcess;
    
    result.State = pstate.state;
    
    sigar_cpu_info_list_t cpulist;
    sigar_cpu_info_list_get(m_sigar, &cpulist);

    sigar_proc_cpu_t proc;
    sigar_proc_cpu_get(m_sigar, PIDProcess, &proc);
    if (status == SIGAR_OK) 
    {
        result.StartTime = proc.start_time;
        result.Percent = proc.percent * 100 / cpulist.number;
    }
    
    sigar_proc_mem_t procmem;
    sigar_proc_mem_get(m_sigar, PIDProcess, &procmem);
    
    result.VirualMemory = procmem.size/MiB;
    result.SharedMemory = procmem.share/MiB;
    result.ResidentMemory = procmem.resident/MiB;
    
    
    sigar_proc_disk_io_t procDisk;
    sigar_proc_disk_io_get(m_sigar, PIDProcess, &procDisk);

    result.DiskRead = procDisk.bytes_read/MiB;
    result.DiskWritten = procDisk.bytes_written/MiB;
    result.DiskTotal = procDisk.bytes_total/MiB;

    return result;
}