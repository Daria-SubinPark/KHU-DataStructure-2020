//
// Created by 박수빈 on 2020/04/30.
//

#pragma once
#include <iostream>
using namespace std;

/**
*	Structure for NodeType to use in Linked structure.
*/
template <typename T>
struct NodeType
{
    T data;	        ///< A data for each node.
    NodeType* next;	///< A node pointer to point succeed node.
};



/**
*	Simple unsorted list class for managing items.
*/
template <typename T>
class SingleLinkedList
{
private:
    NodeType<T>* i_pList;       ///< Pointer for pointing a first node.
    NodeType<T>* i_pCurPointer; ///< Node pointer for pointing current node to use iteration.
    int i_nLength;              ///< Number of node in the list.

public:
    /**
	*	default constructor.
	*/
    SingleLinkedList();

    /**
	*	deep copy constructor.
	*/
    SingleLinkedList(const SingleLinkedList<T>& tmp);

    /**
	*	destructor.
	*/
    ~SingleLinkedList();

    /**
	*	@brief	Initialize list to empty state.
	*	@pre	None
	*	@post	List is empty.
	*/
    void MakeEmpty();

    /**
	*	@brief	Get number of elements in the list.
	*	@pre	None.
	*	@post	Function value = number of elements in list.
	*	@return	Number of elements in this list.
	*/
    int GetLength() const;

    /**
	*	@brief	Add item into appropriate spot of this list.
	*	@pre	List is not full. item is not in list.
	*	@post	Item is inserted in this list.
	*	@return	1 if this function works well, otherwise 0.
	*/
    int Add(T& item);

    /**
	*	@brief	Delete item from this list.
	*	@pre	List is not empty. the item exists in list.
	*	@post	Item is deleted from this list.
	*	@return	1 if this function works well, otherwise 0.
	*/
    int Delete(T& item);

    /**
	*	@brief	Change value of item which is in this list.
	*	@pre	List is not empty. the item exists in list.
	*	@post	Item's value is changed.
	*	@return	1 if this function works well, otherwise 0.
	*/
    int Replace(T& item);

    /**
	*	@brief	Retrieve list element whose key matches item's key (if present).
	*	@pre	Key member of item is initialized.
	*	@post	If there is an element whose key matches with item's key then the element's record is copied to the item.
	*	@return	1 if any element's primary key matches with item's, otherwise 0.
	*/
    int Get(T& item);

    /**
	*	@brief	Initialize current pointer for an iteration through the list.
	*	@pre	None.
	*	@post	current pointer is prior to list. current pointer has been initialized.
	*/
    void ResetList();

    /**
	*	@brief	Get the next element in list.
	*	@pre	current pointer is defined. Element at current pointer is not last in list.
	*	@post	current pointer is updated to next position. item is a copy of element at current pointer.
	*/
    int GetNextItem(T& item);

    void operator= (SingleLinkedList& _item);

    friend ostream& operator<<(ostream& os, SingleLinkedList<T>& _item)
    {
        T tmpWalker;
        _item.ResetList();
        int len = _item.GetLength();
        for(int i = 0; i < len; i++)
        {
            _item.GetNextItem(tmpWalker);
            os << tmpWalker << endl;
        }
        return os;
    }
};

template<typename T>
SingleLinkedList<T>::SingleLinkedList()
{
    i_nLength = 0;
    i_pList = nullptr;
    i_pCurPointer = nullptr;
}

template<typename T>
SingleLinkedList<T>::SingleLinkedList(const SingleLinkedList<T>& tmp)
{
    i_nLength = tmp.i_nLength;
    i_pList = tmp.i_pCurPointer;
    i_pCurPointer = tmp.i_pCurPointer;
}

template<typename T>
SingleLinkedList<T>::~SingleLinkedList() { MakeEmpty(); }

template<typename T>
void SingleLinkedList<T>::MakeEmpty()
{
    NodeType<T>* tempPtr;

    while(i_pList != nullptr)
    {
        tempPtr = i_pList;
        i_pList = i_pList->next;
        delete tempPtr;
    }

    i_nLength = 0;
}

template<typename T>
int SingleLinkedList<T>::GetLength() const { return i_nLength; }

template<typename T>
int SingleLinkedList<T>::Add(T& item)
{
    ResetList();

    NodeType<T>* node = new NodeType<T>;
    NodeType<T>* pre;
    T tmp;
    bool bFound = false;

    node->data = item;
    node->next = nullptr;

    if(!i_nLength)
        i_pList = node;
    else
    {
        while(true)
        {
            pre = i_pCurPointer;
            GetNextItem(tmp);

            if(i_pCurPointer->data > node->data)
            {
                if(pre == nullptr)
                {
                    node->next = i_pCurPointer;
                    i_pList = node;
                    break;
                }
                node->next = i_pCurPointer;
                pre->next = node;
                break;
            }

            if(i_pCurPointer->next == nullptr)
            {
                i_pCurPointer->next = node;
                break;
            }
        }
    }

    i_nLength++;

    return 1;
}

template<typename T>
int SingleLinkedList<T>::Delete(T& item)
{
    bool mToSearch, found;
    NodeType<T>* pre = nullptr;

    i_pCurPointer = i_pList;
    found = false;
    mToSearch = (i_pCurPointer != nullptr);

    while(mToSearch && !found)
    {
        if(item == i_pCurPointer->data)
        {
            found = true;
            if(pre == nullptr)
                i_pList = i_pCurPointer->next;
            else
            {
                pre->next = i_pCurPointer->next;
                delete i_pCurPointer;
            }
            i_nLength--;
        }
        else
        {
            pre = i_pCurPointer;
            i_pCurPointer = i_pCurPointer->next;
            mToSearch = (i_pCurPointer != nullptr);
        }
    }

    if(found)
        return 1;
    else
        return 0;
}

template<typename T>
int SingleLinkedList<T>::Replace(T& item)
{
    bool mToSearch, found;
    NodeType<T>* loc;

    loc = i_pList;
    found = false;
    mToSearch = (loc != nullptr);

    while(mToSearch && !found)
    {
        if(item == loc->data)
        {
            found = true;
            loc->data = item;
        }
        else
        {
            loc = loc->next;
            mToSearch = (loc != nullptr);
        }
    }

    if (found)
        return 1;
    else
        return 0;
}

template<typename T>
int SingleLinkedList<T>::Get(T &item)
{
    bool mToSearch, found;
    NodeType<T>* loc;

    loc = i_pList;
    found = false;
    mToSearch = (loc != nullptr);

    while(mToSearch && !found)
    {
        if(item == loc->data)
        {
            found = true;
            item = loc->data;
        }
        else
        {
            loc = loc->next;
            mToSearch = (loc != nullptr);
        }
    }

    if(found)
        return 1;
    else
        return 0;
}

template<typename T>
void SingleLinkedList<T>::ResetList() { i_pCurPointer = nullptr; }

template<typename T>
int SingleLinkedList<T>::GetNextItem(T &item)
{
    if(i_pCurPointer == nullptr)
    {
        i_pCurPointer = i_pList;
    }
    else
        i_pCurPointer = i_pCurPointer->next;


    item = i_pCurPointer->data;
    return 1;
}

template<typename T>
void SingleLinkedList<T>::operator=(SingleLinkedList& _item)
{
    MakeEmpty();
    int len = _item.GetLength();
    _item.ResetList();

    for(int i = 0; i < len; i++)
    {
        T item;
        _item.GetNextItem(item);
        Add(item);
    }

}

