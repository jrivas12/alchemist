#ifndef QUEUE_H
#define QUEUE_H

#include "Polyhedra.h"

class Queue {
private:
    Polyhedra arr[50]; // Increased queue size to accommodate more polyhedra
    int front, rear;

public:
    Queue();

    bool isEmpty();

    bool isFull();

    void push(Polyhedra value);

    void pop();
};

#endif
