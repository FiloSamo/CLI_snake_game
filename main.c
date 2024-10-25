// Alma Mater - Unibo
// Fondamenti di Informatica - T

// Filippo Samorì - filippo.samori@studio.unibo.it
// v1.0

#include "lib/snake.h"

#define X_ORIGINE 10
#define Y_ORIGINE 5
#define XDIM 20
#define YDIM 10

#define BASSO 0x25
#define ALTO 0x27
#define SX  0x26
#define DX  0x28


int main() {
    int gameover;
    int score;
    point snake[XDIM * YDIM], mela, origin;
    int snake_dim;
    char dir = 'a' , c;
    clock_t t1, t2;
    origin.x = X_ORIGINE;
    origin.y = Y_ORIGINE;
    cls();
    printf("******************  SNAKE GAME  ******************\n\n\n");
    printf("Premere invio per iniziare");
    do{
        scanf("%c",&c);
    } while(c != '\n');
        score = 1;
        gameover = 0;
        snake_dim = 1;
        setup(snake, XDIM, YDIM, origin);
        map(XDIM, YDIM, origin);
        spawn(snake, &mela, snake_dim, XDIM, YDIM, origin);
        move_cursor(1,1);
        printf("Lunghezza: ");
        printf("%d", score);
        t1 = clock();
        t2 = clock();
        while (!gameover){
            if((double)(clock() - t1)/ CLOCKS_PER_SEC > 0.2){
                if(GetKeyState(ALTO) != 0 && GetKeyState(ALTO) != 1 ) dir = 'a';
                else if(GetKeyState(BASSO) != 0 && GetKeyState(BASSO) != 1) dir = 'b';
                else if(GetKeyState(DX) != 0 && GetKeyState(DX) != 1) dir = 'd';
                else if(GetKeyState(SX) != 0 && GetKeyState(SX) != 1) dir = 's';
                fflush(stdin);
                t1 = clock();
            }
            if((double)(clock() - t2)/ CLOCKS_PER_SEC > 0.5){
                map(XDIM, YDIM, origin);
                move(snake, snake_dim, dir, origin);
                if_hurt(&snake[0], XDIM, YDIM);
                if(eat(snake[0], mela, &snake_dim, origin)){
                    spawn(snake, &mela, snake_dim, XDIM, YDIM, origin);
                    score++;
                    move_cursor(1, 12);
                    cell_delate();
                    printf("%d", score);
                }
                gameover = bite(snake, snake_dim);
                stamp(&snake[0], origin);
                t2 = clock();
            }

        }
        finish();
        printf("******************  GAME OVER  ******************\n\n\n");
        printf("Premere invio per uscire");
        scanf("%c",&c);

    return 0;
}