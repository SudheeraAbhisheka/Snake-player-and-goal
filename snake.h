#ifndef SNAKE_H
#define SNAKE_H

void snakeToDown(char** map, int* ssX, int* ssY, int* ppX, int* ppY, int onOff);
void snakeToUp(char** map, int* ssX, int* ssY, int* ppX, int* ppY, int onOff);
void snakeToLeft(char** map, int* ssX, int* ssY, int* ppX, int* ppY, int onOff);
void snakeToRight(char** map, int* ssX, int* ssY, int* ppX, int* ppY, int onOff);

#endif