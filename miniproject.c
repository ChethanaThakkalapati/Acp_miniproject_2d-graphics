#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ROWS 25
#define COLS 60
#define MAX_OBJECTS 100
char canvas[ROWS][COLS];
//Object structure
typedef struct
{
    int type; // 1-Line 2-Rectangle 3-Circle 4-Triangle
    int x1, y1, x2, y2, r;
} Object;
//object Array
Object objects[MAX_OBJECTS];
int objectCount = 0;
//clear canvas-clear screen before drawing
void clearCanvas()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            canvas[i][j] = '_';
        }
    }
}
void displayCanvas()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}