// Alma Mater - Unibo
// Fondamenti di Informatica - T

// Libreria di Filippo Samorì
// v1.0

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_lib.h"
#include <time.h>

#define ESC "\e"
#define CLEAR "\e[1;1H\e[2J"
#define COLOR_MELA "VERDE"
#define COLOR_MAPPA "GIALLO"

typedef struct{
    int x;
    int y;
} point;

// FUNZIONI DI GIOCO


// Inizializza la console
void setup(point *snake,int x_dim, int y_dim, point origin);
// Finisce il gioco
void finish();
// Funzione che restituisce 1 se il serpente si morde da solo, altrimenti 0.
int bite(point *snake, int dim);
// Funzione che fa attraversare i muri al serpente
void if_hurt(point *testa, int x_dim, int y_dim);
// Funzione che restituisce 1 se il serpente mangia la mela, 0 altrimenti, e incrementa la dimensione del serpente di 1.
int eat(point testa, point mela, int *dim, point origin);
// Funzione che muove il serpente (definisce la posizione della nuova testa e cancella la coda)
void move(point *snake, int dim, char dir, point origin);
// Spawna la mela per la mappa.
void spawn(point *snake, point *mela, int dim, int x_dim, int y_dim, point origin);
// Crea la mappa.
void map(int x_dim, int y_dim, point origin);
// stampa il serpente (stampa solo la testa)
void stamp(point *snake, point origin);
