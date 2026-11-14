
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void registration()
{
    string username, password;
    string user, pass;

    cout << "\nEnter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    if(username.empty() || password.empty())
    {
        cout << "Fields cannot be empty!";
        return;
    }

    ifstream check("users.txt");

    while(check >> user >> pass)
    {
        if(user == username)
        {
            cout << "\nUsername already exists!";
            check.close();
            return;
        }
    }

    check.close();

    ofstream file("users.txt", ios::app);

    if(!file)
    {
        cout << "File could not be opened!";
        return;
    }

    file << username << " " << password << endl;

    file.close();

    cout << "\nRegistration Successful!";
}

void login()
{
    string username, password;
    string user, pass;

    cout << "\nEnter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream file("users.txt");

    if(!file)
    {
        cout << "\nNo registered users found!";
        return;
    }

    while(file >> user >> pass)
    {
        if(user == username && pass == password)
        {
            cout << "\nLogin Successful!";
            file.close();
            return;
        }
    }

    file.close();

    cout << "\nInvalid Username or Password!";
}

int main()
{
    int choice;

    cout << "\n===== LOGIN AND REGISTRATION SYSTEM =====";

    cout << "\n1. Registration";
    cout << "\n2. Login";
    cout << "\n3. Exit";

    cout << "\nEnter your choice: ";
    cin >> choice;

    if(choice == 1)
    {
        registration();
    }
    else if(choice == 2)
    {
        login();
    }
    else if(choice == 3)
    {
        cout << "\nProgram Exited!";
    }
    else
    {
        cout << "\nInvalid Choice!";
    }

    return 0;
}

