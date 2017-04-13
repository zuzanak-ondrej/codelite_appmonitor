/**
 * @file
 * @author zuzanak
 * @date 2017
 * @copyright GNU General Public License v2
 */

#ifndef DATASET_H
#define DATASET_H

#include <cstdio>

/**
 * @class RingDataset
 * @brief simple circular buffer for double values
 */
class RingDataset
{
public:
    /**
     * @param capacity - dataset capacity
     */
    RingDataset(int capacity);
    ~RingDataset();

    /**
     * @brief Enters the value into dataset.
     * @param double value
     */
    void Push(double value);

    /**
     * @brief Returns number of values in dataset.
     * @return unsigned int
     */
    unsigned int GetCount();
    
    /**
     * @brief Returns single value on rank.
     * @param unsigned int rank
     * @return double
     */
    double GetValue(unsigned int rank);

    /**
     * @brief Returns true if buffer is filled.
     * @return bool
     */
    bool IsFull()
    {
        return m_bufferIsFull;
    }

    /**
     * @brief Deletes all data from dataset.
     */
    void DeleteData();

    /**
     * @brief Returns largest value in dataset.
     * @return double
     */
    double GetLargestValue();

    /**
     * @brief Prints all values to stdout.
     */
    void PrintAllToStdout();

protected:

    /**
     * @brief Increases and returns index.
     * @param unsigned int *index
     * @return unsigned int
     */
    unsigned int NextIndex(unsigned int *index);

    double *m_data;
    unsigned int m_count;
    unsigned int m_capacity;
    
    unsigned int m_indexOfEndBuffer;
    unsigned int m_dataBeginIndex; 
    unsigned int m_dataEndIndex;   
    
    bool m_bufferIsFull;
    
};

#endif // DATASET_H
