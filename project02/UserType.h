#pragma once

class UserType
{
private:
    string id;
    string password;
    string name;

public:
    UserType();

    ~UserType();

    string GetId() const;
    string GetPassword() const;
    string GetName() const;

    void SetId(string _id);
    void SetPassword(string _pass);
    void SetName(string _name);
    void SetUser(string _id, string _pass, string _name);

    void DisplayIdOnScreen();
    void DisplayPasswordOnScreen();
    void DisplayNameOnScreen();
    void DisplayUserOnScreen();

    void SetIdFromUser();
    void SetPasswordFromUser();
    void SetNameFromUser();
    void SetUserFromUser();


    bool operator==(const UserType& _user)
    {
        return (this->GetId() == _user.id);
    }

    bool operator>(const UserType& _user)
    {
        return (this->GetId() > _user.id);
    }
    bool operator<(const UserType& _user)
    {
        return (this->GetId() < _user.id);
    }
    UserType& operator=(const UserType& _user)
    {
        this -> SetId(_user.GetId());
        return *this;
    }

    friend ostream& operator<<(ostream& os, const UserType& _item)
    {
        os << "\tID       : " << _item.GetId() << endl;
        os << "\tName     : " << _item.GetName() << endl;

        return os;
    }

};

