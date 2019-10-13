#include <stdio.h>
#include <stdlib.h>
#include "../incl/fileHandling.h"
#include "../incl/backtracking.h"
#include "../incl/linkedList.h"
#include "../incl/debug.h"
#include "../incl/colors.h"

//function main
int main(int argc, char *argv[]){
	if (argc == 1){
		printf("Error: Faltan parametros.\nUso: ejecutable.exe archivo_entrada archivo_salida\n\n");
		return 0;
	}
	if (argc == 2){
		printf("Error: Falta parametro.\nUso: ejecutable.exe archivo_entrada archivo_salida\n\n");
		return 0;
	}
	if (argc >= 4){
		printf("Error: Demasiados parametros.\nUso: ejecutable.exe archivo_entrada archivo_salida\n\n");
		return 0;
	}

	//define variables
	int widthMatrix = 0;
	int lengthMatrix = 0;
	char *inputFileName = argv[1];
	char *outputFileName = argv[2];
	node *fixedLocations = NULL;
	node *maxSolution = NULL;
	
	//read input file
	readFile(inputFileName, &fixedLocations,  &widthMatrix, &lengthMatrix);

    //search the solution
    backtracking(widthMatrix, lengthMatrix, fixedLocations, &maxSolution);

    //write file with found solution
    writeFile(outputFileName, widthMatrix, lengthMatrix, maxSolution);

    //free lists
    freeList(&maxSolution);
    freeList(&fixedLocations);

    return 0;
}