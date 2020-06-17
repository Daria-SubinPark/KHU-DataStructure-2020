//
// Created by 박수빈 on 2020/05/22.
//

#include "UserType.h"

UserType::UserType()
{
    id = "";
    password = "";
    name = "";
    MasterList = new CMinHeap<ItemType>(10);
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
    if(MasterList->IsFull())
    {
        cout << "\n\tList is full" << endl;
        return 0;
    }

    ItemType item;
    bool check = false;

    item.SetRecordFromUser();
    MasterList->RetrieveItem(item, check);

    if(check)
    {
        cout << "\n\tAlready has same ID!" << endl;
        return 0;
    }
    else if(MasterList->IsFull())
    {
        cout << "\tMaster List is full" << endl;
        return 0;
    }


    MasterList->Add(item);

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
            cout << "\tStorage List is full" << endl;
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
    bool check = false;
    MasterList->RetrieveItem(item, check);

    if(check)
    {
        cout << "\n\tAlready has same ID!" << endl;
        return 0;
    }
    else if(MasterList->IsFull())
    {
        cout << "\tMaster List is full" << endl;
        return 0;
    }


    MasterList->Add(item);

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
            cout << "\tStorage List is full" << endl;
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
    ContainerType tmpbox;
    StorageType tmp;
    SimpleItemType tmpsItem;
    ItemType item;
    bool check;

    item.SetIdFromUser();

    if(!MasterList->Delete(item))
    {
        cout << "\n\t<=======DELETE FAIL !===========>\n";
        return 0;
    }

    MasterList->RetrieveItem(item, check);

    tmpbox.SetConId(item.GetContainerID());
    tmpsItem.SetId(item.GetId());
    tmp.SetStoId(item.GetStorageID());
    StorageList.Get(tmp);

    if(tmpbox.GetitemLength() == 0)
    {
        tmpbox.DeletesItem(tmpsItem);
        tmp.DeleteContainer(tmpbox);
        if(tmp.GetCurrentNum() == 0)
        {
            StorageList.Delete(tmp);

            cout << "\n\t<=======DELETE SUCCESS !========>\n";
            return 1;
        }
        StorageList.Replace(tmp);

        cout << "\n\t<=======DELETE SUCCESS !========>\n";
        return 1;
    }

    tmpbox.DeletesItem(tmpsItem);
    tmp.UpdateContainer(tmpbox);
    StorageList.Replace(tmp);

    cout << "\n\t<=======DELETE SUCCESS !========>\n";
    return 1;
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

    bool check = false;

    MasterList->RetrieveItem(origin, check);

    if(!check)
    {
        cout << "\n\t<=Can't find item in Master list=>" << endl;
        return 0;
    }

    MasterList->Delete(origin);
    MasterList->Add(item);

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
            cout << "\tStorage List is full" << endl;
            return 0;
        }

        if (tmpSto.GetContainer(tmpBox) == 1)
        {
            tmpsItem.SetRecord(item.GetId(), item.GetName());
            tmpBox.UpdatesItem(tmpsItem);
            tmpSto.UpdateContainer(tmpBox);
            StorageList.Replace(tmpSto);
            return 1;
        }
        else
        {
            tmpsItem.SetRecord(item.GetId(), item.GetName());
            tmpBox.UpdatesItem(tmpsItem);
            tmpSto.AddContainer(tmpBox);
            StorageList.Replace(tmpSto);
            return 1;
        }

    }
    else
    {
        tmpsItem.SetRecord(item.GetId(), item.GetName());
        tmpBox.AddsItem(tmpsItem);
        tmpSto.AddContainer(tmpBox);
        StorageList.Add(tmpSto);
        return 1;
    }
}

int UserType::DequeueFromtItemList()
{
    ItemType tmpItem;
    int len1 = TempList.GetnumOfItems();
    int len2 = MasterList->GetLength();
    TempList.DequeueFromtItemList(tmpItem);
    tmpItem.SetStorageIDFromUser();
    tmpItem.SetContainerIDFromUser();
    AddItem(tmpItem);

    if(len1 > TempList.GetnumOfItems() && len2 < MasterList->GetLength() )
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

    if(!MasterList->IsEmpty())
    {
        cout << "\n\t<======Current list======>\n\n";
        MasterList->PrintHeap();
    }
    else
        cout << "\n\t<========Empty!!!========>\n\n";
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
    bool check = false;

    item.SetIdFromUser();

    MasterList->RetrieveItem(item, check);


    if(check)
    {
        cout << "\n\t<============I FOUND ITEM !==========>\n";
        item.DisplayRecordOnScreen();
        cout << "\n\t<====================================>\n";
        return 1;
    }
    cout << "<========I CAN'T FIND ITEM !==========>" << endl;
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
    ItemType item;
    bool check;

    cout << "\n\t<=======Current list========>\n\n";

    for (int i = 0; i < MasterList->GetLength(); i++) {
        if (MasterList->GetArray(i).GetName() == target.GetName()) {
            StorageType tmpSto;
            ContainerType tmpCon;
            tmpSto.SetStoId(item.GetStorageID());
            StorageList.Get(tmpSto);

            tmpCon.SetConId(item.GetContainerID());
            tmpSto.GetContainer(tmpCon);

            item.SetId(MasterList->GetArray(i).GetId());
            MasterList->RetrieveItem(item, check);
            item.DisplayRecordOnScreen();
            if (tmpCon.GetPhotoLen() == 0)
                cout << "\t<=====NO Photo=====>\n";
            else {
                cout << "\tPhotoList  : ";
                tmpCon.DisplayAllPhoto();
                cout << endl;
            }
        }
    }
    return;
}

ItemType UserType::RetreiveRecordByKind()
{
    ItemType data;
    data.SetKindFromUser();
    return data;
}

void UserType::SearchByKind(ItemType target)
{
    ItemType item;
    bool check;

    cout << "\n\t<=======Current list========>\n\n";

    for (int i = 0; i < MasterList->GetLength(); i++) {
        if (MasterList->GetArray(i).GetKind() == target.GetKind()) {
            StorageType tmpSto;
            ContainerType tmpCon;
            tmpSto.SetStoId(item.GetStorageID());
            StorageList.Get(tmpSto);

            tmpCon.SetConId(item.GetContainerID());
            tmpSto.GetContainer(tmpCon);

            item.SetId(MasterList->GetArray(i).GetId());
            MasterList->RetrieveItem(item, check);
            item.DisplayRecordOnScreen();
            if (tmpCon.GetPhotoLen() == 0)
                cout << "\t<=====NO Photo=====>\n";
            else {
                cout << "\tPhotoList  : ";
                tmpCon.DisplayAllPhoto();
                cout << endl;
            }
        }
    }
    return;
}

int UserType::ReadDataFromFile(ifstream &fin)
{
    fin >> id;
    fin >> password;
    fin >> name;
    return 1;
}

int UserType::WriteDataToFile(ofstream &fout)
{
    return 0;
}
