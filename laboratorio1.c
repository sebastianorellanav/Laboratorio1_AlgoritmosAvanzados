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

//place the locations that cant change in the matrix
//inputs = int matrix, list
void placeFixedLocations(int **matrix, nodo *list){
	node *aux = list;
	while(aux != NULL){
		matrix[aux->y][aux->x] = 2;
	}
}

//backtracking algorithm: search the max number of locations possibles and return them
//inputs = int matrix, width of Matrix, length of Matrix
void backtracking(int** matrix, int width, int length){
	//define variables
	int column = -1, maxLocations = 0, row = 0;
	node *stack = NULL, *maxSolutions = NULL;
	bool aux = TRUE;

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
				freeList(maxSolution);
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
				freeList(maxSolution);
				//save stack as maxSolution
				saveSolution(stack, &maxSolution);
			}
			pop(&stack);
			//go back to previous row
			row--;
			while(rowNotAvailable(stack, row)){
				row--;
			}
		}
	}
	printStack(stack);
}

int lengthList(node *list){
	if(list == NULL){
		return 0;
	}
	return list->id;
}

bool checkPosition(node *stack, int row, int column){
	while(stack != NULL){
		if((stack->x == column) || (stack->y == row) || (abs(column - stack->x) == abs(row - stack->y))){
			return FALSE;
		}
		stack = stack->next;
	}
	return TRUE;
}

bool rowNotAvailable(node *stack, int row){
	while(stack != NULL){
		if(stack->x == row)
			return TRUE;
	}
	return FALSE;
}

void saveSolution(node *sourceList, node **destinationList){
	while(sourceList != NULL){
		push(destinationList, sourceList->x, sourceList->y);
		sourceList = sourceList->next;
	}
}

void freeList(node **list){
	node *aux = NULL;

	while(*list != NULL){
		aux = *list;
		*list = *list->next;
		free(aux);
	}

}
void printStack(node *stack){
	while(stack != NULL){
		printf("x = %d || y = %d || id = %d\n", stack->x, stack->y, stack-> id);
		stack = stack->next;
	}
}


/*
X = matriz[n][n]
X[1] = 0
k = 1
mientras k > 0
	repetir
		X[k] = X[k] + 1
	(hasta X[k] > n) o (colocar(X[k],k,X))
	si (X[k] <= n) entonces
		si (k = n) entonces escribir(X)
		si no k = k+1
			X(k) = 0
	si no k = k-1

	funcion colocar = determina si se puede o no colcoar la reinas
*/


void main(){
	//define variables
	int widthMatrix = 0;
	int lengthMatrix = 0;
	char *fileName = "entrada.in";
	node *list = NULL;
	
	//read input file
	readFile(fileName, &list,  &widthMatrix, &lengthMatrix);

	//create matrix
	matrix = (int**)malloc(lengthMatrix*sizeof(int*));
	for (int i = 0 ; i < lengthMatrix ; i++)
    	matrix[i] = (int *) malloc (widthMatrix*sizeof(int));

    //inicializate matrix with 0s
    for (int i = 0; i < lengthMatrix; ++i)    {
    	for (int j = 0; i < widthMatrix; ++j){
    		matrix[i][j] = 0;
    	}
    }

    //placed the location that cant change 
    placeFixedLocations(matriz, lista);

    //search the solution
    backtracking(matrix, widthMatrix, lengthMatrix);

    return 0;
	}