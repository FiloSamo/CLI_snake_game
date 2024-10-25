
// Alma Mater - Unibo
// Fondamenti di Informatica - T

// Libreria di Filippo Samorì
// v1.0

#include "my_lib.h"


//*************************************************************************************************//

int leggi_int(int *v, int dim){
    int t; // variabile temporanea
    int i = 0; //contatore
    printc("premere 0 per terminare\n", "blu");
    do{
        scanf("%d",&t);
        if(t != 0){
            v[i] = t;
            i++;
        }
    } while (i < dim && t != 0);
    return i;
}

int leggi_float(float *v, int dim){
    float t; // variabile temporanea
    int i = 0; //contatore
    printc("premere 0 per terminare\n", "rosso");
    do{
        scanf("%f",&t);
        if(t != 0){
            v[i] = t;
            i++;
        }
    } while (i < dim && t != 0);
    return i;
}

int leggi_pos(int *v, int dim){
    int t; // variabile temporanea
    int i = 0; //contatore
    printc("premere 0 per terminare\n", "rosso");
    do{
        scanf("%d",&t);
        if(t > 0){
            v[i] = t;
            i++;
        }
    } while (i < dim && t != 0);
    return i;
}

void print_int(int *v, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d; ", v[i]);
    }
}

void print_float(float *v, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%f; ", v[i]);
    }
}

//**************************************************************************************************//

void inizio(){
    cls();
    printc("\t\t\tPROGRAMMA IN ESECUZIONE\n", "verde");
    printc("*****************************************************************************\n", "ciano");
}

void fine(){
    cmd_reset();
    printc("\n*****************************************************************************\n", "ciano");
    printc("\t\t\t    FINE ESECUZIONE\n", "verde");
}

void cmd_reset(){
    printf(RESET);
}

void cls(){
    printf(CLEAR);
}

void move_cursor(int y, int x){
    printf(ESC "[%d;%dH", y , x);
}

void cell_delate(){
    printf(ESC "[1P");
    printf(ESC "[1@");
}


int color(char *colore){
    if(strcmp(colore,"ROSSO") == 0 || strcmp(colore,"rosso") == 0 || strcmp(colore,"Rosso") == 0)
        return 1;
    else if(strcmp(colore,"VERDE") == 0 || strcmp(colore,"verde") == 0 || strcmp(colore,"Verde") == 0)
        return 2;
    else if(strcmp(colore,"GIALLO") == 0 || strcmp(colore,"giallo") == 0 || strcmp(colore,"Giallo") == 0)
        return 3;
    else if(strcmp(colore,"BLU") == 0 || strcmp(colore,"blu") == 0 || strcmp(colore,"Blu") == 0)
        return 4;
    else if(strcmp(colore,"CIANO") == 0 || strcmp(colore,"ciano") == 0 || strcmp(colore,"Ciano") == 0)
        return 6;
    else if(strcmp(colore,"BIANCO") == 0 || strcmp(colore,"bianco") == 0 || strcmp(colore,"Bianco") == 0)
        return 7;
    else if(strcmp(colore,"NERO") == 0 || strcmp(colore,"nero") == 0 || strcmp(colore,"Nero") == 0)
        return 0;
    else return 9;
}

void background_color(char *colore){
    int n = color(colore);
    printf("\e[4%dm", n);
}

void foreground_color(char *colore){
    int n = color(colore);
    printf("\e[3%dm", n);
}

void printc(char *stringa, char *colore){
    foreground_color(colore);
    printf("%s%s", stringa, RESET);
}

void print_color(char *stringa, char *colore, char *sfondo){
    foreground_color(colore);
    background_color(sfondo);
    printf("%s%s", stringa, RESET);
}

void svuota_buffer(){
    scanf("%*c");
}

