
// Alma Mater - Unibo
// Fondamenti di Informatica - T

// Libreria di Filippo Samorì
// v1.0


#include "snake.h"

void setup(point *snake,int x_dim, int y_dim, point origin){
    printf(ESC "[?25l");
    cls();
    snake -> x = (x_dim/2 - 1);
    snake -> y = (y_dim/2 - 1);
}

void finish(){
    cls();
    printf(ESC "[?25h");
    cls();
}

int bite(point *snake, int dim){
    int i;
    for(i = 1; i < dim; i++){
        if(snake[0].x == snake[i].x){
            if(snake[0].y == snake[i].y) return 1;
        }
    }
    return 0;
}

void if_hurt(point *testa, int x_dim, int y_dim){
    if( testa -> x == 0) testa -> x = x_dim -1 ;
    else if( testa -> x == x_dim) testa -> x = 1;
    if( testa -> y == 0) testa -> y = y_dim - 1;
    if( testa -> y == y_dim) testa -> y = 1;    
}


int eat(point testa, point mela, int *dim, point origin){
    if(testa.x == mela.x){
        if(testa.y == mela.y) {
            (*dim)++;
            move_cursor(origin.y + mela.y, origin.x + mela.x );
            cell_delate(); // elimino la mela
            return 1;
        }
    }
    return 0;
}

void move(point *snake, int dim, char dir, point origin){
    int i;
    move_cursor(origin.y + snake[dim - 1].y, origin.x + snake[dim - 1].x );
    cell_delate(); // cancello la coda
    for(i = dim - 1; i > 0; i--) snake[i] = snake[i - 1];
    if(dir == 'a') snake[0].x += 1;
    if(dir == 'd') snake[0].y += 1;
    if(dir == 'b') snake[0].x -= 1;
    if(dir == 's') snake[0].y -= 1;
} 

void spawn(point *snake, point *mela, int dim, int x_dim, int y_dim, point origin){
    point tmela;
    int i;
    int t = 0;
    srand(time(0));
    while(t == 0){
        t = 1;
        tmela.x = rand() % (x_dim - 1) + 1;
        tmela.y = rand() % (y_dim - 1) + 1;
        for(i = 0; i < dim; i++){
            if(tmela.x == snake[i].x){
                if(tmela.y == snake[i].y){
                    t = 0;
                    break;
                }
            }
        }
    }
    mela -> x = tmela.x;
    mela -> y = tmela.y;
    move_cursor(origin.y + tmela.y, origin.x + tmela.x);
    printc("*", COLOR_MELA);   
}

void map(int x_dim, int y_dim, point origin){
    int x, y, i;
    move_cursor(origin.y,origin.x);
    printf(ESC "(0"); // permette di stampare i bordi
    foreground_color(COLOR_MAPPA);
    for(y = 0; y <= y_dim; y++){
        if(y == 0){
            printf("l");
            for(x = 1; x < x_dim; x++) printf("q");
            printf("k");
        }
        else if(y == y_dim){
            printf("m");
            for(x = 1; x < x_dim; x++) printf("q");
            printf("j");
        }
        else{
            printf("x");
            printf(ESC "[%dG", origin.x + x_dim);
            printf("x");
        }
        move_cursor(origin.y + (y + 1),origin.x);
    }
    foreground_color("DEFAULT");
    printf(ESC "(B"); // permette di stamapre caratteri
}

void stamp(point *snake, point origin){
    move_cursor(origin.y + snake -> y, origin.x + snake -> x );
    printf("@"); // stampo la testa
}
