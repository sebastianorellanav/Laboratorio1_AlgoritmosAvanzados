#include "structs.h"
#ifndef FILEHANDLING_H
#define FILEHANDLING_H

void writeFile(int width, int length, node *solution);
void readFile(char *fileName, node **list, int *widthMatrix, int *lengthMatrix);

#endif