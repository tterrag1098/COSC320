#ifndef NODE_H
#define NODE_H

#include <string>

// Holder for name info with easy print method
struct StudentInfo
{
    std::string first_name, last_name;
    void print();
};

class Node
{
    friend class LinkedList;
    private:
        Node(int id);
        ~Node();
        int id;
        StudentInfo info;
        Node* next;
        void print();
};

#endif // NODE_H
