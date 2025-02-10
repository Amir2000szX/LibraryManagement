#ifndef NODE_H
#define NODE_H

#include "Book.h"

typedef struct Node {
    Book* book;
    struct Node* parent;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

extern Node* makeNode(Book* book, Node* parent);

#endif // NODE_H