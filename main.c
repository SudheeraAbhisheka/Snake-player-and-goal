#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include "map.h"
#include "terminal.h"
#include "snake.h"
#include "struct.h"
#include "linkedList.h"
#include "printMap.h"

int main(int argc, char** argv)
{
    char** map;
    char ch = ' ';
    int** metadataTable;
    int metadataAmount, mapRow, mapCol;
    int i;
    int* pX;
    int* pY;
    int* snakeX;
    int* snakeY;
    int winLost;
    LinkedList * list;
    coordinates* coord;
    coordinates* output;

    if(argc == 2)
    {
        pX = (int*)malloc(sizeof(int));
        pY = (int*)malloc(sizeof(int));
        snakeX = (int*)malloc(sizeof(int));
        snakeY = (int*)malloc(sizeof(int));

        /* getting data from the file */
        getMetadata(&argv[1], &metadataTable, &metadataAmount, &mapRow, &mapCol);
        
        *pX = metadataTable[0][1]; 
        *pY = metadataTable[0][0];
        *snakeX = metadataTable[2][1];
        *snakeY = metadataTable[2][0];

        /* creating the new map */
        map = createMap(metadataTable, metadataAmount, mapRow, mapCol);

        list = createLinkedList();

        disableBuffer();
        cls();
        controlRoom(map, mapRow, mapCol, ch, pX, pY, snakeX, snakeY);
        winLost = 1;
        while(!( (*pX == metadataTable[1][1] && *pY == metadataTable[1][0]) || (*pX == *snakeX && *pY == *snakeY) )) 
        {
            scanf("%c", &ch);
            cls();
            if(ch == 'u')
            {   
                output = (coordinates*)removeStart(list);
                if(output != NULL)
                {
                    undo(map, mapRow, mapCol, output, metadataTable, pX, pY, snakeX, snakeY);
                    free(output);
                }
                else/* if(output == NULL) */ 
                {
                    /* adding strting position to the suructure for insert to linked list */
                    coord = (coordinates *) malloc(sizeof(coordinates));
                    coord->pX = metadataTable[0][1]; 
                    coord->pY = metadataTable[0][0];
                    coord->sX = metadataTable[2][1];
                    coord->sY = metadataTable[2][0];
                    coord->pl = 'w';
                    insertStart(list, (void*)coord);

                    output = (coordinates*)removeStart(list);

                    undo(map, mapRow, mapCol, output, metadataTable, pX, pY, snakeX, snakeY);

                    free(output);
                }
            }
            else/* if(ch != 'u') */
            {
                /* adding current position to the suructure for insert to linked list */
                coord = (coordinates *) malloc(sizeof(coordinates));
                coord->pX = *pX;
                coord->pY = *pY;
                coord->sX = *snakeX;
                coord->sY = *snakeY;
                coord->pl = ch;
                insertStart(list, (void*)coord);
                
                controlRoom(map, mapRow, mapCol, ch, pX, pY, snakeX, snakeY);
                
                if(*pX == *snakeX && *pY == *snakeY)/* if the snake bit the player */
                {
                    winLost = 0;
                }
            } 
        }
        if(winLost == 1)
        {
            printf("\nYou Win!\n\n");
        }
        else
        {
            printf("\nYou Lose! try again.\n\n");
        }
        enableBuffer();

        for(i = 0 ; i < metadataAmount; i++)
        {
            free(metadataTable[i]);
        }
        free(metadataTable);

        for(i = 0 ; i < mapRow; i++)
        {
            free(map[i]);
        }
        free(map);
        free(pX);
        free(pY);
        free(snakeX);
        free(snakeY);
    
        freeLinkedList(list);
    }
    else/* if(argc != 2) */
    {
        printf("incompatible amount of arguments\n");
    }

    return 0;
}