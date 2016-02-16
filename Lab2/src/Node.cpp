#include "Node.h"
#include <iostream>

Node::Node(int id) : id(id){}

Node::~Node(){}

// Print the ID and the student info
void Node::print()
{
    std::cout << "ID: " << id << " -> ";
    info.print();
}

// Print first and last name
void StudentInfo::print()
{
    std::cout << "Name: " << first_name << " " << last_name << std::endl;
}
