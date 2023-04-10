#include <iostream>
#include "course.h"
using namespace std;
class Menu
{
public:
    int ch, choice;
    Menu()
    {
        ch = 0;
    }
    void Show()
    {

        while (ch == 0)
        {

            system("clear");
            cout << "Enter Your Choice :\n"
                    "1)Best Policy\n"
                    "2)All In One\n"
                    "0)Exit\n"
                    "Your Choice :";
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                int ch = 0;

                while (ch == 0)
                {
                    cin.ignore();
                    system("clear");
                    cout << "Check Data As :\n1)Whole Class \n2)Roll Nuber Wise\n0)Exit\nYour Choice :";
                    int choice;
                    cin >> choice;
                    switch (choice)
                    {
                    case 1:
                    {
                        Result A;
                        A.result(1);
                        A.display();
                        break;
                    }
                    case 2:
                    {
                        Result A;
                        A.result(1);
                        A.specific_data();
                        break;
                    }
                    case 0:
                    {
                        ch = 1;
                        break;
                    }
                    default:
                    {
                        cout << "\nInvalid Choice!\n";
                        break;
                    }
                    }
                    if (ch != 1)
                    {
                        cout << "\nPress Enter To Continue...";
                        cin.ignore();
                        
                    }
                }
                ch = 0;
                break;
            }
            case 2:
            {

                while (ch == 0)
                {
                    cin.ignore();
                    system("clear");
                    cout << "Check Data As :\n1)Whole Class \n2)Roll Nuber Wise\n0)Exit\nYour Choice :";
                    int choice;
                    cin >> choice;
                    switch (choice)
                    {
                    case 1:
                    {
                        Result A;
                        A.result(0);
                        A.display();
                        break;
                    }
                    case 2:
                    {
                        Result A;
                        A.result(0);
                        A.specific_data();
                        break;
                    }
                    case 0:
                    {
                        ch = 1;
                        break;
                    }
                    }
                    if (ch != 1)
                    {
                        cout << "\nPress Enter To Continue...";
                        cin.ignore();
                        
                    }
                }
                ch = 0;
                break;
            }

            case 0:
            {
                ch = 1;
                break;
            }
            default:
            {
                cout << "\nInvalid Choice!\n";
            }
            }
            if (ch != 1)
            {
                cout << "\nPress Enter To Continue...";
                cin.ignore();
                cin.ignore();
            }
        }
    }
};