//
// Created by 박수빈 on 2020/05/22.
//

#include "pch.h"
#include "UserType.h"

UserType::UserType()
{
    id = "";
    password = "";
    name = "";
}

UserType::~UserType() {}

string UserType::GetId() const
{
    return id;
}

string UserType::GetPassword() const
{
    return password;
}

string UserType::GetName() const
{
    return name;
}

void UserType::SetId(string _id)
{
    id = _id;
}

void UserType::SetPassword(string _pass)
{
    password = _pass;
}

void UserType::SetName(string _name)
{
    name = _name;
}

void UserType::SetUser(string _id, string _pass, string _name)
{
    SetId(_id);
    SetPassword(_pass);
    SetName(_name);
}

void UserType::DisplayIdOnScreen()
{
    cout << "Id       : " << id << endl;
}

void UserType::DisplayPasswordOnScreen()
{
    cout << "Password : " << password << endl;
}

void UserType::DisplayNameOnScreen()
{
    cout << "Name    : " << name << endl;
}

void UserType::DisplayUserOnScreen()
{
    DisplayIdOnScreen();
    DisplayPasswordOnScreen();
    DisplayNameOnScreen();
}

void UserType::SetIdFromUser()
{
    cout << "\tId       : ";
    cin >> id;
}

void UserType::SetPasswordFromUser()
{
    cout << "\tPassword : ";
    cin >> password;
}

void UserType::SetNameFromUser()
{
    cout << "\tName    : ";
    cin >> name;
}

void UserType::SetUserFromUser()
{
    SetIdFromUser();
    SetPasswordFromUser();
    SetNameFromUser();
}

int UserType::AddItem()
{
    if(MasterList.IsFull())
    {
        cout << "\n\t<=======LIST is FULL !========>\n";
        return 0;
    }

    ItemType item;

    item.SetRecordFromUser();

    if(MasterList.Add(item) == 0)
    {
        cout << "\n\t<====ALREADY has same ID !====>\n";
        return 0;
    }

    ContainerType tmpContainer;
    StorageType tmpStorage;
    SimpleItemType tmpsItem;

    tmpContainer.SetConId(item.GetContainerID());
    tmpStorage.SetStoId(item.GetStorageID());
    tmpsItem.SetId(item.GetId());
    tmpsItem.SetName(item.GetName());

    if(StorageList.Get(tmpStorage) == 1)
    {
        if(StorageList.IsFull())
        {
            cout << "\n\t<====STORAGE LIST is FULL !====>\n";
            return 0;
        }

        if (tmpStorage.GetContainer(tmpContainer) == 1)
        {
            tmpContainer.AddsItem(tmpsItem);
            tmpStorage.UpdateContainer(tmpContainer);
            StorageList.Replace(tmpStorage);
        }
        else
        {
            tmpContainer.AddsItem(tmpsItem);
            tmpStorage.AddContainer(tmpContainer);
            StorageList.Replace(tmpStorage);
        }

    }
    else
    {
        tmpContainer.AddsItem(tmpsItem);
        tmpStorage.AddContainer(tmpContainer);
        StorageList.Add(tmpStorage);
    }

    return 1;
}

int UserType::AddItem(ItemType &item)
{
    if(MasterList.IsFull())
    {
        cout << "\n\t<=======LIST is FULL !========>\n";
        return 0;
    }

    if(MasterList.Add(item) == 0)
    {
        cout << "\n\t<====ALREADY has same ID !====>\n";
        return 0;
    }

    ContainerType tmpContainer;
    StorageType tmpStorage;
    SimpleItemType tmpsItem;

    tmpContainer.SetConId(item.GetContainerID());
    tmpStorage.SetStoId(item.GetStorageID());
    tmpsItem.SetId(item.GetId());
    tmpsItem.SetName(item.GetName());

    if(StorageList.Get(tmpStorage) == 1)
    {
        if(StorageList.IsFull())
        {
            cout << "\n\t<====STORAGE LIST is FULL !====>\n";
            return 0;
        }

        if (tmpStorage.GetContainer(tmpContainer) == 1)
        {
            tmpContainer.AddsItem(tmpsItem);
            tmpStorage.UpdateContainer(tmpContainer);
            StorageList.Replace(tmpStorage);
        }
        else
        {
            tmpContainer.AddsItem(tmpsItem);
            tmpStorage.AddContainer(tmpContainer);
            StorageList.Replace(tmpStorage);
        }

    }
    else
    {
        tmpContainer.AddsItem(tmpsItem);
        tmpStorage.AddContainer(tmpContainer);
        StorageList.Add(tmpStorage);
    }

    return 1;
}

int UserType::AddtItem()
{
    ItemType tmpItem;
    tmpItem.SetIdFromUser();
    tmpItem.SetKindFromUser();
    tmpItem.SetNameFromUser();
    tmpItem.SetDateFromUser();
    tmpItem.SetNumFromUser();
    tmpItem.SetWebsiteFromUser();

    int len = TempList.GetnumOfItems();
    TempList.AddtItem(tmpItem);

    if(len < TempList.GetnumOfItems())
        return 1;
    else
    {
        cout << "\n\t<=======ITEM add FAIL !=======>\n";
        return 0;
    }
}

int UserType::AddPhoto()
{
    StorageType tmpSto;
    ContainerType tmpBox;
    tmpSto.SetStoIdFromUser();
    tmpBox.SetConIdFromUser();

    if(StorageList.Get(tmpSto) != 1)
    {
        cout << "\n\t<=====No Storage on List======>\n";
        return 0;
    }

    if(tmpSto.GetContainer(tmpBox) != 1)
    {
        cout << "\n\t<====No Container on List====>\n";
        return 0;
    }

    string photo;
    cout << "\n\tphoto : ";
    cin >> photo;

    tmpBox.AddPhoto(photo);
    tmpSto.UpdateContainer(tmpBox);
    StorageList.Replace(tmpSto);
    return 1;
}

int UserType::AddLocation()
{
    StorageType tmpSto;
    ContainerType tmpBox;
    tmpSto.SetStoIdFromUser();
    tmpBox.SetConIdFromUser();

    if(StorageList.Get(tmpSto) != 1)
    {
        cout << "\n\t<=====No Storage on List======>\n";
        return 0;
    }

    if(tmpSto.GetContainer(tmpBox) != 1)
    {
        cout << "\n\t<====No Container on List====>\n";
        return 0;
    }

    tmpBox.SetConLocationFromUser();
    tmpSto.UpdateContainer(tmpBox);
    StorageList.Replace(tmpSto);
    return 1;
}

int UserType::DeleteItem()
{
    int pre = MasterList.GetLength();
    ItemType item;
    item.SetIdFromUser();

    MasterList.Delete(item);

    ContainerType tmpbox;
    StorageType tmp;
    SimpleItemType tmpsItem;

    tmpbox.SetConId(item.GetContainerID());
    tmpsItem.SetId(item.GetId());
    tmpbox.DeletesItem(tmpsItem);

    tmp.SetStoId(item.GetStorageID());
    StorageList.Get(tmp);
    tmp.UpdateContainer(tmpbox);
    StorageList.Replace(tmp);

    if(pre > MasterList.GetLength())
    {
        cout << "\n\t<=======DELETE SUCCESS !========>\n";
        return 1;
    }

    cout << "\n\t<=======DELETE FAIL !===========>\n";
    return 0;
}

int UserType::DeletePhoto()
{
    StorageType tmpSto;
    ContainerType tmpBox;
    tmpSto.SetStoIdFromUser();
    tmpBox.SetConIdFromUser();

    if(StorageList.Get(tmpSto) != 1)
    {
        cout << "\n\t<=====No Storage on List======>\n";
        return 0;
    }

    if(tmpSto.GetContainer(tmpBox) != 1)
    {
        cout << "\n\t<====No Container on List====>\n";
        return 0;
    }

    string photo;
    cout << "\n\tphoto : ";
    cin >> photo;


    int len = tmpBox.GetPhotoLen();
    tmpBox.DeletePhoto(photo);
    if(tmpBox.GetPhotoLen() > len)
    {
        cout << "\n\t<====Can't Delete Photo on List=====>\n";
        return 0;
    }

    tmpSto.UpdateContainer(tmpBox);
    StorageList.Replace(tmpSto);
    cout << "\n\t<====Delete Photo on List=====>\n";
    return 1;
}

int UserType::ReplaceItem()
{
    ItemType item;
    item.SetRecordFromUser();

    ItemType origin;
    origin.SetId(item.GetId());

    if(MasterList.Get(origin) != 1)
    {
        cout << "\n\t<=Can't find item in Master list=>" << endl;
        return 0;
    }

    MasterList.Get(origin);
    MasterList.Replace(item);

    StorageType tmpSto;
    ContainerType tmpBox;
    SimpleItemType tmpsItem;

    tmpSto.SetStoId(origin.GetStorageID());
    tmpBox.SetConId(origin.GetContainerID());
    tmpsItem.SetId(origin.GetId());

    if(StorageList.Get(tmpSto) == 1)
    {
        if(StorageList.IsFull())
        {
            cout << "\n\t<====STORAGE LIST is FULL !====>\n";
            return 0;
        }

        if (tmpSto.GetContainer(tmpBox) == 1)
        {
            tmpsItem.SetRecord(item.GetId(), item.GetName());
            tmpBox.UpdatesItem(tmpsItem);
            tmpSto.UpdateContainer(tmpBox);
            StorageList.Replace(tmpSto);
        }
        else
        {
            tmpsItem.SetRecord(item.GetId(), item.GetName());
            tmpBox.UpdatesItem(tmpsItem);
            tmpSto.AddContainer(tmpBox);
            StorageList.Replace(tmpSto);
        }

    }
    else
    {
        tmpsItem.SetRecord(item.GetId(), item.GetName());
        tmpBox.AddsItem(tmpsItem);
        tmpSto.AddContainer(tmpBox);
        StorageList.Add(tmpSto);
    }
}

int UserType::DequeueFromtItemList()
{
    ItemType tmpItem;
    int len1 = TempList.GetnumOfItems();
    int len2 = MasterList.GetLength();
    TempList.DequeueFromtItemList(tmpItem);
    tmpItem.SetStorageIDFromUser();
    tmpItem.SetContainerIDFromUser();
    AddItem(tmpItem);

    if(len1 > TempList.GetnumOfItems() && len2 < MasterList.GetLength() )
        return 1;
    else
        return 0;
}

int UserType::ReplaceLocation()
{
    ContainerType tmpBox;
    StorageType tmpSto;

    tmpSto.SetStoIdFromUser();
    tmpBox.SetConIdFromUser();

    if(StorageList.Get(tmpSto) != 1)
    {
        cout << "\n\t<=====No Storage on List======>\n";
        return 0;
    }

    if(tmpSto.GetContainer(tmpBox) != 1)
    {
        cout << "\n\t<====No Container on List====>\n";
        return 0;
    }

    tmpBox.SetConLocationFromUser();
    tmpSto.UpdateContainer(tmpBox);
    StorageList.Replace(tmpSto);

    return 1;
}

void UserType::DisplayAllItem()
{
    ItemType data;

    cout << "\n\t<======Current List========>\n\n";

    MasterList.ResetList();
    int length = MasterList.GetLength();
    int curIndex = MasterList.GetNextItem(data);
    while(curIndex < length && curIndex != -1)
    {
        data.DisplayRecordOnScreen();
        curIndex = MasterList.GetNextItem(data);
    }
}

void UserType::DisplaytItemList()
{
    if(TempList.GetnumOfItems() == 0)
        cout << "\n\t<========No Temp Item========>\n";

    TempList.PrinttItemList();
}

void UserType::DisplayAllPhoto()
{
    StorageType tmpSto;
    ContainerType tmpBox;
    tmpSto.SetStoIdFromUser();
    tmpBox.SetConIdFromUser();

    if(StorageList.Get(tmpSto) != 1)
    {
        cout << "\n\t<=====No Storage on List======>\n";
        return;
    }

    if(tmpSto.GetContainer(tmpBox) != 1)
    {
        cout << "\n\t<====No Container on List====>\n";
        return;
    }

    tmpBox.DisplayAllPhoto();
}

void UserType::DisplayAllContainer()
{
    StorageType tmpSto;
    tmpSto.SetStoIdFromUser();

    StorageList.Get(tmpSto);
    cout << tmpSto << endl;
    tmpSto.DisplayAllContainer();
}

void UserType::DisplayAllDetailsContainer()
{
    StorageType tmpSto;
    tmpSto.SetStoIdFromUser();

    StorageList.Get(tmpSto);
    cout << tmpSto << endl;
    tmpSto.DisplayAllDetailsContainer(MasterList);

}

void UserType::DisplayAllsItem()
{
    StorageType tmpSto;
    ContainerType tmpBox;
    tmpSto.SetStoIdFromUser();
    tmpBox.SetConIdFromUser();

    if(StorageList.Get(tmpSto) != 1)
    {
        cout << "\n\t<=====No Storage on List======>\n";
        return;
    }

    if(tmpSto.GetContainer(tmpBox) != 1)
    {
        cout << "\n\t<====No Container on List====>\n";
        return;
    }

    tmpBox.DisplayAllItem();
}

void UserType::DisplayAllDetailsItem()
{
    StorageType tmpSto;
    ContainerType tmpBox;
    tmpSto.SetStoIdFromUser();
    tmpBox.SetConIdFromUser();

    if(StorageList.Get(tmpSto) != 1)
    {
        cout << "\n\t<=====No Storage on List======>\n";
        return;
    }

    if(tmpSto.GetContainer(tmpBox) != 1)
    {
        cout << "\n\t<====No Container on List====>\n";
        return;
    }
    tmpBox.DisplayAllDetailsItem(MasterList);
}

int UserType::SearchById_BinaryS()
{
    ItemType item;

    item.SetIdFromUser();
    if(MasterList.Get(item) != 0)
    {
        cout << "\n\t<============I FOUND ITEM !==========>\n";
        item.DisplayRecordOnScreen();
        cout << "\n\t<====================================>\n";
        return 1;
    }
    cout << "\t<========I CAN'T FIND ITEM !==========>" << endl;
    return 0;
}

ItemType UserType::RetreiveRecordByName()
{
    ItemType target;
    target.SetNameFromUser();
    return target;
}

void UserType::SearchByName(ItemType target)
{
    ItemType tmp;
    int result = 0;

    MasterList.ResetList();
    while(MasterList.GetNextItem(tmp) != -1)
    {
        if((tmp.GetName() == target.GetName()) == 1)
        {
            if(result == 0)
                cout << "\n\t<============I FOUND ITEM !============>\n";
            tmp.DisplayRecordOnScreen();
            result = 1;
        }
    }

    if(result)
        cout << "\t<===============================>\n";
    else
        cout << "\t<======I CAN'T FIND ITEM !======>\n";
}

ItemType UserType::RetreiveRecordByKind()
{
    ItemType data;
    data.SetKindFromUser();
    return data;
}

void UserType::SearchByKind(ItemType target)
{
    ItemType tmp;
    int result = 0;

    MasterList.ResetList();
    while(MasterList.GetNextItem(tmp) != -1)
    {
        if((tmp.GetKind() == target.GetKind()) == 1)
        {
            if(result == 0)
                cout << "\t<============I FOUND ITEM !============>\n";
            tmp.DisplayRecordOnScreen();
            result = 1;
        }
    }

    if(result)
        cout << "\t<===============================>\n";
    else
        cout << "\t<======I CAN'T FIND ITEM !======>\n";
}
