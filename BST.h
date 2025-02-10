#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Book.h"
#include "Node.h"

extern void insert(Book* book, Node* rootNode);
extern Node* search(Node* root, unsigned long long int key);
extern Node* maximum(Node* root);
extern Node* minimum(Node* root);
extern Node* successor(Node* root);
extern bool isALeaf(Node* node);
extern Node* del(unsigned long long int key, Node* root);

#endif // BST_H
