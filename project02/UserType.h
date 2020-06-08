#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


#include "SortedList.h"
#include "CHeapBase.h"
#include "CMinHeap.h"

#include "ItemType.h"
#include "StorageType.h"
#include "TempType.h"

#define FILENAMESIZE 1024

class UserType
{
private:
    string id;
    string password;
    string name;

    CHeapBase<ItemType>        *MasterList;     ///< master list.
    SortedList<StorageType>     StorageList;    ///< storage list.
    TempType                    TempList;       ///< temp item list.

public:
    UserType();

    ~UserType();

    string GetId() const;
    string GetPassword() const;
    string GetName() const;

    void SetId(string _id);
    void SetPassword(string _pass);
    void SetName(string _name);
    void SetUser(string _id, string _pass, string _name);

    void DisplayIdOnScreen();
    void DisplayPasswordOnScreen();
    void DisplayNameOnScreen();
    void DisplayUserOnScreen();

    void SetIdFromUser();
    void SetPasswordFromUser();
    void SetNameFromUser();
    void SetUserFromUser();

    /**
 *  @brief  Add new record into list. Contain choose master list.
 *  @pre    list should be initialized.
 *  @post   new record is added into the list.
 *  @return return 1 if this function works well, otherwise 0.
 */
    int AddItem();

    /**
     *  @brief  Add new record into list. Contain choose master list or temp list.
     *  @pre    list should be initialized.
     *  @post   new record is added into the list.
     *  @param  item new item
     *  @return return 1 if this function works well, otherwise 0.
     */
    int AddItem(ItemType& item);

    /**
     *  @brief  Add new record into list. Contain choose temp list.
     *  @pre    list should be initialized.
     *  @post   new record is added into the list.
     *  @return return 1 if this function works well, otherwise 0.
     */
    int AddtItem();

    /**
     *  @brief  Add new photo of container into container list.
     *  @pre    list should be initialized.
     *  @post   new photo is added into the container list.
     *  @return return 1 if this function works well, otherwise 0.
     */
    int AddPhoto();

    /**
     *  @brief  Add new photo of container into container list.
     *  @pre    list should be initialized.
     *  @post   new photo is added into the container list.
     *  @return return 1 if this function works well, otherwise 0.
     */
    int AddLocation();

    /**
     *  @brief  Delete item which have input id.
     *  @pre    list should be have input item id.
     *  @post   delete item on master list.
     *  @return return 1 if the function works well, otherwise return 0.
     */
    int DeleteItem();

    /**
     *  @brief  Delete photo which have input address.
     *  @pre    list should be have input photo address(location).
     *  @post   delete photo on container list.
     *  @return return 1 if the function works well, otherwise return 0.
     */
    int DeletePhoto();

    /**
     *  @brief  Replace item which have input id.
     *  @pre    list should be have input item id.
     *  @post   Replace item on list
     *  @return return 1 if the function works well, otherwise return 0.
     */
    int ReplaceItem();

    /**
     *  @brief  Replace item on master list which have input id in temp list.
     *  @pre    list should be have input item id.
     *  @post   Replace item on temp list to master list.
     *  @return return 1 if the function works well, otherwise return 0.
     */
    int DequeueFromtItemList();

    /**
     *  @brief  Replace info. of container which have input container id.
     *  @pre    list should be have input container id.
     *  @post   Replace info. of container on list
     *  @return return 1 if the function works well, otherwise return 0.
     */
    int ReplaceLocation();

    /**
	 *	@brief	Display all records in the list on screen.
  	 *	@pre	none.
	 *	@post	none.
	 */
    void DisplayAllItem();

    /**
	 *	@brief	Display temp item in the queue on screen.
  	 *	@pre	none.
	 *	@post	none.
	 */
    void DisplaytItemList();

    /**
	 *	@brief	Display all photo in the queue on screen.
  	 *	@pre	none.
	 *	@post	none.
	 */
    void DisplayAllPhoto();

    /**
	 *	@brief	Display storage with container in the queue on screen.
  	 *	@pre	none.
	 *	@post	none.
	 */
    void DisplayAllContainer();

    /**
	 *	@brief	Display storage with detail container in the queue on screen.
  	 *	@pre	none.
	 *	@post	none.
	 */
    void DisplayAllDetailsContainer();

    /**
	 *	@brief	Display container with simple items in the queue on screen.
  	 *	@pre	none.
	 *	@post	none.
	 */
    void DisplayAllsItem();

    /**
	 *	@brief	Display container with detail item in the queue on screen.
  	 *	@pre	none.
	 *	@post	none.
	 */
    void DisplayAllDetailsItem();

    /**
    *  @brief  Search item id using binary search.
    *  @pre    none.
    *  @post   print item which is searched
    *  @return return 1 if the function works well, otherwise return 0.
    */
    int SearchById_BinaryS();


    /**
     *  @brief  Search item by name.
     *  @pre    none.
     *  @post   print item which is searched
     *  @return return 1 if the function works well, otherwise return 0.
     */
    ItemType RetreiveRecordByName();

    /**
    *  @brief  Search All item by name.
    *  @pre    input name of item
    *  @post   print All item which is searched
    */
    void SearchByName(ItemType target);


    /**
     *  @brief  Search item by Kind.
     *  @pre    none.
     *  @post   print item which is searched
     *  @return return 1 if the function works well, otherwise return 0.
     */
    ItemType RetreiveRecordByKind();

    /**
    *  @brief  Search All item by Kind.
    *  @pre    input kind of item
    *  @post   print All item which is searched
    */
    void SearchByKind(ItemType target);


    bool operator==(const UserType& _user)
    {
        return (this->GetId() == _user.id);
    }

    bool operator>(const UserType& _user)
    {
        return (this->GetId() > _user.id);
    }
    bool operator<(const UserType& _user)
    {
        return (this->GetId() < _user.id);
    }
    UserType& operator=(const UserType& _user)
    {
        this -> SetId(_user.GetId());
        this -> SetName(_user.GetName());
        this -> SetPassword(_user.GetPassword());
        return *this;
    }

    friend ostream& operator<<(ostream& os, const UserType& _item)
    {
        os << "\tID       : " << _item.GetId() << endl;
        os << "\tName     : " << _item.GetName() << endl;
        os << "\tPassword : " << _item.GetPassword() << endl;
        return os;
    }

};

