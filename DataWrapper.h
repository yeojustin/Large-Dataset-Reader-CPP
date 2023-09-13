/**
 * @brief Header - Class representing a wrapper for storing data in a map of binary search trees.
 */
#ifndef DATAWRAPPER_H_INCLUDED
#define DATAWRAPPER_H_INCLUDED

#include "Bst.h"
#include <map>

/**
 * @class DataWrapper
 * @brief Class representing a wrapper for storing data in a map of binary search trees.
 * @tparam T The type of data to be stored in the binary search trees.
 */
template <class T>
class DataWrapper
{
private:
    std::map<int, Bst<T>> m_data; /**< The map that stores binary search trees for each key. */

public:
    /**
     * @brief Default constructor for the DataWrapper class.
     */
    DataWrapper();

    /**
     * @brief Destructor for the DataWrapper class.
     */
    ~DataWrapper() {};

    /**
     * @brief Inserts a record into the appropriate binary search tree based on the given map key.
     * @param mapkey The key to identify the binary search tree.
     * @param bstkey The key to insert the record in the binary search tree.
     * @param record The record to be inserted into the binary search tree.
     */
    void InsertRecord(int mapkey, long bstkey, const T& record);

    /**
     * @brief Checks if a record with the given key exists in the binary search tree corresponding to the map key.
     * @param mapkey The key to identify the binary search tree.
     * @param bstkey The key to search for in the binary search tree.
     * @return true if the record exists, false otherwise.
     */
    bool ContainsRecordInBst(int mapkey, long bstkey) const;

    /**
     * @brief Checks if a binary search tree with the given map key exists in the map.
     * @param mapkey The key to identify the binary search tree.
     * @return true if the binary search tree exists, false otherwise.
     */
    bool ContainsRecordInMap(int mapkey) const;

    /**
     * @brief Gets the total number of records stored in all binary search trees.
     * @return The total number of records.
     */
    long GetSize() const;

    /**
     * @brief Gets the binary search tree corresponding to the given map key.
     * @param mapkey The key to identify the binary search tree.
     * @return A reference to the binary search tree corresponding to the map key.
     * @throw std::runtime_error if the binary search tree for the given map key is not found.
     */
    Bst<T>& GetBstFromKey(int mapkey);

    /**
     * @brief Gets the record with the given key from the binary search tree corresponding to the map key.
     * @param mapkey The key to identify the binary search tree.
     * @param bstkey The key to retrieve the record from the binary search tree.
     * @return A reference to the record in the binary search tree.
     * @throw std::runtime_error if the binary search tree for the given map key is not found or the record is not found in the binary search tree.
     */
    T& GetBstRecord(int mapkey, long bstkey);
};


template <class T>
DataWrapper<T>::DataWrapper() {}

template <class T>
void DataWrapper<T>::InsertRecord(int mapkey, long bstkey, const T& record)
{
    if (m_data.find(mapkey) == m_data.end()) //std::map::end is a function that points to a special type past the end of map
    {
        // If true, it means mapkey not exist in map, we insert a new key and add a new instance of Bst
        m_data[mapkey] = Bst<T>();
    }
    // Insert the record into the correct Bst based on the correct map key
    m_data[mapkey].Insert(bstkey, record);
}

template <class T>
bool DataWrapper<T>::ContainsRecordInBst(int mapkey, long bstkey) const
{
    typename map<int, Bst<T>>::const_iterator itr = m_data.find(mapkey);
    if(itr != m_data.end())
    {
        return itr->second.Search(bstkey);
    }
    else
    {
        return false;  // the mapkey does not exist in the map
    }
}

template <class T>
bool DataWrapper<T>::ContainsRecordInMap(int mapkey) const
{
    typename map<int, Bst<T>>::const_iterator itr = m_data.find(mapkey);

    return itr != m_data.end();
}

template <class T>
long DataWrapper<T>::GetSize() const
{
    long totalCount = 0;

    for (const auto& itr : m_data)
    {
        totalCount += itr.second.GetSize();
    }

    return totalCount;
}

template <class T>
Bst<T>& DataWrapper<T>::GetBstFromKey(int mapkey)
{
    if (m_data.find(mapkey) != m_data.end())
    {
        return m_data[mapkey];
    }
    else
    {
        throw runtime_error("Map key not found");
    }
}

template <class T>
T& DataWrapper<T>::GetBstRecord(int mapkey, long bstkey)
{
    return GetBstFromKey(mapkey).GetData(bstkey);
}


#endif // DATAWRAPPER_H_INCLUDED
