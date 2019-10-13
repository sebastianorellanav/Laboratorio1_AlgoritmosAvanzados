#include "structs.h"
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

node* createNode(int posX, int posY, int numId);
void push(node **stack, int posY, int posX);
void pop(node **stack);
int lengthList(node *list);
void freeList(node **list);

#endif