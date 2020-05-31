//
// Created by 박수빈 on 2020/04/30.
//


#pragma once

class TempType
{
private:
    int numOfItems;                     ///< number of temp items in list.
    CircularQueue<ItemType> tItemList;  ///< temp item list.

public:
    /**
     * default constructor.
     */
    TempType();

    /**
     *  destructor.
     */
    ~TempType();


    /**
     *  @brief  Get a number of temp item in current list.
     *  @pre    none.
     *  @post   none.
     *  @return number of temp item in current list.
    */
    int GetnumOfItems() const;

    /**
     *  @brief  Add temp item into temp item list.
     *  @pre    temp item list should be initialized.
     *  @post   added the new temp item into the temp item list.
     *  @param  _tItem   new item
     */
    void AddtItem(ItemType _tItem);

    /**
	*	@brief	Removes first item(= new item) from the queue.
	*	@pre	Queue has been initialized.
	*	@post	If (queue is empty), EmptyQueue exception is thrown; otherwise, first element has been removed from queue. item gets value of removed item.
	*/
    void DequeueFromtItemList(ItemType& item);

    /**
     *  @brief  Display temp item list on screen.
     *  @pre    temp item list is set.
     *  @post   temp item list is on screen.
     */
    void PrinttItemList();
};


