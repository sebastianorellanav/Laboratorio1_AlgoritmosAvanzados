#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int x;
	int y;
	int id;
	struct nodo* anterior;
}nodo;


//backtracking algorithm
void backtracking(int n, int** matrix){
	int column = -1;
	int row = 0;
	bool aux = TRUE;
	nodo *list = NULL;
	nodo *max = NULL;

	while (row >= 0){
		do
		{
			column++;
			aux = checkPosition(matrix, row, column);
		} while ((column < n) && not(aux))
		if (column < n){
			insert(&list, row, column);
			if (row == n-1){
				//return list
			}
			else{
				fila++;
				column = -1;
			}
		}
		else{
			max = list;
			k--;
		}
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
	//get int from user
	matrix = (int**)malloc(n*sizeof(int*));
	for (int i = 0 ; i < n ; i++)
    	matrix[i] = (int *) malloc (n*sizeof(int));

    for (int i = 0; i < n; ++i)    {
    	for (int j = 0; i < n; ++j){
    		matrix[i][j] = 0;
    	}
    }
	}