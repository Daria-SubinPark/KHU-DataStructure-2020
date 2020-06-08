#pragma once
#include <iostream>
using namespace std;

#define MAXQUEUE 5

template <class T>
class CircularQueue
{
private:
    int m_iFront;		///< index of one infront of the first element.
    int m_iRear;		///< index of the last element.
    int m_nMaxQueue;	///< max size of the queue.
    int m_CurPointer;	///< iterator pointer.
    T* m_pItems;		///< pointer for dynamic allocation.

public:
    /**
     * default constructor.
     */
    CircularQueue();

    /**
     * default copy constructor.
     */
    CircularQueue(int max);

    /**
     * deep copy constructor.
     */
    CircularQueue(const CircularQueue<T>& tmp);

    /**
     * destructor.
     */
    ~CircularQueue();

    /**
     *  @brief  Get current pointer
     *  @pre    current pointer is set.
     *  @post   none.
     *  @return current pointer.
     */
    T GetCurPointer() const;

    /**
     *  @brief  Get Queue Max size.
     *  @pre    Max size is set.
     *  @post   none.
     *  @return Max size.
     */
    int GetMaxsize() const;

    /**
	 *	@brief	Determines whether the queue is full.
	 *	@pre	Queue has been initialized.
	 *	@post	Function value = (queue is full)
	 */
    bool IsFull() const;

    /**
	 *	@brief	Determines whether the queue is empty.
	 *	@pre	Queue has been initialized.
  	 *	@post	Function value = (queue is empty)
	 */
    bool IsEmpty() const;

    /**
	 *	@brief	Makes the queue empty.
	 *	@pre	Queue has been initialized.
	 *	@post	m_iFront, m_CurPointer, and m_iRear are set same value as Constructer.
	 */
    void ResetQueue();

    /**
	*	@brief	Reset m_CurPointer.
	*	@pre	none.
	*	@post	m_CurPointer가 m_iFront 값으로 초기화된다.
	*/
    void ResetCurrentPointer();

    /**
	*	@brief	Adds newItem to the last of the queue.
	*	@pre	Queue has been initialized.
	*	@post	If (queue is full), FullQueue exception is thrown; otherwise, newItem is at the last.
	*/
    void EnQueue(T item);

    /**
	*	@brief	Removes first item from the queue.
	*	@pre	Queue has been initialized.
	*	@post	If (queue is empty), EmptyQueue exception is thrown; otherwise, first element has been removed from queue. item gets value of removed item.
	*/
    void DeQueue(T& item);

    /**
	*	@brief	Print all the items in the queue on screen
	*	@pre	Queue has been initialized.
	*	@post	None.
	*/
    void PlayInsertOrder();

    /**
	*	@brief	move list iterator to the next item in list and get that item.
	*	@pre	list and list iterator should not be initialized.
	*	@post	iterator is moved to next item.
	*	@param	data	get current iterator's item. it does not need to be initialized.
	*	@return	index of current iterator's item if is not end of list, oterwise return -1.
	*/
    int GetNextItem(T& item);


};

template <class T>
CircularQueue<T>::CircularQueue()
{
    m_nMaxQueue = MAXQUEUE;
    m_CurPointer = m_nMaxQueue - 1;
    m_iFront = m_nMaxQueue - 1;
    m_iRear = m_nMaxQueue - 1;      // member variable initialization
    m_pItems = new T[m_nMaxQueue];  // make m_pItems that size maxQueue
}

template <class T>
CircularQueue<T>::CircularQueue(int max)
{
    m_nMaxQueue = max;
    m_CurPointer = m_nMaxQueue - 1;
    m_iFront = m_nMaxQueue - 1;
    m_iRear = m_nMaxQueue - 1;  // member variable initialization
    m_pItems = new T[max];      // make m_pItems that size max
}

template <class T>
CircularQueue<T>::CircularQueue(const CircularQueue<T>& tmp)
{
    m_nMaxQueue = tmp.m_nMaxQueue;
    m_CurPointer = tmp.m_CurPointer;
    m_iFront = tmp.m_iFront;
    m_iRear = tmp.m_iRear;  // member variable initialization
    m_pItems = new T[tmp.m_nMaxQueue];      // make m_pItems that size max
}

template <class T>
CircularQueue<T>::~CircularQueue() { delete[] m_pItems; }

template <class T>
T CircularQueue<T>::GetCurPointer() const{ return m_pItems[m_CurPointer]; }

template <class T>
int CircularQueue<T>::GetMaxsize() const{ return m_nMaxQueue; }

template <class T>
bool CircularQueue<T>::IsFull() const
{
    if(m_iFront - m_iRear == 1 || m_iRear - m_iFront == m_nMaxQueue - 1)
        return 1;   // if Circular Queue isn't fool, return 0
    return 0;       // if Circular Queue isn't fool, return 0
}

template <class T>
bool CircularQueue<T>::IsEmpty() const { return m_iFront == m_iRear; }

template <class T>
void CircularQueue<T>::ResetQueue()
{
    m_iFront = m_nMaxQueue - 1;
    m_iRear = m_nMaxQueue - 1; // Change m_iFront and m_iRear to constructor
    delete[] m_pItems;
    m_pItems = new T[m_nMaxQueue];

}

template <class T>
void CircularQueue<T>::ResetCurrentPointer()    { m_CurPointer = m_iFront; }

template <class T>
void CircularQueue<T>::EnQueue(T item)
{
    if(IsFull())
    {
        T tmp;
        DeQueue(tmp);
    }
    m_iRear = (m_iRear + 1) % m_nMaxQueue;
    m_pItems[m_iRear] = item;
}

template <class T>
void CircularQueue<T>::DeQueue(T &item)
{
    if(IsEmpty())
        return;
    m_iFront = (m_iFront + 1) % m_nMaxQueue;
    item = m_pItems[m_iFront];
}

template <class T>
void CircularQueue<T>::PlayInsertOrder()
{
    if(IsEmpty())
        return;
    if(m_iFront > m_iRear)
    {
        for(int i = m_iFront + 1; i < m_nMaxQueue; i++)
            cout << m_pItems[i] << " ------------- ";
        for(int i = 0; i <= m_iRear; i++)
            cout << m_pItems[i] << " ------------- ";
    }
    else
    {
        for(int i = m_iFront + 1; i <= m_iRear; i++)
            cout << m_pItems[i] << " ------------- ";
    }
    cout << endl;
}

template <class T>
int CircularQueue<T>::GetNextItem(T &item)
{
    if(IsEmpty())
        return -1;

    m_CurPointer = (m_CurPointer + 1) % m_nMaxQueue;
    item = m_pItems[m_CurPointer];
    if(m_CurPointer == m_iRear)
    {
        this->ResetCurrentPointer();
        return 0;
    }
    return 1;
}