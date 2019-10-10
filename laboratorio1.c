#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int x;
	int y;
	int id;
	struct nodo* siguiente;
}nodo;

nodo* crearNodo(int posX, int posY, int numId){
	nodo *new = NULL;
   	new = (nodo*)malloc(sizeof(nodo));
   	new -> x = posX;
   	new -> y = posY;
   	new -> id = numId;
   	new -> siguiente = NULL;
   	return new;
}

void insertarAlInicio(nodo **lista, int posX, int posY){
	if(*lista == NULL){
		*lista = crearNodo(posX, posY, 0);
	}
	else{
		nodo *aux = *lista;
		*lista = crearNodo(posX, posY, (aux->id)++);
		*lista -> siguiente = aux;
	}
}

void readFile(char *nombreArchivo, nodo **lista, int *ancho, int *alto){
	//Definir variables
	int nLineasSiguientes = 0, aux1 = 0, aux2 = 0;
	FILE *archivo = NULL;

	//Abrir archivo
  	archivo = fopen(nombreArchivo, "r");

  	//verificar si el archivo se abrió correctamente
  	if(archivo == NULL){    
    	printf("  Error: No se ha podido abrir el archivo %s", nombreArchivo);
    	exit(1);
  	}

  	//guardar ancho y alto de la matriz
  	fscanf(archivo, "%d", ancho);
  	fscanf(archivo, "%d", alto);

  	//Guardar el numero de lineas siguientes
  	fscanf(archivo, "%d", &nLineasSiguientes);

  	//Guardar lineas Siguientes
  	for (int i = 0; i < nLineasSiguientes; ++i){
  		fscanf(archivo, "%d", &aux1);
  		fscanf(archivo, "%d", &aux2);
  		insertarAlInicio(lista, aux1, aux2);
  	}


}

void colocarSucursalesFijas(int **matriz, nodo *lista){
	nodo *aux = lista;
	while(aux != NULL){
		matriz[aux->y][aux->x] = 2;
	}
}

//backtracking algorithm
void backtracking(int n, int** matrix){
	int columna = -1;
	int fila = 0;
	bool aux = TRUE;
	nodo *lista = NULL;
	nodo *maximo = NULL;

	//mientras se puedan colocar filas
	while (file >= 0){
		do
		{
			column++;
			aux = checkPosition(matrix, row, column);
		} while ((column < n) && not(aux))
		
		//Si quedé dentro de la matriz
		if (column < n){
			//guardar numero en matriz
			//guardar posicion en lista

			insert(&list, row, column);
			//si estoy en ultima fila (logre colocar el maximo)
			if (row == n-1){
				//return list
			}
			//si no estoy en la ultima fila
			else{
				fila++;
				column = -1;
			}
		}
		//Si no quede dentro de la matriz
		else{
			if(maximo == NULL || lista->tamaño >= maximo->tamaño){
				aux = maximo;
				borrarDesdeMaximo(&lista, aux);
				maximo = lista;
			}
			else{

			}
			k--;
		}
	}
}

for (int i = 0; i < alto; ++i){
	for (int j = 0; j < ancho; ++j){
		if(posicion no es valida){
			j++;
		}
		else{
			//guardar numero en matriz
			//guardar posicion en lista
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
	//crear variables
	int ancho = 0;
	int alto = 0;
	char *nombre;
	nodo *lista = NULL;
	
	//leer archivo
	readFile(nombre, &lista,  &m, &n);

	//crear matriz
	matrix = (int**)malloc(alto*sizeof(int*));
	for (int i = 0 ; i < alto ; i++)
    	matrix[i] = (int *) malloc (ancho*sizeof(int));

    //inicializar la matriz con ceros
    for (int i = 0; i < alto; ++i)    {
    	for (int j = 0; i < ancho; ++j){
    		matrix[i][j] = 0;
    	}
    }

    colocarSucursalesFijas(matriz, lista);
    liberarLista(&lista);


	}