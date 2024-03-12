#include "printMap.h"
#include "snake.h"

/* clearing the previous position of the player. Assinging the new position */
/* & avoiding the walls */
int controlRoom(char** map, int mapRow, int mapCol, char ch, int* ppX, int* ppY, int* ssX, int* ssY)
{  
    if(ch == 'w' && (map[*ppY - 1][*ppX] == ' ' || map[*ppY - 1][*ppX] == 'x' || map[*ppY - 1][*ppX] == '~'))
    {
        if(map[*ppY - 1][*ppX] == '~')
        {
            map[*ppY][*ppX] = ' ';
        }
        else
        {
            map[*ppY][*ppX] = ' ';
            (*ppY)--;
            map[*ppY][*ppX] = '^';
        }

        if(*ppY > *ssY)
        {
            snakeToDown(map, ssX, ssY, ppX, ppY, 1);
        }
        else if(*ppY == *ssY)
        {

        }
        else
        {
            snakeToUp(map, ssX, ssY, ppX, ppY, 1);
        }
    }

    if(ch == 's' && (map[*ppY + 1][*ppX] == ' ' || map[*ppY + 1][*ppX] == 'x' || map[*ppY + 1][*ppX] == '~'))
    {
        if(map[*ppY + 1][*ppX] == '~')
        {
            map[*ppY][*ppX] = ' ';
        }
        else
        {
            map[*ppY][*ppX] = ' ';
            (*ppY)++;
            map[*ppY][*ppX] = 'v';
        }

        if(*ppY > *ssY)
        {
            snakeToDown(map, ssX, ssY, ppX, ppY, 1);
        }
        else if(*ppY == *ssY)
        {

        }
        else
        {
            snakeToUp(map, ssX, ssY, ppX, ppY, 1);
        }
    }
    if(ch == 'a' && (map[*ppY][*ppX - 1] == ' ' || map[*ppY][*ppX - 1] == 'x' || map[*ppY][*ppX - 1] == '~'))
    {
        if(map[*ppY][*ppX - 1] == '~')
        {
            map[*ppY][*ppX] = ' ';
        }
        else
        {
            map[*ppY][*ppX] = ' ';
            (*ppX)--;
            map[*ppY][*ppX] = '<';
        }

        if(*ppX > *ssX)
        {
            snakeToRight(map, ssX, ssY, ppX, ppY, 1);
        }
        else if(*ppX == *ssX)
        {

        }
        else
        {
            snakeToLeft(map, ssX, ssY, ppX, ppY, 1);
        }
    }
    
    if(ch == 'd' && (map[*ppY][*ppX + 1] == ' ' || map[*ppY][*ppX + 1] == 'x' || map[*ppY][*ppX + 1] == '~'))
    {
        if(map[*ppY][*ppX + 1] == '~')
        {
            map[*ppY][*ppX] = ' ';
        }
        else
        {
            map[*ppY][*ppX] = ' ';
            (*ppX)++;
            map[*ppY][*ppX] = '>';
        }

        if(*ppX > *ssX)
        {
            snakeToRight(map, ssX, ssY, ppX, ppY, 1);
        }
        else if(*ppX == *ssX)
        {

        }
        else
        {
            snakeToLeft(map, ssX, ssY, ppX, ppY, 1);
        }
    }

    completeMap(map, mapRow, mapCol);

    return 0;
}

/* clearing the previous position of the snake. Assinging the new position */
/* & avoiding the walls */
/* onOff = 1 -> function has been called from above controlRoom 
onOff = 0 -> function has been called from one of below snake functions */
/* this prevents endless recursion */
void snakeToDown(char** map, int* ssX, int* ssY, int* ppX, int* ppY, int onOff)
{
    if(map[*ssY + 1][*ssX] != 'o' && map[*ssY + 1][*ssX] != 'x')
    {
        map[*ssY][*ssX] = ' ';
        (*ssY)++;
        map[*ssY][*ssX] = '~';
    }
    else if(onOff == 1)/* if there is a wall */
    {
        if(*ppX > *ssX)
        {
            snakeToRight(map, ssX, ssY, ppX, ppY, 0);
        }
        else
        {
            snakeToLeft(map, ssX, ssY, ppX, ppY, 0);
        }
    }
}
void snakeToUp(char** map, int* ssX, int* ssY, int* ppX, int* ppY, int onOff)
{   
    if(map[*ssY - 1][*ssX] != 'o' && map[*ssY - 1][*ssX] != 'x')
    {
        map[*ssY][*ssX] = ' ';
        (*ssY)--;
        map[*ssY][*ssX] = '~';
    }
    else if(onOff == 1)/* if there is a wall */
    {
        if(*ppX > *ssX)
        {
            snakeToRight(map, ssX, ssY, ppX, ppY, 0);
        }
        else
        {
            snakeToLeft(map, ssX, ssY, ppX, ppY, 0);
        }
    }
}
void snakeToRight(char** map, int* ssX, int* ssY, int* ppX, int* ppY, int onOff)
{
    if(map[*ssY][*ssX + 1] != 'o' && map[*ssY][*ssX + 1] != 'x')
    {
        map[*ssY][*ssX] = ' ';
        (*ssX)++;
        map[*ssY][*ssX] = '~';
    }
    else if(onOff == 1)/* if there is a wall */
    {
        if(*ppY > *ssY)
        {
            snakeToDown(map, ssX, ssY, ppX, ppY, 0);
        }
        else
        {
            snakeToUp(map, ssX, ssY, ppX, ppY, 0);
        }
    }
}
void snakeToLeft(char** map, int* ssX, int* ssY, int* ppX, int* ppY, int onOff)
{
    if(map[*ssY][*ssX - 1] != 'o' && map[*ssY][*ssX - 1] != 'x')
    {
        map[*ssY][*ssX] = ' ';
        (*ssX)--;
        map[*ssY][*ssX] = '~';
    }
    else if(onOff == 1)/* if there is a wall */
    {
        if(*ppY > *ssY)
        {
            snakeToDown(map, ssX, ssY, ppX, ppY, 0);
        }
        else
        {
            snakeToUp(map, ssX, ssY, ppX, ppY, 0);
        }
    }
}