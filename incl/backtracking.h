#include "structs.h"
#ifndef BACKTRACKING_H
#define BACKTRACKING_H

void backtracking(int width, int length, node *fixedLocations, node **maxSolution);
int checkPosition(node *stack, int row, int column);
void saveSolution(node *sourceList, node **destinationList);

#endif