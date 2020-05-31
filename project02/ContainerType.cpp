//
// Created by 박수빈 on 2020/04/30.
//

#include "pch.h"
#include "ContainerType.h"



ContainerType::ContainerType()
{
    c_id = -1;
    c_location = "";
}

ContainerType::~ContainerType() {}


int ContainerType::GetConId() const { return c_id; }

string ContainerType::GetConLocation() const { return c_location; }


int ContainerType::GetPhotoLen() const { return photoList.GetLength(); }

void ContainerType::SetConId(int _id) { c_id = _id; }

void ContainerType::SetConLocation(string _loc) { c_location = _loc; }

void ContainerType::SetConIdFromUser()
{
    cout << "\tContainer ID : ";
    cin >> c_id;
}

void ContainerType::SetConLocationFromUser()
{
    cout << "\tLocation     : ";
    cin >> c_location;
}

void ContainerType::SetConRecordFromUser()
{
    SetConIdFromUser();
    SetConLocationFromUser();
}


void ContainerType::AddsItem(SimpleItemType &_item) { sItemList.Add(_item); }

void ContainerType::DeletesItem(SimpleItemType &_item) { sItemList.Delete(_item); }

void ContainerType::UpdatesItem(SimpleItemType &_item) { sItemList.Replace(_item); }


void ContainerType::AddPhoto(string photo) { photoList.Add(photo); }

void ContainerType::DeletePhoto(string photo) { photoList.Delete(photo); }


void ContainerType::DisplayAllPhoto()
{
    string pho;
    photoList.GetNextItem(pho);
    if(photoList.GetLength() != 0)
    {
        cout << "\t<PhotoList>---------------\n";
        for(int i = 0; i < photoList.GetLength(); i++)
        {
            cout << "\t" << pho << endl;
            photoList.GetNextItem(pho);
        }
    }
    else
        cout << "\t<===Photo list is empty====>\n";
}

void ContainerType::DisplayAllItem() { cout << sItemList << endl; }

void ContainerType::DisplayAllDetailsItem(SortedList<ItemType> &ref)
{
    SimpleItemType tmpItem;
    sItemList.ResetList();
    cout << "\t<ItemList>----------------\n";
    while(sItemList.GetNextItem(tmpItem) != -1)
    {
        ItemType detail;
        detail.SetId(tmpItem.GetId());
        ref.Get(detail);
        cout << detail;
    }
    DisplayAllPhoto();
}


bool ContainerType::operator==(const ContainerType &_box) { return c_id == _box.GetConId(); }

bool ContainerType::operator>(const ContainerType &_box) { return c_id > _box.GetConId(); }

bool ContainerType::operator<(const ContainerType &_box) { return c_id < _box.GetConId(); }

void ContainerType::operator=(const ContainerType &_box)
{
    c_id = _box.GetConId();
    c_location = _box.GetConLocation();
    sItemList = _box.sItemList;
    photoList = _box.photoList;
}
