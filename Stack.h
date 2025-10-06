#ifndef STACK_H
#define STACK_H

#include "Polyhedra.h"

class Stack {
private:
    Polyhedra arr[50]; // Increased stack size to accommodate more polyhedra
    int top;

public:
    Stack();

    bool isEmpty();

    bool isFull();

    void push(Polyhedra value);

    void pop();
};

#endif
