//
// Created by 박수빈 on 2020/05/01.
//

#include "pch.h"
#include "Application.h"

Application::Application() { i_Command = 0; }

Application::~Application() {}

void Application::Run()
{
    while(1)
    {
        GetCommand();

        switch (i_Command)
        {
            case 1:     ///< display list about add
                Add();
                break;
            case 2:     ///< display list about delete
                Delete();
                break;
            case 3:     ///< display list about replace
                Replace();
                break;
            case 4:     ///< display list about print
                Print();
                break;
            case 5:     ///< load list data from a file.
                ReadDataFromFile();
                break;
            case 6:     ///< save list data into a file.
                WriteDataToFile();
                break;
            case 0:
                return;
            default:
                cout << "\tIllegal selection...\n";
                break;
        }
    }
}

void Application::GetCommand()
{
    cout << "\n\n";
    cout << "\n\t== <Main Menu> =============================\n";
    cout << "\t #  1 | ADD\n";
    cout << "\t #  2 | DELETE\n";
    cout << "\t #  3 | REPLACE\n";
    cout << "\t #  4 | PRINT and SEARCH on screen\n";
    cout << "\t-------------------------------------------\n";
    cout << "\t #  5 | GET from FILE\n";
    cout << "\t #  6 | PUT fo FILE\n";
    cout << "\t-------------------------------------------\n";
    cout << "\t #  0 | Quit\n";
    cout << "\t===========================================\n";

    cout << "\n\t Choose a Commend--> ";
    cin >> i_Command;
    cout << endl;
}

void Application::Add()
{
    int a_command;

    while(1)
    {
        cout << "\n\n";
        cout << "\t== <ADD Menu> =============================\n";
        cout << "\t #  1 | Back to Main menu\n";
        cout << "\t-------------------------------------------\n";
        cout << "\t #  2 | Item\n";
        cout << "\t #  3 | Temp Item\n";
        cout << "\t #  4 | Photo about Container\n";
        cout << "\t #  5 | Location about Container\n";
        cout << "\t-------------------------------------------\n";
        cout << "\t #  0 | Quit\n";
        cout << "\t===========================================\n";

        cout << "\n\t Choose a Commend--> ";
        cin >> a_command;
        cout << endl;

        switch (a_command)
        {
            case 1:     ///< back to main menu
                return;
            case 2:     ///< read a item and add to list
                AddItem();
                break;
            case 3:     ///< read temp item and add to temp list
                AddtItem();
                break;
            case 4:     ///< find a container and add a photo
                AddPhoto();
                break;
            case 5:     ///< read a container and add location info. to list
                AddLocation();
                break;
            case 0:
                i_Command = 0;
                return;
        }
    }

}

void Application::Delete()
{
    int d_command;

    while(1)
    {
        cout << "\n\n";
        cout << "\t== <DELETE Menu> ==========================\n";
        cout << "\t #  1 | Back to Main menu\n";
        cout << "\t-------------------------------------------\n";
        cout << "\t #  2 | Item\n";
        cout << "\t #  3 | Photo about Container\n";
        cout << "\t-------------------------------------------\n";
        cout << "\t #  4 | Make EMPTY list\n";
        cout << "\t-------------------------------------------\n";
        cout << "\t #  0 | Quit\n";
        cout << "\t===========================================\n";

        cout << "\n\t Choose a Commend--> ";
        cin >> d_command;
        cout << endl;

        switch (d_command)
        {
            case 1:     ///< back to main menu
                return;
            case 2:     ///< delete a item
                DeleteItem();
                break;
            case 3:     ///< delete container photo
                DeletePhoto();
                break;
            case 4:     ///< make empty list
                MasterList.MakeEmpty();
                break;
            case 0:
                i_Command = 0;
                return;
        }
    }

}


void Application::Replace()
{
    int r_command;

    while(1)
    {
        cout << "\n\n";
        cout << "\t== <REPLACE Menu> =========================\n";
        cout << "\t #  1 | Back to Main menu\n";
        cout << "\t-------------------------------------------\n";
        cout << "\t #  2 | Item\n";
        cout << "\t #  3 | Temp Item to Storage\n";
        cout << "\t #  4 | Location about Container\n";
        cout << "\t-------------------------------------------\n";
        cout << "\t #  0 | Quit\n";
        cout << "\t===========================================\n";

        cout << "\n\t Choose a Commend--> ";
        cin >> r_command;
        cout << endl;

        switch (r_command)
        {
            case 1:     ///< back to main menu
                return;
            case 2:     ///< replace a item
                ReplaceItem();
                break;
            case 3:     ///< move item on temp list to master list
                DequeueFromtItemList();
                break;
            case 4:     ///< replace a info. about container
                ReplaceLocation();
                break;
            case 0:
                i_Command = 0;
                return;
        }
    }

}

void Application::Print()
{
    int p_command;
    while(1)
    {
        cout << "\n\n";
        cout << "\t== <PRINT and SEARCH Menu> ================\n";
        cout << "\t #  1 | Back to Main menu\n";
        cout << "\t-------------------------------------------\n";
        cout << "\t #  2 | All Item\n";
        cout << "\t #  3 | All Temp Item\n";
        cout << "\t #  4 | Photo about Container\n";
        cout << "\t-------------------------------------------\n";
        cout << "\t #  5 | Search Storage with Simple item\n";
        cout << "\t #  6 | Search Storage with Details item\n";
        cout << "\t-------------------------------------------\n";
        cout << "\t #  7 | Search Container with Simple item\n";
        cout << "\t #  8 | Search Container with Details item\n";
        cout << "\t-------------------------------------------\n";
        cout << "\t #  9 | Search item by ID\n";
        cout << "\t # 10 | Search item by Name\n";
        cout << "\t # 11 | Search item by Kinds\n";
        cout << "\t-------------------------------------------\n";
        cout << "\t #  0 | Quit\n";
        cout << "\t===========================================\n";

        cout << "\n\t Choose a Commend--> ";
        cin >> p_command;
        cout << endl;

        switch (p_command)
        {
            case 1:     ///< back to main menu
                return;
            case 2:     ///< display master list
                DisplayAllItem();
                break;
            case 3:     ///< display temp list
                DisplaytItemList();
                break;
            case 4:     ///< display photo about container
                DisplayAllPhoto();
                break;
            case 5:     ///< search Storage and display all container with simple item
                DisplayAllContainer();
                break;
            case 6:     ///< search Storage and display all container with Detail itam
                DisplayAllDetailsContainer();
                break;
            case 7:     ///< search Container and display all simple item
                DisplayAllsItem();
                break;
            case 8:     ///< search Container and display all details item
                DisplayAllDetailsItem();
                break;
            case 9:     ///< search item using ID
                SearchById_BinaryS();
                break;
            case 10:    ///< search item using name
                SearchByName(RetreiveRecordByName());
                break;
            case 11:    ///< search item using kinds
                SearchByKind(RetreiveRecordByKind());
                break;
            case 0:
                i_Command = 0;
                return;
        }
    }
}



int Application::OpenInFile(char *fileName)
{
    i_InFile.open(fileName);

    if(!i_InFile)   return 0;
    else            return 1;
}


int Application::OpenOutFile(char *fileName)
{
    i_OutFile.open(fileName);

    if(!i_OutFile)  return 0;
    else            return 1;
}

int Application::ReadDataFromFile()
{
    int index = 0;
    ItemType item;

    char filename[FILENAMESIZE];
    cout << "\n\tEnter Input File Name : ";
    cin >> filename;

    if(!OpenInFile(filename))
    {
        cout << "\n\t<========File Open FAIL !=========>\n";
        return 0;
    }


    while(!i_InFile.eof())
    {
        item.ReadDataFromFile(i_InFile);
        MasterList.Add(item);
    }

    i_InFile.close();

    cout << "\n\t<=======Road Data SUCCESS !========>\n";
    return 1;
}

int Application::WriteDataToFile()
{
    ItemType item;
    char filename[FILENAMESIZE];
    cout << "\n\tEnter Output File Name : ";
    cin >> filename;

    if(!OpenOutFile(filename))
    {
        cout << "\n\t<========File Open FAIL !=========>\n";
        return 0;
    }

    MasterList.ResetList();
    int length = MasterList.GetLength();
    int curIndex = MasterList.GetNextItem(item);
    while(curIndex < length && curIndex != -1)
    {
        item.WriteDataToFile(i_OutFile);
        curIndex = MasterList.GetNextItem(item);
    }

    i_OutFile.close();
    cout << "\n\t<=======Save Data SUCCESS !========>\n";

    return 1;


}

int Application::AddItem()
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

int Application::AddItem(ItemType &item)
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

int Application::AddtItem()
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

int Application::AddPhoto()
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

int Application::AddLocation()
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

int Application::DeleteItem()
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

int Application::DeletePhoto()
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

int Application::ReplaceItem()
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

int Application::DequeueFromtItemList()
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


int Application::ReplaceLocation()
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

void Application::DisplayAllItem()
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

void Application::DisplaytItemList()
{
    if(TempList.GetnumOfItems() == 0)
        cout << "\n\t<========No Temp Item========>\n";

    TempList.PrinttItemList();
}

void Application::DisplayAllPhoto()
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

void Application::DisplayAllContainer()
{
    StorageType tmpSto;
    tmpSto.SetStoIdFromUser();

    StorageList.Get(tmpSto);
    cout << tmpSto << endl;
    tmpSto.DisplayAllContainer();
}

void Application::DisplayAllDetailsContainer()
{
    StorageType tmpSto;
    tmpSto.SetStoIdFromUser();

    StorageList.Get(tmpSto);
    cout << tmpSto << endl;
    tmpSto.DisplayAllDetailsContainer(MasterList);

}

void Application::DisplayAllsItem()
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

void Application::DisplayAllDetailsItem()
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

int Application::SearchById_BinaryS()
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

ItemType Application::RetreiveRecordByName()
{
    ItemType target;
    target.SetNameFromUser();
    return target;
}

void Application::SearchByName(ItemType target)
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

ItemType Application::RetreiveRecordByKind()
{
    ItemType data;
    data.SetKindFromUser();
    return data;
}

void Application::SearchByKind(ItemType target)
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
