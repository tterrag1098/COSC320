#include <iostream>
#include <cstdlib>
#include "Heap.h"

using namespace std;

int main()
{
    Heap heap;

    string instructions = "Enter a command:\ninsert | extract | max | sort | print | exit\n";
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
            heap.insert((cin >> s, atoi(s.c_str())));
        }
        else if (input == "extract")
        {
            cout << heap.extractMax();
        }
        else if (input == "max")
        {
            cout << heap.getMax();
        }
        else if (input == "sort")
        {
            int* sorted = heap.sort();
            cout << "[" << sorted[0];
            for (int i = 1; i < heap.getSize(); i++)
            {
                cout << ", " << sorted[i];
            }
            cout << "]";
            return 0;
        }
        else if(input == "print")
        {
            cout << endl;
            heap.print();
        }
        else
        {
            cout << "Invalid command. Please try again." << endl;
        }

        cout << endl << instructions;
    }
}
