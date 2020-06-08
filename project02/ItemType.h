//
// Created by 박수빈 on 2020/04/30.
//

#pragma once


#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class ItemType
{
private:
    int         i_id;           ///< item ID.
    int         i_kind;         ///< item kind.
    string      i_name;         ///< item name.
    string      i_date;         ///< item's buy date
    int         i_num;          ///< item number.
    string      i_website;      ///< website where item was purchased.
    int         storageID;      ///< storage(which have this item)'s ID.
    int         containerID;    ///< container(which have this item)'s ID.


public:
    /**
     * default constructor.
     */
    ItemType();

    /**
     *  destructor.
     */
    ~ItemType();

    /**
     *  @brief  Get item id.
     *  @pre    item id is set.
     *  @post   none.
     *  @return item id.
     */
    int GetId() const;

    /**
     *  @brief  Get item kinds.
     *  @pre    item kinds is set.
     *  @post   none.
     *  @return item kinds.
     */
    int GetKind() const;

    /**
      *  @brief  Get item name
      *  @pre    item name is set.
      *  @post   none.
      *  @return item name.
      */
    string GetName() const;

    /**
     *  @brief  Get date buying item.
     *  @pre    date buying item is set.
     *  @post   none.
     *  @return date buying item.
     */
    string GetDate() const;


    /**
     *  @brief  Get number of item.
     *  @pre    number of item is set.
     *  @post   none.
     *  @return number of item.
     */
    int GetNum() const;

    /**
     *  @brief  Get website link where item was purchased.
     *  @pre    website link where item was purchased is set
     *  @post   none.
     *  @return website link where item was purchased.
     */
    string GetWebsite() const;

    /**
     *  @brief  Get storage id.
     *  @pre    storage id is set.
     *  @post   none.
     *  @return storage id.
     */
    int GetStorageID() const;

    /**
     *  @brief  Get container id.
     *  @pre    container id is set.
     *  @post   none.
     *  @return container id.
     */
    int GetContainerID() const;

    /**
     *  @brief  Set item id.
     *  @pre    none.
     *  @post   Item id is set.
     *  @param  _Id    item id.
     */
    void SetId(int _id);

    /**
    *  @brief  Set item kinds.
    *  @pre    none.
    *  @post   Item kinds is set.
    *  @param  _Kinds    item kinds.
    */
    void SetKind(int _kind);

    /**
     *  @brief  Set item name.
     *  @pre    none.
     *  @post   Item name is set.
     *  @param  _Name    item Name.
     */
    void SetName(string _name);

    /**
     *  @brief  Set date buying item.
     *  @pre    none.
     *  @post   Date buying item is set.
     *  @param  _Date    date buying item.
     */
    void SetDate(string _date);

    /**
    *  @brief  Set number of item.
    *  @pre    none.
    *  @post   Number of item is set.
    *  @param  _Num    number of item.
    */
    void SetNum(int _num);

    /**
     *  @brief  set website link where item was purchased.
     *  @pre    none.
     *  @post   Website link where item was purchased is set.
     *  @return _website    website link where item was purchased.
     */
    void SetWebsite(string _website);

    /**
    *  @brief  Set storage id.
    *  @pre    none.
    *  @post   Storage id is set.
    *  @param  _sID     storage id.
    */
    void SetStorageID(int _sID);

    /**
    *  @brief  Set container id.
    *  @pre    none.
    *  @post   Container id is set.
    *  @param  _cID     container id.
    */
    void SetContainerID(int _cID);

    /**
     *  @brief  Set item record.
     *  @pre    none.
     *  @post   Item record is set.
     *  @param  _id      item id.
     *  @param  _kind    item kinds.
     *  @param  _date    date buying item.
     *  @param  _name    item name.
     *  @param  _num     number of item.
     *  @param  _website website link where item was purchased.
     *  @param  _sID     storage id.
     *  @param  _cID     container id.
     */
    void SetRecord(int _id, int _kind, string _date, string _name, int _num, string _website, int _sID, int _cID);


    /**
     *  @brief  Set item id from user.
     *  @pre    none.
     *  @post   item id is set.
     */
    void SetIdFromUser();

    /**
     *  @brief  Set item kinds from user.
     *  @pre    none.
     *  @post   item kinds is set.
     */
    void SetKindFromUser();

    /**
     *  @brief  Set item name from user.
     *  @pre    none.
     *  @post   item name is set.
     */
    void SetNameFromUser();

    /**
     *  @brief  Set date buying item from user.
     *  @pre    none.
     *  @post   date buying item is set.
     */
    void SetDateFromUser();

    /**
     *  @brief  Set number of item from user.
     *  @pre    none.
     *  @post   number of item is set.
     */
    void SetNumFromUser();

    /**
     *  @brief  Set website link where item was purchased. from user.
     *  @pre    none.
     *  @post   website link where item was purchased. is set.
     */
    void SetWebsiteFromUser();

    /**
    *  @brief  Set storage id from user.
    *  @pre    none.
    *  @post   storage id is set.
    */
    void SetStorageIDFromUser();

    /**
    *  @brief  Set container id from user.
    *  @pre    none.
    *  @post   container id is set.
    */
    void SetContainerIDFromUser();

    /**
     *  @brief  Set item record from user.
     *  @pre    none.
     *  @post   item record is set.
     */
    void SetRecordFromUser();

    /**
     *  @brief  Display item id on screen.
     *  @pre    item id is set.
     *  @post   item id is on screen.
     */
    void DisplayIdOnScreen();
    /**
     *  @brief  Display item name on screen
     *  @pre    item name is set.
     *  @post   item name is on screen.
     */
    void DisplayNameOnScreen();


    /**
     *  @brief  Display item kinds on screen
     *  @pre    item kinds is set.
     *  @post   item kinds is on screen.
     */
    void DisplayKindsOnScreen();


    /**
     *  @brief  Display date buying item on screen
     *  @pre    date buying item is set.
     *  @post   date buying item is on screen.
     */
    void DisplayDateOnScreen();

    /**
     *  @brief  Display number of item on screen
     *  @pre    number of item is set.
     *  @post   number of item is on screen.
     */
    void DisplayNumOnScreen();

    /**
     *  @brief  Display website link where item was purchased.
     *  @pre    website link where item was purchased is set.
     *  @post   website link where item was purchased is on screen.
     */
    void DisplayWebsiteOnScreen();

    /**
     *  @brief  Display StorageID of item on screen
     *  @pre    StorageID of item is set.
     *  @post   StorageID of item is on screen.
     */
    void DisplayStoIdOnScreen();


    /**
     *  @brief  Display ContainerID of item on screen
     *  @pre    ContainerID of item is set.
     *  @post   ContainerID of item is on screen.
     */
    void DisplayConIdOnScreen();


    /**
     *  @brief  Display item record ont screen.
     *  @pre    item record is set.
     *  @post   item record is on screen.
     */
    void DisplayRecordOnScreen();

    /**
     *  @brief  Read a record from file.
     *  @pre    the target file is opened.
     *  @post   item record is set.
     *  @param  fin     file descriptor.
     *  @return return 1 if this function works well, otherwise 0.
     */
    int ReadDataFromFile(ifstream& fin);

    /**
     *  @brief  Write a record into file.
     *  @pre    the target file is opened. And the list should be initialized.
     *  @post   the target file is included the new item record.
     *  @param  fout    file descriptor.
     *  @return return 1 if this function works well, otherwise 0.
     */
    int WriteDataToFile(ofstream& fout);

    bool operator==(const ItemType& _item)
    {
        return (this->GetId() == _item.i_id/*|| this->GetName() == _item.i_name*/);
    }

    bool operator>(const ItemType& _item)
    {
        return this-> GetId() > _item.i_id;
    }
    bool operator<(const ItemType& _item)
    {
        return this-> GetId() < _item.i_id;
    }
    ItemType& operator=(const ItemType& _item)
    {
        this -> SetId(_item.GetId());
        this -> SetKind(_item.GetKind());
        this -> SetName(_item.GetName());
        this -> SetDate(_item.GetDate());
        this -> SetNum(_item.GetNum());
        this -> SetWebsite(_item.GetWebsite());
        this -> SetStorageID(_item.GetStorageID());
        this -> SetContainerID(_item.GetContainerID());
        return *this;
    }

    friend ostream& operator<<(ostream& os, const ItemType& _item)
    {
        os << "\tID       : " << _item.GetId() << endl;
        os << "\tKind     : " << _item.GetKind() << endl;
        os << "\tName     : " << _item.GetName() << endl;
        os << "\tDate     : " << _item.GetDate() << endl;
        os << "\tNum      : " << _item.GetNum() << endl;
        os << "\tWebsite  : " << _item.GetWebsite() << endl;
        os << "\tStorage  : " << _item.GetStorageID() << endl;
        os << "\tContainer: " << _item.GetContainerID() << endl << endl;

        if(_item.GetNum() <= 2)
        {
            os << "\tThis item only left " << _item.GetNum() << endl;
            os << "\tPlease check website and buy it!\n";
            os << "\t ====[ " << _item.GetWebsite() << " ]==== " << endl;
        }
        return os;
    }


};
