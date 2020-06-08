//
// Created by 박수빈 on 2020/05/01.
//

#pragma once

#include "BinarySearchTree.h"
#include "UserType.h"

#define FILENAMESIZE 1024


class Application
{
private:
    ifstream                    i_InFile;       ///< input file descriptor.
    ofstream                    i_OutFile;      ///< output file descriptor.
    int                         i_Command;      ///< current command number.

    BinarySearchTree<UserType>  UserList;
    UserType                    CurrentUser;

public:
    /**
     * default constructor.
     */
    Application();

    /**
     * destructor.
     */
    ~Application();

/// login menu
    void LoginRun();

/// Admin's Main menu
    void AdminRun();

    void AddUser();

    void DeleteUser();

    void ReplaceUser();

    void SearchUserById();

    void PrintAllUser();

/// User's Main menu

    void DisplayCurrentUser();

    /**
     *  @brief  Program driver.
     *  @pre    program is started.
     *  @post   program is finished.
     */
    void Run();

    /**
     *  @brief  Display command on screen and get a input from user.
     *  @pre    none.
     *  @post   none.
     *  @return user's command.
     */
    void GetCommand();

    /**
     *  @brief  Display command on screen about ADD list and get a input from user.
     *  @pre    none.
     *  @post   none.
     *  @return user's command.
     */
    void Add();

    /**
     *  @brief  Display command on screen about DELETE list and get a input from user.
     *  @pre    none.
     *  @post   none.
     *  @return user's command.
     */
    void Delete();

    /**
     *  @brief  Display command on screen about REPLACE list and get a input from user.
     *  @pre    none.
     *  @post   none.
     *  @return user's command.
     */
    void Replace();

    /**
     *  @brief  Display command on screen about PRINT list and get a input from user.
     *  @pre    none.
     *  @post   none.
     *  @return user's command.
     */
    void Print();


    /**
	 *	@brief	Open a file by file descriptor as an input file.
	 *	@pre	a file for reading is exist.
	 *	@post	open the file for reading.
	 *	@param	fileName	a filename to open for reading.
	 *	@return	return 1 if this function works well, otherwise 0.
	 */
    int OpenInFile(char *fileName);

    /**
	 *	@brief	Open a file by file descriptor as an output file.
	 *	@pre	list should be initialized.
	 *	@post	open the file for writing.
	 *	@param	fileName	a filename to open for writing.
	 *	@return	return 1 if this function works well, otherwise 0.
	 */
    int OpenOutFile(char *fileName);


    /**
	 *	@brief	Open a file as a read mode, read all data on the file, and set list by the data.
	 *	@pre	The file is not opened.
	 *	@post	list holds all records from the file.
	 *	@return	return 1 if this function works well, otherwise 0.
	 */
    int ReadDataFromFile();

    /**
	 *	@brief	Open a file as a write mode, and write all data into the file,
	 *	@pre	The file is not opened.
	 *	@post	the list is stored in the output file.
	 *	@return	return 1 if this function works well, otherwise 0.
	 */
    int WriteDataToFile();



/// ADD Menu


    /**
     *  @brief  Add new record into list. Contain choose master list.
     *  @pre    list should be initialized.
     *  @post   new record is added into the list.
     *  @return return 1 if this function works well, otherwise 0.
     */
    int AddItem();

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


/// Delete menu


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



/// Replace menu


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



///PRINT & SEARCH menu


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
    *  @brief  Search All item by name.
    *  @pre    input name of item
    *  @post   print All item which is searched
    */
    void SearchByName();

    /**
    *  @brief  Search All item by Kind.
    *  @pre    input kind of item
    *  @post   print All item which is searched
    */
    void SearchByKind();


};


