#include "TempType.h"


TempType::TempType() { numOfItems = 0; }

TempType::~TempType() { }


int TempType::GetnumOfItems() const { return numOfItems; }


void TempType::AddtItem(ItemType _tItem)
{
    tItemList.EnQueue(_tItem);
    numOfItems++;
}

void TempType::DequeueFromtItemList(ItemType &item)
{
    tItemList.DeQueue(item);
    numOfItems--;
}

void TempType::PrinttItemList() { tItemList.PlayInsertOrder(); }
