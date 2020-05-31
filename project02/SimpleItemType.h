//
// Created by 박수빈 on 2020/04/30.
//

#pragma once

class SimpleItemType
{
private:
    int i_id;       ///< item id.
    string i_name;  ///< item name.

public:
    /**
     * default constructor.
     */
    SimpleItemType();

    /**
     *  destructor.
     */
    ~SimpleItemType();

    /**
     *  @brief  Get item id.
     *  @pre    item id is set.
     *  @post   none.
     *  @return item id.
     */
    int GetId() const;

    /**
      *  @brief  Get item name
      *  @pre    item name is set.
      *  @post   none.
      *  @return item name.
      */
    string GetName() const;


    /**
     *  @brief  Set item id.
     *  @pre    set item id on master list.
     *  @post   Item id is set.
     *  @param  inId    item id.
     */
    void SetId(int _id);

    /**
     *  @brief  Set item name.
     *  @pre    set item name on master list.
     *  @post   Item name is set.
     *  @param  inName    item Name.
     */
    void SetName(string _name);

    /**
     *  @brief  Set item record.
     *  @pre    none.
     *  @post   Item record is set.
     *  @param  inId    item id.
     *  @param  inName  item name.
     */
    void SetRecord(int _id, string _name);


    bool operator==(const SimpleItemType& _item)
    {
        return i_id == _item.GetId();
    }
    bool operator>(const SimpleItemType& _item)
    {
        return i_id > _item.GetId();
    }
    bool operator<(const SimpleItemType& _item)
    {
        return i_id < _item.GetId();
    }
    void operator=(const SimpleItemType& _item)
    {
        i_id = _item.GetId();
        i_name = _item.GetName();
    }
    friend ostream& operator<<(ostream& os, const SimpleItemType& _item)
    {
        os << "\tID     : " << _item.GetId() << endl;
        os << "\tName   : " << _item.GetName() << endl;
        return os;
    }
};


