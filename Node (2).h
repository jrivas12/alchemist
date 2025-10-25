// Node.h
#ifndef NODE_H
#define NODE_H
#include <string>


struct Node {
    std::string description;
    bool gem;
    bool sword;
    bool chest;
    bool cave;
    Node* north;
    Node* south;
    Node* east;
    Node* west;

    Node(std::string desc);
};

#endif 