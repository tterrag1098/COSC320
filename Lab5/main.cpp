#include <iostream>
#include "BST.h"

using namespace std;

int main() {
    BST bst;

    string instructions = "Enter a command:\ninsert(a) | delete | print | exit\n";
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
            bst.insert((cin >> s, atoi(s.c_str())));
        }
        else if (input == "inserta")
	{
	    cout << enter_id;
	    string s;
	    cin >> s;
	    while (s != "x")
	    {
	      bst.insert(atoi(s.c_str()));
	      cout << enter_id;
	      cin >> s;
	    }
	}
        else if (input == "delete")
        {
            cout << enter_id;
	    string s;
	    bst.del((cin >> s, atoi(s.c_str())));
        }
        else if(input == "print")
        {
	    l:
            cout << "\nEnter type:\nio | preo | posto | a\n";
	    string type;
	    cin >> type;
	    
	    if (type == "a")
	    {
	      bst.print();
	    }
	    else if (type == "io")
	    {
	      bst.inOrder();
	    }
	    else if (type == "preo")
	    {
	      bst.preOrder();
	    }
	    else if (type == "posto")
	    {
	      bst.postOrder();
	    }
	    else
	    {
	      cout << "Invalid type. Please try again." << endl;
	      goto l; //hehehehe
	    }
        }
        else
        {
            cout << "Invalid command. Please try again." << endl;
        }

        cout << endl << instructions;
    }

}
