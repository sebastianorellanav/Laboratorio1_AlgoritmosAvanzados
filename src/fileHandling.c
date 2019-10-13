#include <stdio.h>
#include <stdlib.h>
#include "../incl/fileHandling.h"
#include "../incl/backtracking.h"
#include "../incl/linkedList.h"

//function to write results in file
//inputs = width matrix, length matrix, solution list
void writeFile(char *fileName, int width, int length, node *solution){
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
 	txtOut = fopen (fileName, "w" );
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