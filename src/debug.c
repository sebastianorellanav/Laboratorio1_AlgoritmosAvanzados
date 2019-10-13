#include <stdio.h>
#include <string.h>
#include "../incl/colors.h"
#include "../incl/structs.h"
#include "../incl/debug.h"


// las entradas son totalmente opcionales, en este caso he agregado para temas de prueba.
void printCurrent(node *stack, node *maxSolution, int current_ite, int current_row, int locals, int best_lvl, int best_locals)
{

    #ifdef LINUX // preguntamos si estamos trabajando en linux
    printf( VERDE_T"\t╔═══════════════════════════════════════════════════════════════════════╗\n"RESET_COLOR);
    printf( VERDE_T"\t║     "AMARILLO_T"Contenido:                                                        "VERDE_T"║\n"RESET_COLOR);
    printf( VERDE_T"\t╠═══════════════════════════════════════════════════════════════════════╣\n"RESET_COLOR);
    printf( VERDE_T"\t║                                                                       ║\n"RESET_COLOR);
    printContent(stack, maxSolution);
    printf( VERDE_T"\t║                                                                       ║\n"RESET_COLOR);
    printf( VERDE_T"\t╠═══════════════════════════════════════════════════════════════════════╣\n"RESET_COLOR);
    printf( VERDE_T"\t║    " AMARILLO_T"Iteracion: "RESET_COLOR "%i\t"VERDE_T"║\t"AMARILLO_T"Fila : "RESET_COLOR "%i\t"VERDE_T"║\t"AMARILLO_T"Sucursales: "RESET_COLOR "%i\t"VERDE_T"║\n"RESET_COLOR,current_ite,current_lvl,locals);
    printf( VERDE_T"\t╠═══════════════════════════════════════════════════════════════════════╣\n"RESET_COLOR);
    printf( VERDE_T"\t║    "AMARILLO_T"Mejor Respuesta "ROJO_T"→ \t "AMARILLO_T"Nivel: "RESET_COLOR "%i\t"VERDE_T"║\t"AMARILLO_T"Surcursales : "RESET_COLOR "%i\t        "VERDE_T"║\n"RESET_COLOR,best_lvl,best_locals);
    printf( VERDE_T"\t╚═══════════════════════════════════════════════════════════════════════╝\n"RESET_COLOR);
    #endif

    #ifdef WINDOWS // preguntamos si estamos trabajando en windows
    printf( VERDE_T"\t*-----------------------------------------------------------------------*\n"RESET_COLOR);
    printf( VERDE_T"\t|     "AMARILLO_T"Contenido:                                                        "VERDE_T"|\n"RESET_COLOR);
    printf( VERDE_T"\t*-----------------------------------------------------------------------*\n"RESET_COLOR);
    printf( VERDE_T"\t|                                                                       |\n"RESET_COLOR);
    printBoard_enun_2(board);
    printf( VERDE_T"\t|                                                                       |\n"RESET_COLOR);
    printf( VERDE_T"\t*-----------------------------------------------------------------------*\n"RESET_COLOR);
    printf( VERDE_T"\t|    " AMARILLO_T"Iteracion: "RESET_COLOR "%i\t"VERDE_T"|\t"AMARILLO_T"Nivel : "RESET_COLOR "%i\t"VERDE_T"|\t"AMARILLO_T"Sucursales: "RESET_COLOR "%i\t"VERDE_T"|\n"RESET_COLOR,current_ite,current_lvl,locals);
    printf( VERDE_T"\t*-----------------------------------------------------------------------*\n"RESET_COLOR);
    printf( VERDE_T"\t|    "AMARILLO_T"Mejor Respuesta "ROJO_T"->\t "AMARILLO_T"Nivel: "RESET_COLOR "%i\t"VERDE_T"|\t"AMARILLO_T"Surcursales : "RESET_COLOR "%i\t        "VERDE_T"|\n"RESET_COLOR,best_lvl,best_locals);
    printf( VERDE_T"\t*-----------------------------------------------------------------------*\n"RESET_COLOR);
    #endif

}


/* 
    Esta función se encarga de imprimir la matriz y calcular
    el espacio faltante para cerrar el cuadro.
*/

void printContent(node *stack, node *maxSolution)
{
    #ifdef LINUX
    printf( VERDE_T"\t║     ");
    #endif
    #ifdef WINDOWS
    printf( VERDE_T"\t|     ");
    #endif
    printf("Stack of possibles solutions:\n");
    // se cierra el cuadro.
    #ifdef LINUX
    printf(  VERDE_T"║\n"RESET_COLOR);
    #endif
    #ifdef WINDOWS
    printf(  VERDE_T"|\n"RESET_COLOR);
    #endif
    
    while(stack != NULL)
    {
        #ifdef LINUX
        printf( VERDE_T"\t║     ");
        #endif
        #ifdef WINDOWS
        printf( VERDE_T"\t|     ");
        #endif

        printf(RESET_COLOR "fila = %d | columna = %d "RESET_COLOR , stack->y, stack->x);

         // se cierra el cuadro.
        #ifdef LINUX
        printf(  VERDE_T"║\n"RESET_COLOR);
        #endif
        #ifdef WINDOWS
        printf(  VERDE_T"|\n"RESET_COLOR);
        #endif

        stack = stack->next;
    }

    #ifdef LINUX
    printf( VERDE_T"\t║     ");
    #endif
    #ifdef WINDOWS
    printf( VERDE_T"\t|     ");
    #endif
    printf("Max Solution:\n");
    // se cierra el cuadro.
    #ifdef LINUX
    printf(  VERDE_T"║\n"RESET_COLOR);
    #endif
    #ifdef WINDOWS
    printf(  VERDE_T"|\n"RESET_COLOR);
    #endif
    
    while(maxSolution != NULL)
    {
        #ifdef LINUX
        printf( VERDE_T"\t║     ");
        #endif
        #ifdef WINDOWS
        printf( VERDE_T"\t|     ");
        #endif

        printf(RESET_COLOR "fila = %d | columna = %d "RESET_COLOR , maxSolution->y, maxSolution->x);

         // se cierra el cuadro.
        #ifdef LINUX
        printf(  VERDE_T"║\n"RESET_COLOR);
        #endif
        #ifdef WINDOWS
        printf(  VERDE_T"|\n"RESET_COLOR);
        #endif

        maxSolution = maxSolution->next;
    }
        
        
    }

