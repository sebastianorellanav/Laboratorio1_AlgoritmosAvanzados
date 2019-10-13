#include <stdio.h>
#include <stdlib.h>

//struct node of a linked list
typedef struct node{
	int x;
	int y;
	int id;
	struct node* next;
}node;

//function to create a new node of linked list
//inputs = position X, position Y, id 
node* createNode(int posX, int posY, int numId){
	//create a new node
	node *new = NULL;
	//get memory for new node
   	new = (node*)malloc(sizeof(node));
   	//set attributes of new node with parameters
   	new -> x = posX;
   	new -> y = posY;
   	new -> id = numId;
   	new -> next = NULL;
   	//return new node
   	return new;
}

//function to add an element to stack
//inputs = stack (by reference), position X, position Y 
void push(node **stack, int posY, int posX){
	//define lastId
	int lastId = 0;

	//if stack is empty
	if(*stack == NULL){
		//stack pointer points to new node
		*stack = createNode(posX, posY, 1);
	}
	//in other case
	else{
		//create an auxiliar node to point to the rest of stack
		node *aux = *stack;
		//define last id 
		lastId = aux->id;
		lastId++;
		//create a new node and add on top 
		*stack = createNode(posX, posY, lastId);
		//stack pointer points to the rest of stack
		(*stack)->next = aux;
	}
}

//function to remove last element in stack
//inputs = stack (by reference)
void pop(node **stack){
	//create an auxiliar node to save the rest of stack
	node *aux = (*stack)->next;
	//free last element 
	free(*stack);
	//stack pointer = rest of stack
	*stack = aux;
}

//function to read the input file
//inputs = name, list (by reference), width (by reference), length (by reference)
void readFile(char *fileName, node **list, int *widthMatrix, int *lengthMatrix){
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
  		push(list, aux2, aux1);
  	}
  	fclose(archive);
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

//this function free the given list's memory
//inputs = double list pointer (a list by reference)
void freeList(node **list){
	//create an auxiliar (index)
	node *aux = NULL;
	//for all elements in list
	while(*list != NULL){
		aux = *list;
		*list = (*list)->next;
		free(aux);
	}

}

//this function print the given list
void printStack(node *stack){
	if(stack == NULL){
	}
	while(stack != NULL){
		printf("x = %d || y = %d || id = %d\n", stack->x, stack->y, stack-> id);
		stack = stack->next;
	}
}

//backtracking algorithm: search the max number of locations possibles and return them
//inputs = width of Matrix, length of Matrix
void backtracking(int width, int length, node *fixedLocations, node **maxSolution){
	//define variables
	int column = -1, maxLocations = 0, row = 0, invalidPosition = 0, numberFixedLocations = 0;
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
			}
		}
	}
	printStack(*maxSolution);
}

void writeFile(int width, int length, node *solution){
	char **matrix;
	matrix = (char **)malloc (length*sizeof(char *));
	for (int i = 0 ; i < length ; i++)
		matrix[i] = (char *) malloc (width*sizeof(char));
	
	for (int i = 0; i < length; ++i){
		for (int j = 0; j < width; ++j){
			matrix[i][j] = '_';
		}
	}

	FILE *txtOut;
 	txtOut = fopen ("salida.out", "w" );
 	fprintf(txtOut, "%d\n", lengthList(solution));

 	while(solution != NULL){
		matrix[solution->y][solution->x] = 'x';
		fprintf(txtOut, "%d%s%d %s", solution->y, "-", solution->x, " || ");
		solution = solution->next;
	}

	fprintf(txtOut, "\n\n");

	for (int i = 0; i < length; ++i){
		for (int j = 0; j < width; ++j){
			fprintf(txtOut, "%c%c", matrix[i][j], ' ');
		}
		fputc('\n', txtOut);
	}

 	fclose(txtOut);

}

int main(int argc, char *argv[]){
	/*if (argc == 1){
		printf("Error: Faltan parámetros.\nUso: lexico.exe archivo_entrada archivo_salida\n\n");
		return 0;
	}
	if (argc == 2){
		printf("Error: Falta parámetro.\nUso: lexico.exe archivo_entrada archivo_salida\n\n");
		return 0;
	}
	if (argc >= 4){
		printf("Error: Demasiados parámetros.\nUso: lexico.exe archivo_entrada archivo_salida\n\n");
		return 0;
	}*/

	//define variables
	int widthMatrix = 0;
	int lengthMatrix = 0;
	char *fileName = argv[1];
	node *fixedLocations = NULL;
	node *maxSolution = NULL;
	
	//read input file
	readFile(fileName, &fixedLocations,  &widthMatrix, &lengthMatrix);

    //search the solution
    backtracking(widthMatrix, lengthMatrix, fixedLocations, &maxSolution);

    //write file with found solution
    writeFile(widthMatrix, lengthMatrix, maxSolution);

    return 0;
	}