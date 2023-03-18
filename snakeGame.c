#include <unistd.h>

int create_gameboard(int width,int height)
{
    /*
        0 : Empty
        1 : Snake
        2 : Fruit
        3 : Limit
    */

    int xpos_loop;
    int ypos_loop;
    int gameboard[height][width];

    for (ypos_loop = 0; ypos_loop <= height; ++ypos_loop)
    {
        for (xpos_loop = 0; xpos_loop <= width; ++xpos_loop)
        {
            if (ypos_loop == 0 || ypos_loop == height || xpos_loop == 0 || xpos_loop == width)
            {
                gameboard[ypos_loop][xpos_loop] = 1;
            } else {
                gameboard[ypos_loop][xpos_loop] = 0;
            }
        }
    }
    return gameboard;
}


void display_gameboard(int gameboard[][], int width, int height)
{
    int xpos_loop;
    int ypos_loop;

    for (ypos_loop = 0; ypos_loop <= height; ++ypos_loop)
    {
        for (xpos_loop = 0; xpos_loop <= width; ++xpos_loop)
        {
            switch(gameboard[ypos_loop][xpos_loop]){
                case 0:
                    write(1," ",1);
                case 1:
                    write(1,"*",1);
                case 2:
                    write(1,"&",1);
                case 3:
                    write(1,"=",1);
            }
        }
        write(1,"\n",1);
    }
}