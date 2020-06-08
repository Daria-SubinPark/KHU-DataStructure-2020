//
// Created by 박수빈 on 2020/04/30.
//
#include "ItemType.h"

ItemType::ItemType()
{
    i_id = -1;
    i_kind = -1;
    i_name = "";
    i_date = "";
    i_num = -1;
    i_website = "";
    storageID = -1;
    containerID = -1;
}

ItemType::~ItemType() {}

int ItemType::GetId() const { return i_id; }

int ItemType::GetKind() const { return i_kind; }

string ItemType::GetName() const { return i_name; }

string ItemType::GetDate() const { return i_date; }

int ItemType::GetNum() const { return i_num; }

string ItemType::GetWebsite() const { return i_website; }

int ItemType::GetStorageID() const { return storageID; }

int ItemType::GetContainerID() const { return containerID; }


void ItemType::SetId(int _id) { i_id = _id; }

void ItemType::SetKind(int _kind) { i_kind = _kind; }

void ItemType::SetName(string _name) { i_name = _name; }

void ItemType::SetDate(string _date) { i_date = _date; }

void ItemType::SetNum(int _num) { i_num = _num; }

void ItemType::SetWebsite(string _website) { i_website = _website; }

void ItemType::SetStorageID(int _sID) { storageID = _sID; }

void ItemType::SetContainerID(int _cID) { containerID = _cID; }

void ItemType::SetRecord(int _id, int _kind, string _name, string _date, int _num, string _website, int _sID, int _cID)
{
    SetId(_id);
    SetKind(_kind);
    SetName(_name);
    SetDate(_date);
    SetNum(_num);
    SetWebsite(_website);
    SetStorageID(_sID);
    SetContainerID(_cID);
}

void ItemType::SetIdFromUser()
{
    cout << "\tID         : ";
    cin >> i_id;
}

void ItemType::SetKindFromUser()
{
    cout << "\tKind(0~2)  : ";
    cin >> i_kind;
}

void ItemType::SetNameFromUser()
{
    cout << "\tName       : ";
    cin >> i_name;
}

void ItemType::SetDateFromUser()
{
    cout << "\tDate       : ";
    cin >> i_date;
}


void ItemType::SetNumFromUser()
{
    cout << "\tNum        : ";
    cin >> i_num;
}

void ItemType::SetWebsiteFromUser()
{
    cout << "\tWebsite    : ";
    cin >> i_website;
}

void ItemType::SetStorageIDFromUser()
{
    cout << "\tStorageID  : ";
    cin >> storageID;
}

void ItemType::SetContainerIDFromUser()
{
    cout << "\tContainerID : ";
    cin >> containerID;
}

void ItemType::SetRecordFromUser()
{
    SetIdFromUser();
    SetKindFromUser();
    SetNameFromUser();
    SetDateFromUser();
    SetNumFromUser();
    SetWebsiteFromUser();
    SetStorageIDFromUser();
    SetContainerIDFromUser();
}

void ItemType::DisplayIdOnScreen()    { cout << "\tID           :" << i_id << "\n"; }

void ItemType::DisplayNameOnScreen()  { cout << "\tName         :" << i_name << "\n"; }

void ItemType::DisplayKindsOnScreen() { cout << "\tKinds        :" << i_kind << "\n"; }

void ItemType::DisplayDateOnScreen()  { cout << "\tDate         :" << i_date << "\n"; }

void ItemType::DisplayNumOnScreen()   { cout << "\tNumber       : " << i_num << "\n"; }

void ItemType::DisplayWebsiteOnScreen() { cout << "\tWebSite      : " << i_website << "\n"; }

void ItemType::DisplayStoIdOnScreen() { cout << "\tStorage ID   : " << storageID << "\n"; }

void ItemType::DisplayConIdOnScreen() { cout << "\tContainer ID : " << containerID << "\n"; }

void ItemType::DisplayRecordOnScreen()
{
    DisplayIdOnScreen();
    DisplayKindsOnScreen();
    DisplayNameOnScreen();
    DisplayDateOnScreen();
    DisplayNumOnScreen();
    DisplayWebsiteOnScreen();
    DisplayStoIdOnScreen();
    DisplayConIdOnScreen();

    if(GetNum() <= 2)
    {
        cout << "\tThis item only left " << GetNum() << endl;
        cout << "\tPlease check website and buy it!\n";
        cout << "\t ====[ " << GetWebsite() << " ]==== " << endl;
    }

}

int ItemType::ReadDataFromFile(ifstream &fin)
{
    fin >> i_id;
    fin >> i_kind;
    fin >> i_name;
    fin >> i_date;
    fin >> i_num;
    fin >> i_website;
    fin >> storageID;
    fin >> containerID;

    return 1;
}

int ItemType::WriteDataToFile(ofstream &fout)
{
    fout << i_id << " ";
    fout << i_kind << " ";
    fout << i_name << " ";
    fout << i_date << " ";
    fout << i_num << " ";
    fout << i_website << " ";
    fout << storageID << " ";
    fout << containerID << endl;

    return 1;
}



