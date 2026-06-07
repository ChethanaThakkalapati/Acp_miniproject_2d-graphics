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
void plotPoint(int x, int y)
{
    if (x >= 0 && x < ROWS && y >= 0 && y < COLS)
    {
        canvas[x][y] = '*';
    }
}
//drawing line
void drawLine(int x1,int y1,int x2,int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int steps = (dx > dy) ? dx : dy;
    float Xinc = (float)(x2 - x1) / steps;
    float Yinc = (float)(y2 - y1) / steps;
    float x = x1;
    float y = y1;
    for (int i = 0; i <= steps; i++)
    {
        plotPoint(round(x), round(y));
        x += Xinc;
        y += Yinc;
    }
}
//drawing rectangle
void drawRectangle(int x1,int y1,int x2,int y2)
{
    drawLine(x1, y1, x1, y2);
    drawLine(x2, y1, x2, y2);
    drawLine(x1, y1, x2, y1);
    drawLine(x1, y2, x2, y2);
}   
//drawing circle
void drawCircle(int x0,int y0,int r)
{
    for(int angle=0;angle<360;angle++)
    {
        float rad=angle*3.14159/180;
        int x=xc+r*cos(rad);
        int y=yc+r*sin(rad);

        plotPoint(x,y);
    }
}
//drawing triangle
void drawTriangle(int x1,int y1,int x2,int y2,int x3,int y3)
{
    drawLine(x1, y1, x2, y2);
    drawLine(x2, y2, x3, y3);
    drawLine(x3, y3, x1, y1);
}
//reddraw entire canvas
void redrawCanvas()
{
    clearCanvas();
    for (int i = 0; i < objectCount; i++)
    {
        Object obj = objects[i];
        switch (obj.type)
        {
        case 1:
            drawLine(obj.x1, obj.y1, obj.x2, obj.y2);
            break;
        case 2:
            drawRectangle(obj.x1, obj.y1, obj.x2, obj.y2);
            break;
        case 3:
            drawCircle(obj.x1, obj.y1, obj.r);
            break;
        case 4:
            drawTriangle(obj.x1, obj.y1, obj.x2, obj.y2, obj.r, obj.y2); 
            break;
        }
    }
}
//Add function
void addline()
{
    Object obj;
    obj.type = 1;
    printf("Enter x1 y1 x2 y2: ");
    scanf("%d %d %d %d", &obj.x1, &obj.y1, &obj.x2, &obj.y2);
    objects[objectCount++] = obj;
}
void addRectangle()
{
    Object obj;
    obj.type = 2;
    printf("Enter top-left and bottom-right coordinates:\n ");
    scanf("%d %d %d %d", &obj.x1, &obj.y1, &obj.x2, &obj.y2);
    objects[objectCount++] = obj;
}
void addCircle()
{
    Object obj;
    obj.type = 3;
    printf("Enter center x y and radius: ");
    scanf("%d %d %d", &obj.x1, &obj.y1, &obj.r);
    objects[objectCount++] = obj;
}
void addTriangle()
{
    Object obj;
    obj.type = 4;
    printf("Enter x1 y1 x2 y2 x3 y3:\n ");
    scanf("%d %d %d %d %d %d", &obj.x1, &obj.y1, &obj.x2, &obj.y2, &obj.r, &obj.y2); 
    objects[objectCount++] = obj;
}

