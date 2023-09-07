#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

// global variables
string fname, lname, phone_number;
// functions
void add_contact();
void search_contact();
void help();
void self_exit();
bool check_digits(string);
bool check_numbers(string);

int main()
{

    short int choice;
    system("cls");
    system("color 0A");
    cout << "\n\n\n\t\tContact Management.";
    cout << "\n\n\t1. Add Contact\n\t2. Search Contact \n\t3. Help \n\t4. Exit\n\t> ";
    cin >> choice;
    
    switch (choice)
    {
    case 1:
        add_contact();
        break;
    case 2:
        search_contact();
        break;
    case 3:
        help();
        break;
    case 4:
        self_exit();
        break;
    default:
        cout << "\n\tInvalid Input" << endl;
        cout << "\n\tPress any Key to Continue..";
        getch();
        main();
    }

    return 0;
}

void self_exit()
{
    system("cls");
    cout << "\n\n\tThank you!!!";
    exit(1);
}
void help()
{
    system("cls");
    cout << "\nThis program is develop by Jeevan Thote" << endl;
    cout << "\nFor more information please visit my website https://jeevan48.github.io/Portfolio/" << endl;
}

void add_contact()
{
    ofstream phone("number.txt", ios::app);
    system("cls");
    cout << "\n\nEnter First Name : ";
    cin >> fname;
    cout << "\n\nEnter Last Name : ";
    cin >> lname;
    cout << "\n\nEnter 10-digit Phone Number : ";
    cin >> phone_number;

    if (check_digits(phone_number) == true)
    {
        if (check_numbers(phone_number) == true)
        {
            if (phone.is_open())
            {
                phone << fname << " " << lname << " " << phone_number << endl;
                cout << "\n\t Contact Saved Successfully!";
            }
            else
            {
                cout << "\n\t Error in Saving the Data, Please try again later...";
            }
            
        }
        else
        {
            cout<<"\n\tPhone Number Must Contain Only Digits!";
        }
    
    }
    else
    {
        cout << "\n\tA Phone Number must be of 10 digits";
    }
    phone.close();
}

void search_contact()
{
    bool found=false;
    fstream myfile("number.txt");
    string keyword;
    cout<<"\n\tEnter Name to Search : ";
    cin>>keyword;
    // for(int i=0;i<keyword.size();i++)
    // keyword[i]=tolower(keyword[i]);
    while(myfile>>fname >> lname >> phone_number)
    {
        if(keyword==fname || keyword ==lname)
        {
            system("cls");
            cout<<"\n\n\t\tContact Details..";
            cout<<"\n\tFirst Name : "<<fname;
            cout<<"\n\tLast Name : "<<lname;
            cout<<"\n\tPhone Number : "<<phone_number;
            found=true;
            break;
        }
    }
    if(found==false)
    cout<<"\n\tNo such Contact found..";
}

bool check_digits(string x)
{
    if (x.length() == 10)
        return true;
    else
    return false;
}
bool check_numbers(string x)
{
    bool check = true;
    for (int i = 0; i < x.length(); i++)
    {
        if (!(int(x[i]) >= 48 && int(x[i]) <= 57))
        {
            check = false;
            break;
        }
    }
    if (check == true)
        return true;
    else
        return false;
}