#include <iostream>
#include <istream>
#include <cstdlib>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList list;

    string instructions = "Enter a command:\ninsert | delete | search | print | exit\n";
    string enter_id = "\nEnter ID: ";
    cout << instructions;

    string input;
    while (cin >> input, input != "exit")
    {
        if (input == "insert")
        {
            string idStr, first, last;
            cout << enter_id;
            cin >> idStr;
            cout << "Enter first name: ";
            cin >> first;
            cout << "Enter last name: ";
            cin >> last;
            list.insertNode(atoi(idStr.c_str()), {first, last});
        }
        else if (input == "delete")
        {
            cout << enter_id;
            string s;
            list.deleteNode((cin >> s, atoi(s.c_str())));
        }
        else if (input == "search")
        {
            cout << enter_id;
            string s;
            list.searchNode((cin >> s, atoi(s.c_str())));
        }
        else if(input == "print")
        {
            cout << endl;
            list.print();
        }
        else
        {
            cout << "Invalid command. Please try again." << endl;
        }

        cout << endl << instructions;
    }
}
