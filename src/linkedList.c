#include <stdio.h>
#include <stdlib.h>
#include "../incl/backtracking.h"
#include "../incl/linkedList.h"
#include "../incl/debug.h"

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