#include <stdlib.h>
#include <unistd.h>

void create_gameboard(int*** gameboard_pointer, int width, int height)
{
    /*
        0 : Empty
        1 : Snake
        2 : Fruit
        3 : Limit
    */

    int xpos_loop;
    int ypos_loop;

    for (ypos_loop = 0; ypos_loop < height; ++ypos_loop)
    {
        for (xpos_loop = 0; xpos_loop < width; ++xpos_loop)
        {
            if (ypos_loop == 0 || ypos_loop == height-1 || xpos_loop == 0 || xpos_loop == width-1)
            {
                gameboard_pointer[ypos_loop][xpos_loop] = malloc(sizeof(int));
                *(gameboard_pointer[ypos_loop][xpos_loop]) = 3;
            } else {
                gameboard_pointer[ypos_loop][xpos_loop] = malloc(sizeof(int));
                *(gameboard_pointer[ypos_loop][xpos_loop]) = 0;
            }
        }
    }
}


void display_gameboard(int*** gameboard_pointer, int width, int height)
{
    int xpos_loop;
    int ypos_loop;
    int value;

    for (ypos_loop = 0; ypos_loop < height; ++ypos_loop)
    {
        for (xpos_loop = 0; xpos_loop < width; ++xpos_loop)
        {
            value = *(gameboard_pointer[ypos_loop][xpos_loop]);
            switch(value){
                case 0:
                    write(1," ",1);
                    break;
                case 1:
                    write(1,"*",1);
                    break;
                case 2:
                    write(1,"&",1);
                    break;
                case 3:
                    write(1,"=",1);
                    break;
            }
        }
        write(1,"\n",1);
    }
}

int main(void)
{
    int width = 30;
    int height = 20;

    // Allouer de l'espace mémoire pour chaque pointeur dans le tableau de pointeurs
    int*** gameboard = malloc(height * sizeof(int**));
    for (int i = 0; i < height; ++i) {
        gameboard[i] = malloc(width * sizeof(int*));
    }

    create_gameboard(gameboard, width, height);
    display_gameboard(gameboard, width, height);

    // Libérer l'espace mémoire alloué pour chaque pointeur et chaque élément du tableau
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            free(gameboard[i][j]);
        }
        free(gameboard[i]);
    }
    free(gameboard);

    return 0;
}
