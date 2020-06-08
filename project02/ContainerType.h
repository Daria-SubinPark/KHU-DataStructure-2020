//
// Created by 박수빈 on 2020/04/30.
//
#pragma once
#include <iostream>
#include <string>
using namespace std;


#include "UnsortedList.h"
#include "SortedList.h"
#include "CHeapBase.h"
#include "SimpleItemType.h"
#include "ItemType.h"

class ContainerType
{
private:
    int                             c_id;       ///< container ID
    string                          c_location; ///< container location
    UnsortedList<SimpleItemType>    sItemList;  ///< item list
    UnsortedList<string>            photoList;  ///< container photo list

public:
    /**
     * default constructor.
     */
    ContainerType();

    /**
     *  destructor.
     */
    ~ContainerType();

    /**
     *  @brief  Get container id.
     *  @pre    container id is set.
     *  @post   none.
     *  @return container id.
     */
    int GetConId() const;

    /**
     *  @brief  Get container Location.
     *  @pre    container location is set.
     *  @post   none.
     *  @return container location.
     */
    string GetConLocation() const;

    /**
     *  @brief  Get current length of photo list.
     *  @pre    current length of photo list is set.
     *  @post   none.
     *  @return current length of photo list.
     */
    int GetPhotoLen() const;


    /**
     *  @brief  Set container id.
     *  @pre    none.
     *  @post   container id is set.
     *  @param  _cid    container id.
     */
    void SetConId(int _id);

    /**
    *  @brief  Set container location.
    *  @pre    none.
    *  @post   container location is set.
    *  @param  _cloc    container location.
    */
    void SetConLocation(string _loc);


    /**
     *  @brief  Set container id from user.
     *  @pre    none.
     *  @post   container id is set.
     */
    void SetConIdFromUser();

    /**
     *  @brief  Set container location from user.
     *  @pre    none.
     *  @post   container location is set.
     */
    void SetConLocationFromUser();

    /**
     *  @brief  Set item recode from user.
     *  @pre    none.
     *  @post   item recode is set.
     */
    void SetConRecordFromUser();


    /**
     *  @brief  Add item into item list.
     *  @pre    item list should be initialized.
     *  @post   added the new item into the item list.
     *  @param  _item   new simple item
     */
    void AddsItem(SimpleItemType& _item);

    /**
    *  @brief  delete item into item list.
    *  @pre    item list and item list iterator should not be initialized.
    *  @post   delete the new item into the item list.
    *  @param  _item   new simple item
    */
    void DeletesItem(SimpleItemType& _item);

    /**
     *  @brief  if new item exist in list, replace item on list to new item
     *  @pre    item list and list iterator should not be initialized.
     *  @post   replace on list item to new item
     *  @param  _item    new item
     */
    void UpdatesItem(SimpleItemType& _item);

    /**
     *  @brief  Add photo into photo list.
     *  @pre    photo list should be initialized.
     *  @post   added the new photo into the photo list.
     *  @param  photo   new photo
     */
    void AddPhoto(string photo);

    /**
     *  @brief  delete photo into item photo.
     *  @pre    photo list and photo list iterator should not be initialized.
     *  @post   delete the new photo into the photo list.
     *  @param  photo   new photo
     */
    void DeletePhoto(string photo);


    /**
     *  @brief  Display All photo on screen.
     *  @pre    all photo is set.
     *  @post   all photo is on screen.
     */
    void DisplayAllPhoto();

    /**
     *  @brief  Display All simple item on screen.
     *  @pre    all simple item is set.
     *  @post   all simple item is on screen.
     */
    void DisplayAllItem();

    /**
     *  @brief  Display All item on screen.
     *  @pre    all item is set.
     *  @post   all item is on screen.
     */
    void DisplayAllDetailsItem(CHeapBase<ItemType>* re);

    /**
     *  @brief  Get number of simple items
     *  @pre    all item is set.
     *  @post   none.
     *  @return simple item list's length
     */
    int GetitemLength();

    bool operator==(const ContainerType& _box);
    bool operator>(const ContainerType& _box);
    bool operator<(const ContainerType& _box);
    void operator=(const ContainerType& _box);

    friend ostream& operator<<(ostream& os, ContainerType& _box) {
        os << "\tContainer ID : " << _box.c_id << endl;
        if(!_box.c_location.empty())
            os << "\tLocation		: " << _box.c_location << endl;
        os << "\n\t<ItemList>----------------" << endl;
        os << _box.sItemList << endl;
        if(_box.GetPhotoLen() != 0)
        {
            os << "\t<PhotoList>---------------" << endl;
            os << "\t" << _box.photoList << endl;
        }
        else
            os << "\t<NO PHOTO>----------------" << endl;
        return os;
    }
};

