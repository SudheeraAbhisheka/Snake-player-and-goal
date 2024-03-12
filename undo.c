#include "struct.h"
#include "printMap.h"

/* when pressed the 'u' */
void undo(char** map, int mapRow, int mapCol, coordinates* output, int** metadataTable, int* ppX, int* ppY, int* ssX, int* ssY)
{
    char icon;
    int pSX, pSY, sSX, sSY;

    if(output->pl == 'w')
    {
        icon = '^';
    }
    else if(output->pl == 's')
    {
        icon = 'v';
    }
    else if(output->pl == 'a')
    {
        icon = '<';
    }
    else if(output->pl == 'd')
    {
        icon = '>';
    }

    /* starting position coordinates */
    pSX = metadataTable[0][1]; 
    pSY = metadataTable[0][0];
    sSX = metadataTable[2][1];
    sSY = metadataTable[2][0];

    /* clearing the starting positions & current position to print undid map */
    map[pSY][pSX] = ' ';
    map[sSY][sSX] = ' ';
    map[*ppY][*ppX] = ' ';
    map[*ssY][*ssX] = ' ';

    /* entering undid player and snake to the map */
    map[output->pY][output->pX] = icon;
    map[output->sY][output->sX] = '~';
    completeMap(map, mapRow, mapCol);

    /* assigning undid coordinates */ 
    *ppX = output->pX;
    *ppY = output->pY;
    *ssX = output->sX;
    *ssY = output->sY;
}