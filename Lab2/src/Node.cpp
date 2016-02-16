#include "Node.h"
#include <iostream>

Node::Node(int id) : id(id){}

Node::~Node(){}

void Node::print()
{
    std::cout << "ID: " << id << " -> ";
    info.print();
}

void StudentInfo::print()
{
    std::cout << "Name: " << first_name << " " << last_name << std::endl;
}
