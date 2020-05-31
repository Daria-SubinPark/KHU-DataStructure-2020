//
// Created by 박수빈 on 2020/04/30.
//

#include "pch.h"
#include "SimpleItemType.h"

SimpleItemType::SimpleItemType()
{
    i_id = -1;
    i_name = "";
}

SimpleItemType::~SimpleItemType() {}


int SimpleItemType::GetId() const { return i_id; }

string SimpleItemType::GetName() const { return i_name; }


void SimpleItemType::SetId(int _id) { i_id = _id; }

void SimpleItemType::SetName(string _name) { i_name = _name; }

void SimpleItemType::SetRecord(int _id, string _name)
{
    SetId(_id);
    SetName(_name);
}
