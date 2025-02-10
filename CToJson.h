#ifndef CTOJSON_H
#define CTOJSON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Node.h"
#include "BST.h"
#include "cJSON.h"

cJSON* BSTtoJson(Node* root);
void saveJson(Node* root);

#endif

