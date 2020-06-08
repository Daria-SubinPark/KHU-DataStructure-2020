//
// Created by 박수빈 on 2020/04/30.
//

#include "StorageType.h"


StorageType::StorageType()
{
    s_id = -1;
    currentNum = 0;
    maxNum = MAXSTORAGE;
}

StorageType::StorageType(int _num)
{
    s_id = -1;
    currentNum = 0;
    maxNum = _num;
}


StorageType::StorageType(StorageType &tmp)
{
    s_id = tmp.s_id;
    currentNum = tmp.currentNum;
    maxNum = tmp.maxNum;
    ContainerList = tmp.ContainerList;
}

StorageType::~StorageType() {}

int StorageType::GetStoId() const { return s_id; }

int StorageType::GetCurrentNum() const { return currentNum; }

int StorageType::GetMaxNum() const { return maxNum; }


void StorageType::SetStoId(int _sid) { s_id = _sid; }

void StorageType::SetmaxNum(int _num) { maxNum = _num; }


void StorageType::SetStoIdFromUser()
{
    cout << "\tStorage ID : ";
    cin >> s_id;
}


bool StorageType::IsFull() { return currentNum == maxNum; }

int StorageType::GetContainer(ContainerType &_box) { return ContainerList.Get(_box); }

void StorageType::AddContainer(ContainerType &_box)
{
    ContainerList.Add(_box);
    currentNum = ContainerList.GetLength();
}

void StorageType::DeleteContainer(ContainerType &_box)
{
    ContainerList.Delete(_box);
    currentNum--;
}

void StorageType::UpdateContainer(ContainerType &_box) { ContainerList.Replace(_box); }


void StorageType::DisplayAllContainer()
{
    cout << ContainerList << endl;
}

void StorageType::DisplayAllDetailsContainer(CHeapBase<ItemType>* ref)
{

    ContainerType tmpBox;
    ContainerList.ResetList();
    int len = ContainerList.GetLength();

    for(int i = 0; i < len; i++)
    {
        ContainerList.GetNextItem(tmpBox);
        ContainerType detail;
        detail.SetConId(tmpBox.GetConId());
        ContainerList.Get(detail);
        detail.DisplayAllDetailsItem(ref);
    }

}

bool StorageType::operator== (const StorageType& _sto) { return s_id == _sto.GetStoId(); }

bool StorageType::operator> (const StorageType& _sto) { return s_id > _sto.GetStoId(); }

bool StorageType::operator< (const StorageType& _sto) { return s_id < _sto.GetStoId(); }

