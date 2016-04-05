#include <cstdlib>
#include <cstddef>
#include "Hashtable.h"

using namespace std;

int main() {
    Hashtable table(20);

    string instructions = "Enter a command:\ninsert(a) | delete | search | print | exit\n";
    string enter_id = "\nEnter ID: ";
    cout << instructions;

    string input;
    // Read input until "exit" is read, then terminate
    while (cin >> input, input != "exit")
    {
        if (input == "insert")
        {
            cout << enter_id;
            string s;
            // Used throughout, atoi(foo.c_str()) converts a string into an int
            table.insert((cin >> s, atoi(s.c_str())));
        }
        else if (input == "inserta")
	{
	    cout << enter_id;
	    string s;
	    cin >> s;
	    while (s != "x")
	    {
	      table.insert(atoi(s.c_str()));
	      cout << enter_id;
	      cin >> s;
	    }
	}
        else if (input == "delete")
        {
            cout << enter_id;
	    string s;
	    table.remove((cin >> s, atoi(s.c_str())));
        }
        else if (input == "search")
	{
	    cout << enter_id;
	    string s;
	    table.search((cin >> s, atoi(s.c_str())));
	}
        else if(input == "print")
        {
	    table.print();
	    cout << endl;
        }
        else
        {
            cout << "Invalid command. Please try again." << endl;
        }

        cout << endl << instructions;
    }

}
