#include <stdio.h>
#define ROW 3
#define COL 2

void main()
{
    int i, j;
    int a[ROW][COL] = {{1, 2}, {3, 4}, {5, 6}};

    int sum = 0;

    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            sum += a[i][j];
        }
    }

    printf("%.2f", (float)sum / (ROW * COL));
}
