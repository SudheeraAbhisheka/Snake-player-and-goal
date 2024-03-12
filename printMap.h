#ifndef MAPS_H
#define MAPS_H

#include "struct.h"

void completeMap(char** map, int mapRow, int mapCol);
int controlRoom(char** map, int mapRow, int mapCol, char ch, int* ppX, int* ppY, int* ssX, int* ssY);
char** createMap(int** metadataTable, int metadataAmount, int mapRow, int mapCol);
void undo(char** map, int mapRow, int mapCol, coordinates* output, int** metadataTable, int* ppX, int* ppY, int* ssX, int* ssY);

#endif