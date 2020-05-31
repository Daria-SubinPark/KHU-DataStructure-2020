//
// Created by 박수빈 on 2020/04/30.
//


#pragma once

class StorageType
{
private:
    int                             s_id;            ///< storage id.
    int                             currentNum;      ///< number of current container.
    int                             maxNum;          ///< max size of storage.
    SingleLinkedList<ContainerType> ContainerList;   ///< container list.

public:
    /**
     * default constructor.
     */
    StorageType();

    StorageType(int _num);

    /**
     * deep copy constructor.
     */
    StorageType(StorageType& tmp);

    /**
     *  destructor.
     */
    ~StorageType();


    /**
     *  @brief  Get storage id.
     *  @pre    storage id is set.
     *  @post   none.
     *  @return storage id.
     */
    int GetStoId() const;

    /**
     *  @brief  Get number of current container.
     *  @pre    number of current container is set.
     *  @post   none.
     *  @return number of current container.
     */
    int GetCurrentNum() const;

    /**
     *  @brief  Get max size of storage.
     *  @pre    max size of storage is set.
     *  @post   none.
     *  @return max size of storage.
     */
    int GetMaxNum() const;


    /**
     *  @brief  Set Storage id.
     *  @pre    none.
     *  @post   Storage id is set.
     *  @param  _sid    storage id.
     */
    void SetStoId(int _sid);

    /**
     *  @brief  Set max size of storage.
     *  @pre    none.
     *  @post   max size of storage is set.
     *  @param  _num    max size of storage.
     */
    void SetmaxNum(int _num);

    /**
     *  @brief  Set Storage id from user.
     *  @pre    none.
     *  @post   Storage id is set.
     */
    void SetStoIdFromUser();

    /**
	 *	@brief	Determines whether the List is full.
	 *	@pre	List has been initialized.
	 *	@post	Function value = (Storage List is full)
	 */
    bool IsFull();

    /**
     *  @brief  if new Container exist in list, Get Container into Container list.
     *  @pre    Container list and list iterator should not be initialized.
     *  @post   get the new Container in the Container list.
     *  @param  _box   new Container
     */
    int GetContainer(ContainerType& _box);

    /**
     *  @brief  Add Container into Container list.
     *  @pre    Container list should be initialized.
     *  @post   added the new Container into the Container list.
     *  @param  _box   new Container
     */
    void AddContainer(ContainerType& _box);

    /**
    *  @brief  delete Container into Container list.
    *  @pre    Container list and Container list iterator should not be initialized.
    *  @post   delete the new Container into the Container list.
    *  @param  _box   new Container
    */
    void DeleteContainer(ContainerType& _box);

    /**
     *  @brief  if new Container exist in list, replace Container on list to new Container
     *  @pre    Container list and list iterator should not be initialized.
     *  @post   replace Container on list to new Container
     *  @param  _box    new Container
     */
    void UpdateContainer(ContainerType& _box);


    /**
     *  @brief  Display All Container with simple item on screen.
     *  @pre    all Container with simple item is set.
     *  @post   all Container with simple item is on screen.
     */
    void DisplayAllContainer();

    /**
     *  @brief  Display All Container with item on screen.
     *  @pre    all Container with item is set.
     *  @post   all Container with item is on screen.
     */
    void DisplayAllDetailsContainer(SortedList<ItemType>& ref);

    bool operator== (const StorageType& _sto);
    bool operator> (const StorageType& _sto);
    bool operator< (const StorageType& _sto);
    void operator= (StorageType& _sto)
    {
        s_id = _sto.GetStoId();
        currentNum = _sto.GetCurrentNum();
        maxNum = _sto.GetMaxNum();
        ContainerList = _sto.ContainerList;
    }

    friend ostream& operator<<(ostream& os, StorageType& _sto) {
        os << "\n\tStorage ID          : " << _sto.s_id << endl;
        os << "\tNumber of Container : " << _sto.currentNum << endl;
        os << "\t<Container List>----------------- ";
        return os;
    }
};

