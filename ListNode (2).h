//ListNode.h
#ifndef LISTNODE_H
#define LISTNODE_H

#include <cstddef>

struct ListNode
{
    double value;
    ListNode *next;

    ListNode(double value1, ListNode *next1 = NULL);
};

#endif