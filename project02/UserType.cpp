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
    cout << "Id       : ";
    cin >> id;
}

void UserType::SetPasswordFromUser()
{
    cout << "Password : ";
    cin >> password;
}

void UserType::SetNameFromUser()
{
    cout << "Name    : ";
    cin >> name;
}

void UserType::SetUserFromUser()
{
    SetIdFromUser();
    SetPasswordFromUser();
    SetNameFromUser();
}
