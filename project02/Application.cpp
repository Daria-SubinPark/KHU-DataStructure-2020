//
// Created by 박수빈 on 2020/05/01.
//

#include "pch.h"
#include "Application.h"

Application::Application() { i_Command = 0; }

Application::~Application() {}

void Application::LoginRun()
{
   while(1)
    {
        cout << "\n\n";
        cout << "\n\t== <Login> ================================\n";
        cout << "\t Enter your id and password please (Quit: 0)";
        cout << "\n\t===========================================\n";

        UserType user;
        bool check;
        int fail = 0;
        user.SetIdFromUser();
        if(user.GetId() == "0")
            return;
        user.SetPasswordFromUser();

        if(user.GetId() == "admin" && user.GetPassword() == "admin")
            AdminRun();
        else
        {
            UserList.RetrieveItem(user, check);
            if(check)
            {
                CurrentUser = user;
                Run();
            }
            else
            {
                fail++;
                if(fail < 3)
                {
                    cout << "\t<You've entered a wrong ID or password " << fail << "...>\n";
                    cout << "\t<If you enter it wrong more than three times, the program will end>\n";
                }
                else
                {
                    cout << "\t<You've entered a wrong ID or password " << fail << "...>\n";
                    cout << "\t<The program exits.>\n";
                    return;
                }
            }
        }
    }
}

void Application::AdminRun()
{
    while(1)
    {
        int command;

        cout << "\n\n";
        cout << "\n\t== <Admin Menu> ============================\n";
        cout << "\t #  1 | ADD user\n";
        cout << "\t #  2 | DELETE user\n";
        cout << "\t #  3 | REPLACE user\n";
        cout << "\t #  4 | SEARCH user \n";
        cout << "\t #  5 | PRINT user\n";
        cout << "\t-------------------------------------------\n";
        cout << "\t #  0 | Quit\n";
        cout << "\t===========================================\n";

        cout << "\n\t Choose a Commend--> ";
        cin >> command;
        cout << endl;

        switch(command)
        {
            case 1:                 ///< Add user.
                AddUser();
                break;
            case 2:                 ///< Delete user.
                DeleteUser();
                break;
            case 3:                 ///< Update user data.
                ReplaceUser();
                break;
            case 4:                 ///< Search user by id.
                SearchUserById();
                break;
            case 5:                 ///< Print all user in user list.
                PrintAllUser();
                break;
            case 0:
                return;
            default:
                cout << "\tIllegal selection...\n";
                break;
        }
    }
}

void Application::AddUser()
{
    UserType user;
    bool check;
    user.SetUserFromUser();
    UserList.RetrieveItem(user, check);
    if(check)
    {
        cout << "\n\t<====ALREADY has same ID !====>\n";
        return;
    }

    int len = UserList.GetLength();
    UserList.Add(user);
    if(len == UserList.GetLength())
    {
        cout << "\n\t<=======Add User FAIL=========>\n";
        return;
    }

    cout << "\n\t<=======Add User SUCCESS======>\n";
}

void Application::DeleteUser()
{
    UserType user;
    bool check;
    user.SetIdFromUser();
    UserList.RetrieveItem(user, check);
    if(check)
    {
        UserList.DeleteItem(user);
        int len = UserList.GetLength();
        UserList.Add(user);
        if(len == UserList.GetLength())
        {
            cout << "\n\t<=======DELETE User FAIL======>\n";
            return;
        }
        cout << "\n\t<=====DELETE User SUCCESS=====>\n";
        return;
    }

    cout << "\n\t<===Can't found ID on list !==>\n";
}

void Application::ReplaceUser()
{
    UserType user;
    bool check;
    user.SetIdFromUser();
    UserList.RetrieveItem(user, check);
    if(check)
    {
        user.SetPasswordFromUser();
        user.SetNameFromUser();
        if(UserList.UpdateItem(user))
        {
            cout << "\n\t<=====Update User SUCCESS=====>\n";
            return;
        }
        cout << "\n\t<=======Update User FAIL======>\n";
        return;
    }
    cout << "\n\t<===Can't found ID on list !==>\n";
}

void Application::SearchUserById()
{
    UserType user;
    bool check;
    user.SetIdFromUser();

    UserList.RetrieveItem(user, check);
    if(check)
    {
        cout << "\n\t<============I FOUND ITEM !==========>\n";
        cout << user;
        cout << "\n\t<====================================>\n";
        return;
    }
    cout << "\t<========I CAN'T FIND ITEM !==========>" << endl;
}


void Application::PrintAllUser()
{
    if(!UserList.IsEmpty())
        UserList.PrintTree(cout);
    else
        cout << "\n\t<===========List is Empty============>\n" << endl;
}


/// User's Main menu

void Application::DisplayCurrentUser()
{
    if(!CurrentUser.GetId().empty())
    {
        cout << "\n\t== <USER> ==================================\n";
        cout << "\t ID   | " << CurrentUser.GetId() << endl;
        cout << "\t Name | " << CurrentUser.GetName() << endl;
    }
}

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
    DisplayCurrentUser();
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
        DisplayCurrentUser();
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
        DisplayCurrentUser();
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
                UserList.MakeEmpty();
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
        DisplayCurrentUser();
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
        DisplayCurrentUser();
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
                SearchByName();
                break;
            case 11:    ///< search item using kinds
                SearchByKind();
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
        UserList.Add(CurrentUser);
    }

    i_InFile.close();

    cout << "\n\t<=======Road Data SUCCESS !========>\n";
    return 1;
}

int Application::WriteDataToFile()
{
    UserType user;
    char filename[FILENAMESIZE];
    cout << "\n\tEnter Output File Name : ";
    cin >> filename;

    if(!OpenOutFile(filename))
    {
        cout << "\n\t<========File Open FAIL !=========>\n";
        return 0;
    }

    /*
    UserList.MakeEmpty();
    int length = UserList.GetLength();
    int curIndex = UserList.GetNextItem(item);
    while(curIndex < length && curIndex != -1)
    {
        item.WriteDataToFile(i_OutFile);
        curIndex = MasterList.GetNextItem(item);
    }

    i_OutFile.close();
    cout << "\n\t<=======Save Data SUCCESS !========>\n";
    */
    return 1;


}

int Application::AddItem()
{
    if(CurrentUser.AddItem())
    {
        UserList.UpdateItem(CurrentUser);
        return 1;
    }

    return 0;
}


int Application::AddtItem()
{
    if(CurrentUser.AddtItem())
    {
        UserList.UpdateItem(CurrentUser);
        return 1;
    }
    return 0;
}

int Application::AddPhoto()
{
    if(CurrentUser.AddPhoto())
    {
        UserList.UpdateItem(CurrentUser);
        return 1;
    }
    return 0;
}

int Application::AddLocation()
{
    if(CurrentUser.AddLocation())
    {
        UserList.UpdateItem(CurrentUser);
        return 1;
    }
    return 0;
}

int Application::DeleteItem()
{
    if(CurrentUser.DeleteItem())
    {
        UserList.UpdateItem(CurrentUser);
        return 1;
    }
    return 0;
}

int Application::DeletePhoto()
{
    if(CurrentUser.DeletePhoto())
    {
        UserList.UpdateItem(CurrentUser);
        return 1;
    }
    return 0;
}

int Application::ReplaceItem()
{
    if(CurrentUser.ReplaceItem())
    {
        UserList.UpdateItem(CurrentUser);
        return 1;
    }
    return 0;
}

int Application::DequeueFromtItemList()
{
    if(CurrentUser.DequeueFromtItemList())
    {
        UserList.UpdateItem(CurrentUser);
        return 1;
    }
    return 0;
}


int Application::ReplaceLocation()
{
    if(CurrentUser.ReplaceLocation())
    {
        UserList.UpdateItem(CurrentUser);
        return 1;
    }
    return 0;
}

void Application::DisplayAllItem()
{
    CurrentUser.DisplayAllItem();
}

void Application::DisplaytItemList()
{
    CurrentUser.DisplaytItemList();
}

void Application::DisplayAllPhoto()
{
    CurrentUser.DisplayAllPhoto();
}

void Application::DisplayAllContainer()
{
    CurrentUser.DisplayAllContainer();
}

void Application::DisplayAllDetailsContainer()
{
    CurrentUser.DisplayAllDetailsContainer();
}

void Application::DisplayAllsItem()
{
    CurrentUser.DisplayAllsItem();
}

void Application::DisplayAllDetailsItem()
{
    CurrentUser.DisplayAllDetailsItem();

}

int Application::SearchById_BinaryS()
{
    if(CurrentUser.SearchById_BinaryS())
        return 1;
    return 0;
}

void Application::SearchByName()
{
    CurrentUser.SearchByName(CurrentUser.RetreiveRecordByName());
}

void Application::SearchByKind()
{
    CurrentUser.SearchByKind(CurrentUser.RetreiveRecordByKind());
}


