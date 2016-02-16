#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList
{
    public:
        LinkedList();
        ~LinkedList();
        void insertNode(int id, StudentInfo info = StudentInfo{"Unknown", "Unknown"});
        void deleteNode(int id);
        void print();
        void searchNode(int id);
    private:
        Node* list;
        Node* createNode(int id);
        Node* searchLocation(int id, bool eq);
};

#endif // LINKEDLIST_H
