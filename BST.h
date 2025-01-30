#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Book{
    unsigned long long int ISBN;
    char Title[100];
    char Author[100];
    unsigned short int Year;
}Book;

typedef struct Node{
    Book book;
    Node* parent;
    Node* leftChild;
    Node* rightChild;
}Node;
Book* makeBook(unsigned long long int ISBN,char Title[],char Author[],unsigned short int Year);
Node* makeNode(Book book,Node* parent);
void insert(Book book,Node* rootNode);
Node* search(Node* key,Node* root);
Node* maximum(Node* root);
Node* minimum(Node* root);
Node* successor(Node* root);
bool isALeaf(Node* node);
Node* del(Node* key,Node* root);

#endif