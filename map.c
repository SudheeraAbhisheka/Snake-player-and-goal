#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "snake.h"

void getMetadata(char* argv[], int *** metadataTable, int * metadataAmount, int * mapRow, int * mapCol)
{
    FILE* fp = fopen(*argv, "r");

    if(fp == NULL)
    {
        perror("Error opening input file");
    }
    else
    {
        int i, j, p;
        int player, goal, snake;
        int** table;
        int** arangedTable;
        
        /* reading the first lind */
        fscanf(fp, "%d %d %d", metadataAmount, mapRow, mapCol);

        table = (int**) malloc(sizeof(int*) * (*metadataAmount));
        for(i = 0; i < (*metadataAmount); i++)
        {
            table[i] = (int*) malloc(sizeof(int*) * 3);
        }

        arangedTable = (int**) malloc(sizeof(int*) * (*metadataAmount));
        for(i = 0; i < (*metadataAmount); i++)
        {
            arangedTable[i] = (int*) malloc(sizeof(int*) * 3);
        }

        /* reading remaining lines & adding them to a 2d array */
        for(i = 0; i < (*metadataAmount); i++)
        {
            for(j = 0; j < 3; j++)
            {
                fscanf(fp, "%d ", &table[i][j]);
            }
        }

        /* rearanging the map using arangedTable 2d array */
        
        /* 1st row -> player */
        player = 0;
        while(table[player][2] != 0)
        {
            player++;
        }
        arangedTable[0][0] = table[player][0];
        arangedTable[0][1] = table[player][1];
        arangedTable[0][2] = table[player][2];

        /* 3rd row -> snake */
        snake = 0;
        while(table[snake][2] != 1)
        {
            snake++;
        }
        arangedTable[2][0] = table[snake][0];
        arangedTable[2][1] = table[snake][1];
        arangedTable[2][2] = table[snake][2];

        /* 2nd row -> goal */
        goal = 0;
        while(table[goal][2] != 2)
        {
            goal++;
        }
        arangedTable[1][0] = table[goal][0];
        arangedTable[1][1] = table[goal][1];
        arangedTable[1][2] = table[goal][2];

        /* coping remaining values from table to rearanged table */
        p = 0;
        for(i = 3; i < (*metadataAmount); i++)
        {
            if(p == player || p == goal || p == snake)
                p++;

            for(j = 0; j < 3; j++)
            {
                arangedTable[i][j] = table[p][j];
            }
            p++;
        }

        *metadataTable = arangedTable;

        for(i = 0 ; i < (*metadataAmount); i++)
        {
            free(table[i]);
        }
        free(table);

        if(ferror(fp))
        {
             perror("Error reading from input file");
        }
        fclose(fp);
        fp = NULL;
    }
}