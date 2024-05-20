#include <stdio.h>
#include <stdlib.h>
#include "./struct.h"

void printGrid(CASE **grid, int rows, int cols)
{
    printf("row : %d, cols : %d\n", rows, cols);
    for (int row = 0; row < rows; row++)
    {
        // Afficher le mur du haut pour chaque case
        for (int col = 0; col < cols; col++)
        {
            if (grid[row][col].wall[NORTH] == WALL_PRESENT)
            {
                printf(" ― "); // Mur au-dessus de la case
            }
            else
            {
                printf("   "); // Pas de mur
            }
        }
        printf("\n");

        // Afficher les murs gauche et les symboles de chaque case
        for (int col = 0; col < cols; col++)
        {
            if (grid[row][col].wall[WEST] == WALL_PRESENT)
            {
                printf("|"); // Mur à gauche de la case
            }
            else
            {
                printf(" "); // Pas de mur
            }

            if (grid[row][col].state == IS_EMPTY)
            {
                printf("."); // Case vide
            }
            else if (grid[row][col].state == IS_ROBOT)
            {
                printf("%d", grid[row][col].robot_number); // Robot
            }
            else if (grid[row][col].state == IS_TARGET)
            {
                printf("%d", grid[row][col].target_number); // Cible
            }

            if (grid[row][col].wall[EAST] == WALL_PRESENT)
            {
                printf("|"); // Mur à droite de la case
            }
            else
            {
                printf(" "); // Pas de mur
            }
        }

        printf("\n");

        // Afficher le mur du bas pour chaque case
        for (int col = 0; col < cols; col++)
        {
            if (grid[row][col].wall[SOUTH] == WALL_PRESENT)
            {
                printf(" _ "); // Mur en dessous de la case
            }
            else
            {
                printf("   "); // Pas de mur
            }
        }
        printf("\n");
    }
}