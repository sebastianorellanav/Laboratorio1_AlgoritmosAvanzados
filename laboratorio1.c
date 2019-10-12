#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int x;
	int y;
	int id;
	struct node* next;
}nodo;

node* createNode(int posX, int posY, int numId){
	node *new = NULL;
   	new = (node*)malloc(sizeof(node));
   	new -> x = posX;
   	new -> y = posY;
   	new -> id = numId;
   	new -> next = NULL;
   	return new;
}

//function to add an element to stack
//inputs = stack (by reference), position X, position Y 
void push(node **stack, int posY, int posX){
	if(*stack == NULL){
		*stack = crearNodo(posX, posY, 1, -1);
	}
	else{
		node *aux = *satck;
		*satck = createNode(posX, posY, (aux->id)++);
		*stack -> next = aux;
	}
}

void pop(node **stack){
	node *aux = *stack->next;
	free(*stack);
	*stack = aux;
}

//function to read the input file
//inputs = name, list (by reference), width (by reference), length (by reference)
void readFile(char *fileName, nodo **list, int *widthMatrix, int *lengthMatrix){
	//define variables
	int nextLines = 0, aux1 = 0, aux2 = 0;
	FILE *archive = NULL;

	// open file
  	archive = fopen(fileName, "r");

  	//check if file was opened correctly
  	if(archive == NULL){    
    	printf("  Error: No se ha podido abrir el archivo %s", fileName);
    	exit(1);
  	}

  	// read and save width and long of matrix
  	fscanf(archive, "%d", widthMatrix);
  	fscanf(archive, "%d", lengthMatrix);

  	// read and save the number of next lines
  	fscanf(archive, "%d", &nextLines);

  	// read and save the content of next lines
  	for (int i = 0; i < nextLines; ++i){
  		fscanf(archive, "%d", &aux1);
  		fscanf(archive, "%d", &aux2);
  		push(list, aux1, aux2);
  	}
}

//backtracking algorithm: search the max number of locations possibles and return them
//inputs = width of Matrix, length of Matrix
node *backtracking(int width, int length, node *fixedLocations){
	//define variables
	int column = -1, maxLocations = 0, row = 0;
	node *stack = NULL, *maxSolutions = NULL;
	bool aux = TRUE;

	// if exist some fixed locations (positions that cant change)
	if(fixedLocations != NULL){
		// save the positions in stack
		saveSolution(fixedLocations, stack);
		// free fixed locations
		freeList(&fixedLocations);
	}

	//define maximum number of locations
	if (width > length)
		maxLocations = length;
	else
		maxLocations = width;

	// while current row is valid
	while (row >= 0){
		
		//if current row is occupied by fixed Location
		while(rowNotAvailable(stack, row)){
			//move on to the next row
			row++;
		}

		//do
		do{	
			//move on to next column
			column++;
			//check if a branchOffice can be built in current location
			aux = checkPosition(stack, row, column);
  		  //while current column is valid and current location isn't avaiable to build
		} while ((column < width) && not(aux))
		
		// if current column is valid
		if (column < width){
			// save location in stack
			push(&stack, row, column);
			
			// if current row == last row  or  length of stack == max number of locations
			if (row == length-1 || lengthList(stack) == maxLocations){
				//free maxSolution
				freeList(&maxSolution);
				//save stack as maxSolution
				saveSolution(stack, &maxSolution);

				// finish while
				row = -1;
			}
			// if current row != last row
			else{
				//move on to the next row
				row++;
				//go back before the first column
				column = -1;
			}
		}
		// if current column is not valid 
		else{
			//if size of maxSolution < size of stack
			if(lengthList(maxSolutions) < lengthList(stack)){
				//free maxSolution
				freeList(&maxSolution);
				//save stack as maxSolution
				saveSolution(stack, &maxSolution);
			}
			// remove an element from stack
			pop(&stack);
			//go back to previous row
			row--;
			//if current row is occupied by fixed Location
			while(rowNotAvailable(stack, row)){
				//go back to the preious row
				row--;
			}
		}
	}
	printStack(stack);
	return maxSolution;
}

// this function returns the length of a list
// inputs = list pointer
int lengthList(node *list){
	// if list is empty
	if(list == NULL){
		// length is 0
		return 0;
	}
	//in other case return the id of the last element in stack
	return list->id;
}

// this function returns true if the position (column, row) is available
// inputs = stack pointer, row , column
bool checkPosition(node *stack, int row, int column){
	//for all elements in stack
	while(stack != NULL){
		//if the position (column,row) is not available
		if((stack->x == column) || (stack->y == row) || (abs(column - stack->x) == abs(row - stack->y))){
			return FALSE;
		}
		//move on to the next element
		stack = stack->next;
	}
	// in other case return true
	return TRUE;
}

// this function returns true if the given list is not available to build a location
// inputs = stack pointer, row
bool rowNotAvailable(node *stack, int row){
	// for all elements in stack
	while(stack != NULL){
		// if the row is not available
		if(stack->x == row)
			return TRUE;
	}
	//in other case return false
	return FALSE;
}

// this function save the current stack in other linked-list
// inputs = source stack, destination List
void saveSolution(node *sourceList, node **destinationList){
	//for all elements in stack
	while(sourceList != NULL){
		//add element to destination List
		push(destinationList, sourceList->x, sourceList->y);
		//move on to the next element
		sourceList = sourceList->next;
	}
}

//this function free the given list's memory
//inputs = double list pointer (a list by reference)
void freeList(node **list){
	//create an auxiliar (index)
	node *aux = NULL;
	//for all elements in list
	while(*list != NULL){
		aux = *list;
		*list = *list->next;
		free(aux);
	}

}

//this function print the given list
void printStack(node *stack){
	while(stack != NULL){
		printf("x = %d || y = %d || id = %d\n", stack->x, stack->y, stack-> id);
		stack = stack->next;
	}
}

void main(){
	//define variables
	int widthMatrix = 0;
	int lengthMatrix = 0;
	char *fileName = "entrada.in";
	node *fixedLocations = NULL;
	
	//read input file
	readFile(fileName, &fixedLocations,  &widthMatrix, &lengthMatrix);

    //search the solution
    backtracking(widthMatrix, lengthMatrix, fixedLocations);

    return 0;
	}