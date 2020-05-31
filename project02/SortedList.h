//
// Created by 박수빈 on 2020/04/30.
//

#pragma once


template <typename T>
class SortedList
{
private:
    T* i_Array;         ///< list array.
    int i_Length;       ///< number of elements in list.
    int i_CurPointer;   ///< iterator pointer.
    int i_MaxSize;      ///< max size.

public:
    /**
     *  default constructor.
     */
    SortedList();

    /**
     *  deep copy constructor.
     */
    SortedList(const SortedList<T>& tmp);

    /**
     *  destructor.
     */
    ~SortedList();


    /**
     *  @brief  Make list empty.
     *  @pre    none.
     *  @post   clear list.
     */
    void MakeEmpty();

    /**
     *  @brief  Get a number of records in current list.
     *  @pre    none.
     *  @post   none.
     *  @return number of records in current list.
    */
    int GetLength();

    /**
     *  @brief  Check capacity of list is full.
     *  @pre    none.
     *  @post   none.
     *  @return return true if list capacity reached to the upper bound, otherwise return false.
     */
    bool IsFull();


    /**
     *  @brief  Initialize list iterator.
     *  @pre    list should be initialized.
     *  @post   iterator is reset.
     */
    void ResetList();

    /**
     *  @brief  move list iterator to the next item in list and get that item.
     *  @pre    list and list iterator should not be initialized.
     *  @post   iterator is moved to next item.
     *  @param  data    get current iterator's item. it does not need to be initialized.
     *  @return index of current iterator's item if is not end of list, otherwise return -1.
     */
    int GetNextItem(T& data);

    /**
     *  @brief  add a new data into list.
     *  @pre    list should be initialized.
     *  @post   added the new record into the list.
     *  @param  data    new data.
     *  @return return 1 if this function works well, otherwise 0.
     */
    int Add(T& inData);

    /**
     *  @brief  Get data on list.
     *  @pre    list and list iterator should not be initialized.
     *  @post   get data
     *  @param  data    input data( wanted to get )
     *  @return return 1 if this funcion works well, otherwise 0.
     */
    int Get(T& data);

    /**
     *  @brief  if data exist in list, delete them item.
     *  @pre    list and list iterator should not be initialized.
     *  @post   iterator is moved to next item.
     *  @param  data    new data
     *  @return if data exist in list return data's pointer, otherwise return -1.
     */
    int Delete(T data);

    /**
     *  @brief  if new data exist in list, replace data on list to new data
     *  @pre    list and list iterator should not be initialized.
     *  @post   iterator is moved to next item.
     *  @param  data    new data
     *  @return if data exist in list return 1, otherwise return -1.
     */
    int Replace(T& data);


    /**
     *  @brief  Same Retrieve_S function, but add Binary Search
     *  @pre    list and list iterator should not ne initialized.
     *  @post   data    get item id of ItemType.
     *  @return if found same item type return 1, otherwise return 0
     */
    int GetByBinarySearch(T& data);

};

template<typename T>
SortedList<T>::SortedList()
{
    i_MaxSize = ADDSIZE;
    i_Length = 0;
    ResetList();
    i_Array = new T[i_MaxSize];
}


template<typename T>
SortedList<T>::SortedList(const SortedList<T>& tmp)
{
    i_MaxSize = tmp.i_MaxSize;
    i_Length = tmp.i_Length;
    ResetList();
    i_Array = new T[tmp.i_MaxSize];
}

template<typename T>
SortedList<T>::~SortedList() { delete[] i_Array; }

template<typename T>
void SortedList<T>::MakeEmpty() { i_Length = 0; }

template<typename T>
int SortedList<T>::GetLength() { return i_Length; }

template<typename T>
bool SortedList<T>::IsFull() { return i_Length > i_MaxSize - 1; }

template<typename T>
void SortedList<T>::ResetList() { i_CurPointer = -1; }

template<typename T>
int SortedList<T>::GetNextItem(T &data)
{
    i_CurPointer++;
    if(i_CurPointer == i_Length)
        return -1;
    data = i_Array[i_CurPointer];

    return i_CurPointer;
}

template<typename T>
int SortedList<T>::Add(T &inData)
{
    if(IsFull())
    {
        T* tmpList = new T[i_Length];
        for(int i = 0; i < i_Length; i++)
            tmpList[i] = i_Array[i];
        delete[] i_Array;
        i_MaxSize += ADDSIZE;
        i_Array = new T[i_MaxSize];
        for(int i = 0; i < i_Length; i++)
            i_Array[i] = tmpList[i];
        delete[] tmpList;
    }

    if(i_Length == 0)
    {
        i_Array[i_Length] = inData;
        i_Length++;
        return 1;
    }
    else
    {
        for(int i = 0; i < i_Length; i++)
        {
            if(i_Array[i] < inData)
            {
                if(i == i_Length - 1)
                {
                    i_Array[i_Length] = inData;
                    i_Length++;
                    return 1;
                }
            }
            else if(i_Array[i] > inData)
            {
                for(int j = i_Length; j > i; j--)
                    i_Array[j] = i_Array[j - 1];
                i_Array[i] = inData;
                i_Length++;
                return 1;
            }
            else
                return -1;
        }
    }
    return 0;
}

template<typename T>
int SortedList<T>::Get(T &data)
{
    for(int i = 0; i < i_Length; i++)
    {
        if(i_Array[i] == data)
        {
            data = i_Array[i];
            return 1;
        }
    }
    return 0;
}

template<typename T>
int SortedList<T>::Delete(T data)
{
    for(int i = 0; i < i_Length; i++)
    {
        if(i_Array[i] == data)
        {
            for(int j = i; j < i_Length - 1; j++)
                i_Array[j] = i_Array[j + 1];
            i_Length--;
            return 1;
        }
    }
    return 0;
}

template<typename T>
int SortedList<T>::Replace(T &data)
{
    for(int i = 0; i < i_Length; i++)
    {
        if(i_Array[i] == data)
        {
            i_Array[i] = data;
            return 1;
        }
    }
    return 0;
}

template<typename T>
int SortedList<T>::GetByBinarySearch(T &data)
{
    int first = 0;
    int last = i_Length - 1;
    bool found = false;
    while(first <= last && !found)
    {
        int mid = (first + last) / 2;
        if(data < i_Array[mid])
            last = mid - 1;
        else if (data > i_Array[mid])
            first = mid + 1;
        else
        {
            data = i_Array[mid];
            found = true;
            return 1;
        }
    }
    return 0;
}

