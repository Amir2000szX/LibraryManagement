#include <stdio.h>
#include <stdlib.h>
#include "Node.h"
#include "BST.h"
#include "cJSON.h"
#include "CToJson.h"

cJSON* BSTtoJson(Node* root){
    if (root->leftChild == NULL && root->rightChild == NULL){
        cJSON *jsonfile = cJSON_CreateObject();
        cJSON_AddNumberToObject(jsonfile,"ISBN",root->book->ISBN);
        cJSON_AddItemToObject(jsonfile,"leftChild",cJSON_CreateNull());
        cJSON_AddItemToObject(jsonfile,"rightChild",cJSON_CreateNull());
        return jsonfile;
    }
    else {
        cJSON *jsonfile = cJSON_CreateObject();
        if(root->rightChild != NULL && root->leftChild == NULL){
            cJSON_AddNumberToObject(jsonfile,"ISBN",root->book->ISBN);
            cJSON_AddItemToObject(jsonfile,"leftChild",cJSON_CreateNull());
            cJSON_AddItemToObject(jsonfile,"rightChild",BSTtoJson(root->rightChild));
            return jsonfile;
        }
        else if(root->rightChild == NULL && root->leftChild != NULL){
            cJSON_AddNumberToObject(jsonfile,"ISBN",root->book->ISBN);
            cJSON_AddItemToObject(jsonfile,"rightChild",cJSON_CreateNull());
            cJSON_AddItemToObject(jsonfile,"leftChild",BSTtoJson(root->leftChild));
            return jsonfile;
        }
        else {
            cJSON_AddNumberToObject(jsonfile,"ISBN",root->book->ISBN);
            cJSON_AddItemToObject(jsonfile,"rightChild",BSTtoJson(root->rightChild));
            cJSON_AddItemToObject(jsonfile,"leftChild",BSTtoJson(root->leftChild));
            return jsonfile;
        }
    }
    
}
void saveJson(Node* root){
    cJSON* endingJson =BSTtoJson(root);
    
    char* jsonString = cJSON_Print(endingJson);
    FILE* file = fopen("BST.json","w");
    if (file == NULL) {
        perror("Failed to open file");
    }
    fputs(jsonString, file);
    fclose(file);

    cJSON_Delete(endingJson);
    free(jsonString);
    
}

