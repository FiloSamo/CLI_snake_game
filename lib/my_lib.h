// Alma Mater - Unibo
// Fondamenti di Informatica - T

// Libreria di Filippo Samorì
// v1.0

#include <stdio.h>
#include <string.h>

// COLORI TESTO

#define BIANCO "\e[0;37m"
#define NERO "\e[0;30m"
#define ROSSO "\e[0;31m"
#define VERDE "\e[0;32m"
#define GIALLO "\e[0;33m"
#define BLU "\e[0;34m"
#define CIANO "\e[0;36m"
#define DEFAULT "\e[0;39m"
#define RESET "\e[0m"

// COLORI SFONDO

#define S_BIANCO "\e[0;47m"
#define S_NERO "\e[0;40m"
#define S_ROSSO "\e[0;41m"
#define S_VERDE "\e[0;42m"
#define S_GIALLO "\e[0;43m"
#define S_BLU "\e[0;44m"
#define S_CIANO "\e[0;46m"
#define S_DEFAULT "\e[0;49m"

// SCHERMO

#define CLEAR "\e[1;1H\e[2J"
#define ESC "\e"

// COSTANTI

#define PI 3.14159

//FUNZIONI PER GLI ARRAY

// legge un vettore di interi di massimo n numeri.
int leggi_int(int *v, int dim); 
// legge un vettore di float di massimo n numeri.
int leggi_float(float *v, int dim); 
// legge un vettore di interi positivi di massimo n numeri.
int leggi_pos(int *v, int dim); 
// stampa un vettore di interi di n numeri.
void print_int(int *v, int n);
// stampa un vettore di float di n numeri.
void print_float(float *v, int n); 

// FUNZIONI PER IL TERMINALE

// Stampa una cagata per iniziare il programma
void inizio();
// Stampa una cagata per finire il programma
void fine();
// ripristina il prompt dei comandi.
void cmd_reset(); 
// pulisce lo schermo.
void cls();
// muove il cursore su una cella definita da y e x
void move_cursor(int y, int x);
// elimina la cella corrente
void cell_delate();
// converte un colore in un numero.
int color(char *colore); 
// cambia lo sfondo dietro i caratteri.
void background_color(char *colore); 
// cambia il colore dei caratteri.
void foreground_color(char *colore); 
// Scrive la stringa in un colore.
void printc(char *stringa, char *colore); 
// Scrive la stringa di un colore e cambia lo sfondo.
void print_color(char *stringa, char *colore, char *sfondo); 
//svuota il buffer dopo una scanf di caratteri.
void svuota_buffer(); 

