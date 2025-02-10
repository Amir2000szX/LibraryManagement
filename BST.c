#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Node.h"
#include "BST.h"
#include "cJSON.h"
#include "CToJson.h"

Book* makeBook(unsigned long long int ISBN,char Title[],char Author[],unsigned short int Year){
    Book* book = (Book*)malloc(sizeof(Book));
    book->ISBN = ISBN;
    strcpy(book->Title , Title);
    strcpy(book->Author, Author);
    book->Year = Year;
    return book;
}
Node* makeNode(Book* book,Node* parent){
    struct Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->book = book;
    NewNode->parent = parent;
    NewNode->rightChild = NULL;
    NewNode->leftChild = NULL;
    return NewNode;
}

void insert(Book* book,Node* rootNode){

    if(book->ISBN > rootNode->book->ISBN && rootNode->rightChild != NULL){
        insert(book,rootNode->rightChild);
    }
    else if(book->ISBN < rootNode->book->ISBN && rootNode->leftChild != NULL){
        insert(book,rootNode->leftChild);
    }
    else if(book->ISBN > rootNode->book->ISBN && rootNode->rightChild == NULL){
        Node* newRightChild = makeNode(book,rootNode);
        rootNode->rightChild = newRightChild;  
    }
    else if(book->ISBN < rootNode->book->ISBN && rootNode->leftChild == NULL){
        Node* newLeftChild = makeNode(book,rootNode);
        rootNode->leftChild = newLeftChild;
    }
    else{
        printf("invalid paramater");
    }
}
Node* search(Node* root,unsigned long long int key){
    if (root == NULL){
        return NULL;
    }
    else if(root->book->ISBN == key){
        return root;
    }
    else if(key > root->book->ISBN){
        return search(root->rightChild,key);
    }
    else if (key < root->book->ISBN){
        return search(root->leftChild,key);
    }
}
Node* maximum(Node* root){
    if(root->rightChild == NULL){
        return root;
    }
    else{
        return maximum(root->rightChild);
    }
}
Node* minimum(Node* root){
    if (root->leftChild == NULL){
        return root;
    }
    else {
        return minimum(root->leftChild);
    }
}
Node* successor(Node* node) {
    if (node->rightChild != NULL)
        return minimum(node->rightChild);
    
    Node* parent = node->parent;
    while (parent != NULL && node == parent->rightChild) {
        node = parent;
        parent = parent->parent;
    }
    return parent;
}
bool isALeaf(Node* node){
    if (node->rightChild == NULL && node->leftChild == NULL){
        return true;
    }
    else{
        return false;
    }
}
Node* del(unsigned long long int key,Node* root){
    struct Node* findedNode = search(root,key);
    struct Node* findedNodeParent = findedNode->parent;
    
    if (findedNode == NULL){
        printf("this key doesnt exists in this Tree");
        return NULL;
    }
    else if (findedNodeParent == NULL) {
        struct Node* newRoot = successor(findedNode);
        del(newRoot->book->ISBN,findedNode);
        newRoot->rightChild = findedNode->rightChild;
        newRoot->leftChild = findedNode->leftChild;
        free(findedNode->book);
        free(findedNode);
        return newRoot;
}
    else if(isALeaf(findedNode) == true){
        if(findedNodeParent->rightChild->book->ISBN == findedNode->book->ISBN){
            findedNodeParent->rightChild = NULL;
        }
        else{
            findedNodeParent->leftChild = NULL;
        }
        free(findedNode->book);
        free(findedNode);
        return root;
    }
    else{
        struct Node* successorNode = successor(findedNode);
        if(findedNodeParent->rightChild->book->ISBN == findedNode->book->ISBN){
            findedNodeParent->rightChild = successorNode;
            successorNode->parent = findedNodeParent;
        }
        else{
            findedNode->leftChild = successorNode;
            successorNode->parent = findedNodeParent;
        }
        successorNode->leftChild = findedNode->leftChild;
    }
    free(findedNode->book);
    free(findedNode);
    return root;
}