#include <stdlib.h>
#include <stdio.h>

/* adding the map details & the start positions to the map */
char** createMap(int** metadataTable, int metadataAmount, int mapRow, int mapCol)
{
    char** map;
    int* x, *y;
    int i, j;

    y = (int *) malloc(sizeof(int *) * metadataAmount);
    x = (int *) malloc(sizeof(int *) * metadataAmount);

    map = (char **) malloc(sizeof(char *) * mapRow);
    for(i = 0 ; i < mapRow; i++)
    {
        map[i] = (char *) malloc(sizeof(char) * mapCol);
    }

    for(i = 0; i < metadataAmount; i++)
    {
        y[i] = metadataTable[i][0];
        x[i] = metadataTable[i][1];
    }

    for(i = 0; i < mapRow; i++)
    {
        for(j = 0; j < mapCol; j++)
        {
            map[i][j] = ' ';
        }
    }

    for(i = 3; i < metadataAmount; i++)
    {
        map[y[i]][x[i]] = 'o'; 
    }

    for(i = 1; i < mapCol - 1; i++){
        map[0][i] = '-';
        map[mapRow - 1][i] = '-';
    }
    for(i = 1; i < mapRow - 1; i++){
        map[i][0] = '|';
        map[i][mapCol - 1] = '|';
    }
 
    map[y[0]][x[0]] = '^';
    map[y[1]][x[1]] = 'x';
    map[y[2]][x[2]] = '~';
    map[0][0] = '#';
    map[0][mapCol -1] = '#';
    map[mapRow - 1][0] = '#';
    map[mapRow - 1][mapCol - 1] = '#';

    free(x);
    free(y);

    return map;    
}

/*printing the map*/
void completeMap(char** map, int mapRow, int mapCol)
{
    int y, x;
    for(y = 0; y < mapRow; y++)
    {
        for(x = 0; x < mapCol; x++)
        {
            printf("%c", map[y][x]);
        }
        printf("\n");
    }
}