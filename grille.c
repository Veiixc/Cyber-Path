#include "./struct.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_SIZE 15
#define MAX_SIZE 20

int generateRandomNumber(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

void addWall(CASE caseGrid)
{
           int direction = generateRandomNumber(0, 3);
                switch (direction)
                {
                case 0: // mur au sud et à l'ouest
                    caseGrid.wall[SOUTH] = WALL_PRESENT;
                    caseGrid.wall[WEST] = WALL_PRESENT;
                    break;

                case 1: // mur au sud et à l'est
                    caseGrid.wall[SOUTH] = WALL_PRESENT;
                    caseGrid.wall[EST] = WALL_PRESENT;
                    break;

                case 2: // mur au nord et à l'ouest
                    caseGrid.wall[NORTH] = WALL_PRESENT;
                    caseGrid.wall[WEST] = WALL_PRESENT;
                    break;

                case 3: // mur au nord et à l'est
                    caseGrid.wall[NORTH] = WALL_PRESENT;
                    caseGrid.wall[EST] = WALL_PRESENT;
                    break;
                }
            }


void addTargetAndWall(CASE **grid, int cols, int rows)
{
    int placedTargets = 0;
    while (placedTargets < 18)
    {
        int targetRow = generateRandomNumber(1, rows - 2);
        int targetCol = generateRandomNumber(1, cols - 2);

           if(grid[targetRow][targetCol].state == IS_EMPTY
               && grid[targetRow-1][targetCol].state == IS_EMPTY
               &&grid[targetRow-1][targetCol-1].state == IS_EMPTY
               &&grid[targetRow-1][targetCol+1].state == IS_EMPTY
               &&grid[targetRow+1][targetCol-1].state == IS_EMPTY
               &&grid[targetRow+1][targetCol+1].state == IS_EMPTY
               &&grid[targetRow+1][targetCol+1].state == IS_EMPTY
               &&grid[targetRow-1][targetCol+1].state == IS_EMPTY
               &&grid[targetRow][targetCol+1].state == IS_EMPTY){
                  placedTargets++;
                  grid[targetRow][targetCol].state = IS_TARGET;
                  addWall(grid[targetRow][targetCol]);
               }
    }
}
//     switch(k)
//     {
//         case 0 :
//             printf("%d\n",i/j);
//             break;
//         case 1 :
//             printf("%f\n",(float)i/j);
//             break;
//        default :
//             printf("il faut entrer 0 ou 1\n");
//             printf("relancez l'execution\n");
//     }
// }     

void createGrid()
{
    int rows = generateRandomNumber(15, 20);
    int cols = generateRandomNumber(15, 20);
    CASE **grid = (CASE **)malloc(rows * sizeof(CASE *));
    if (grid == NULL)
    {
        printf("erreur d'allocation dynamique");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < rows; i++)
    {
        grid[i] = (CASE *)malloc(cols * sizeof(CASE));
        if (grid[i] == NULL)
        {
            exit(EXIT_FAILURE);
        }
    }

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {

            grid[row][col].state = IS_EMPTY;
            for (int i = 0; i < 4; i++)
            {
                grid[row][col].wall[i] = WALL_ABSENT;
            }
        }
    }

    addTargetAndWall(grid,cols,rows);

    
    for(int i = 0; i < rows; i++)
    {
        free(grid[i]);
    }
    free(grid);
}
int main()
{
    createGrid();
    return 0;
}