#include <iostream>
#include <istream>
#include <cstdlib>
#include "src/LinkedList.cpp"

using namespace std;

// Holder for name info with easy print method
struct StudentInfo : public Printable
{
    string first_name, last_name;
    void print() override;
};

void StudentInfo::print()
{
    cout << first_name << " " << last_name << endl;
}

int main()
{
    LinkedList<StudentInfo> list;

    string instructions = "Enter a command:\ninsert | delete | search | print | exit\n";
    string enter_id = "\nEnter ID: ";
    cout << instructions;

    string input;
    // Read input until "exit" is read, then terminate
    while (cin >> input, input != "exit")
    {
        if (input == "insert")
        {
            StudentInfo info;
            string idStr;
            cout << enter_id;
            cin >> idStr;
            cout << "Enter first name: ";
            cin >> info.first_name;
            cout << "Enter last name: ";
            cin >> info.last_name;
            // Used throughout, atoi(foo.c_str()) converts a string into an int
            list.insertNode(atoi(idStr.c_str()), info);
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
