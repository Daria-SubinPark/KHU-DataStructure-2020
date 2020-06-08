#pragma once
#include <iostream>
using namespace std;


template <typename T>
class UnsortedList
{
private:
    T* i_Array;         ///< list array.
    int i_Length;       ///< number of elements in list.
    int i_CurPointer;   ///< iterator pointer.
    int i_MaxSize;      ///< max size.

public:
    /**
	*	default constructor.
	*/
    UnsortedList();

    UnsortedList(int MaxSize);

    /**
	*	deep copy constructor.
	*/
    UnsortedList(UnsortedList<T>& tmp);

    /**
	*	destructor.
	*/
    ~UnsortedList();

    /**
	*	@brief	Make list empty.
	*	@pre	none.
	*	@post	clear list.
	*/
    void MakeEmpty();

    /**
	*	@brief	Get a number of records in current list.
	*	@pre	none.
	*	@post	none.
	*	@return	number of records in current list.
	*/
    int GetLength() const;

    /**
	*	@brief	Check capacity of list is full.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if list capacity reached to the upper bound, otherwise return false.
	*/
    bool IsFull() const;

    /**
	*	@brief	Initialize list iterator.
	*	@pre	list should be initialized.
	*	@post	iterator is reset.
	*/
    void ResetList();

    /**
	*	@brief	move list iterator to the next item in list and get that item.
	*	@pre	list and list iterator should not be initialized.
	*	@post	iterator is moved to next item.
	*	@param	data	get current iterator's item. it does not need to be initialized.
	*	@return	index of current iterator's item if is not end of list, oterwise return -1.
	*/
    int GetNextItem(T& data);

    /**
	*	@brief	add a new data into list.
	*	@pre	list should be initialized.
	*	@post	added the new record into the list.
	*	@param	data	new data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
    int Add(const T& inData);

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
    int Replace(const T& data);

    void operator= (const UnsortedList& _item);

    friend ostream& operator<<(ostream& os, const UnsortedList& _item)
    {
        if(_item.GetLength() == 1)
            os << _item.i_Array[0] << endl;
        else
        {
            for(int i = 0; i < _item.GetLength(); i++)
            {
                os << "[ " << i+1 << "] layer" << endl;
                os << _item.i_Array[i] << endl;
            }
        }

        return os;
    }
};

template<typename T>
UnsortedList<T>::UnsortedList()
{
    i_MaxSize = 5;
    i_Length = 0;
    ResetList();
    i_Array = new T[i_MaxSize];
}

template<typename T>
UnsortedList<T>::UnsortedList(int MaxSize)
{
    i_MaxSize = MaxSize;
    i_Length = 0;
    ResetList();
    i_Array = new T[i_MaxSize];
}

template<typename T>
UnsortedList<T>::UnsortedList(UnsortedList<T> &tmp)
{
    i_MaxSize = tmp.i_MaxSize;
    i_Length = tmp.i_Length;
    ResetList();
    i_Array = new T[tmp.i_MaxSize];
}


template<typename T>
UnsortedList<T>::~UnsortedList() { delete[] i_Array; }

template<typename T>
void UnsortedList<T>::MakeEmpty() { i_Length = 0; }

template<typename T>
int UnsortedList<T>::GetLength() const{ return i_Length; }

template<typename T>
bool UnsortedList<T>::IsFull() const{ return i_Length > i_MaxSize - 1;}

template<typename T>
void UnsortedList<T>::ResetList() { i_CurPointer = -1; }

template<typename T>
int UnsortedList<T>::GetNextItem(T &data)
{
    i_CurPointer++;
    if(i_CurPointer == i_Length)
        return -1;
    data = i_Array[i_CurPointer];

    return i_CurPointer;
}

template<typename T>
int UnsortedList<T>::Add(const T &inData)
{
    if (!IsFull())
    {
        i_Array[i_Length]= inData;
        i_Length++;
    }
    else
        return 0;

    return 1;
}

template<typename T>
int UnsortedList<T>::Get(T &data)
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
int UnsortedList<T>::Delete(T data)
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
int UnsortedList<T>::Replace(const T &data)
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
void UnsortedList<T>::operator=(const UnsortedList &_item)
{
    delete[] i_Array;
    i_Length = _item.i_Length;
    i_CurPointer = _item.i_CurPointer;
    i_MaxSize = _item.i_MaxSize;
    i_Array = new T[i_MaxSize];
    for(int i = 0; i < _item.i_Length; i++)
        i_Array[i] = _item.i_Array[i];
}
