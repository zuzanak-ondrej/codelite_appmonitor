/**
 * @file
 * @author zuzanak
 * @date 2017
 * @copyright GNU General Public License v2
 */

#include "ringdataset.h"

RingDataset::RingDataset(int capacity)
{
    m_data = new double[capacity];
    
    m_capacity = capacity;
    m_indexOfEndBuffer = capacity - 1;  
    
    m_count = 0;
    m_dataBeginIndex = 0; 
    m_dataEndIndex = 0;
    
    m_bufferIsFull = false;
}

RingDataset::~RingDataset()
{
    delete[] m_data; 
}

void RingDataset::Push(double value)
{
    if (m_bufferIsFull)
    {
        if (m_dataBeginIndex == m_indexOfEndBuffer)
        {
            m_dataBeginIndex = 0;
            m_dataEndIndex = m_indexOfEndBuffer;
            m_data[m_dataEndIndex] = value;
        }
        else
        {
            m_dataBeginIndex ++;
            m_dataEndIndex = m_dataBeginIndex -1;
            m_data[m_dataEndIndex] = value;
        }
    }
    else
    {
        if (m_count > 0)
        {
            m_dataEndIndex ++;
            m_data[m_dataEndIndex] = value;
            m_count ++;
            
            if (m_count == m_capacity)
            {
                m_bufferIsFull = true;
            }
        }
        else
        {
            m_data[0] = value;
            m_count ++;   
        }
    }
}

unsigned int RingDataset::NextIndex(unsigned int *index)
{
    *index = (*index + 1) % m_capacity;
    return *index;
}

unsigned int RingDataset::GetCount()
{
    return m_count;
}

double RingDataset::GetValue(unsigned int rank)
{
    return m_data[(m_dataBeginIndex + rank - 1) % m_capacity];
}

void RingDataset::DeleteData()
{
    m_count = 0;
    m_dataBeginIndex = 0; 
    m_dataEndIndex = 0;
    
    m_bufferIsFull = false;
}

double RingDataset::GetLargestValue()
{
    double max = 0;
    
    unsigned int index = m_dataBeginIndex;
    
    for (unsigned int i = 0; i < m_count; i ++)
    {
        if (max < m_data[index])
        {
            max = m_data[index];
        }
        index = NextIndex(&index);
    }
    return max;
}

void RingDataset::PrintAllToStdout()
{
    unsigned int index = m_dataBeginIndex;
    
    for (unsigned int i = 0; i < m_count; i ++)
    {
        printf("order: %d - value: %f - index: %d\n", i+1, m_data[index], index);
        index = NextIndex(&index);
    }
}
