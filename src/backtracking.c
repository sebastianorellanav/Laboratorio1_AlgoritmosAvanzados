#include <stdio.h>
#include <stdlib.h>
#include "../incl/backtracking.h"
#include "../incl/linkedList.h"
#include "../incl/debug.h"

//backtracking algorithm: search the max number of locations possibles and return them
//inputs = width of Matrix, length of Matrix
void backtracking(int width, int length, node *fixedLocations, node **maxSolution){
	//define variables
	int column = -1, maxLocations = 0, row = 0, invalidPosition = 0, numberFixedLocations = 0, iter = 0;
	node *stack = NULL;

	// if exist some fixed locations (positions that cant change)
	if(fixedLocations != NULL){
		// save the positions in stack
		saveSolution(fixedLocations, &stack);
		//save number of fixed locations
		numberFixedLocations = lengthList(fixedLocations);
	}

	//define maximum number of locations
	if (width > length)
		maxLocations = length;
	else
		maxLocations = width;

	// while current row is valid
	while (row >= 0){
		iter++;
		//check if exist a valid column in current row
		do{	
			//move on to next column
			column++;
			//check if a branchOffice can be built in current location
			invalidPosition = checkPosition(stack, row, column);
  		  //while current column is valid and current location isn't avaiable to build
		} while ((column < width) && invalidPosition);
		
		// if current column is valid
		if (column < width){
			// save location in stack
			push(&stack, row, column);

			#ifdef DEBUG
			printCurrent(stack, maxSolution, iter, row, lengthList(stack), row, lengthList(maxSolution));
			#endif
		}

		//move on to the next row
		row++;
		//set column as -1
		column = -1;

		// if current row is out of matrix
		if (row > length-1){
				//if quantity of elements of max Solution is equal to max possible locations
			if( lengthList(*maxSolution) == maxLocations ||
			 	//or if quantity of elements of stack is equal to number of fixed locations
			 	lengthList(stack) == numberFixedLocations||
			 	//or if quantity of elements of stack is equal to cero
			 	lengthList(stack) == 0){
				//stop searching
				row = -1;
			}
			//in other case 
			else{
				//if size of maxSolution < size of stack
				if(lengthList(*maxSolution) < lengthList(stack)){
					//free maxSolution
					freeList(maxSolution);
					//save stack as maxSolution
					saveSolution(stack, maxSolution);
				}
				//go back to the last element in stack
				row = stack->y;
				column = stack->x;
				//and remove it
				pop(&stack);
				#ifdef DEBUG
				printCurrent(stack, maxSolution, iter, row, lengthList(stack), row, lengthList(maxSolution));
				#endif
			}
		}
	}
}

// this function returns true if the position (column, row) is available
// inputs = stack pointer, row , column
int checkPosition(node *stack, int row, int column){
	//for all elements in stack
	while(stack != NULL){
		//if the position (column,row) is not available
		if((stack->x == column) || (stack->y == row) || (abs(column - stack->x) == abs(row - stack->y))){
			return 1;
		}
		//move on to the next element
		stack = stack->next;
	}
	// in other case return true
	return 0;
}

// this function save the current stack in other linked-list
// inputs = source stack, destination List
void saveSolution(node *sourceList, node **destinationList){
	//for all elements in stack
	while(sourceList != NULL){
		//add element to destination List
		push(destinationList, sourceList->y, sourceList->x);
		//move on to the next element
		sourceList = sourceList->next;
	}
}

