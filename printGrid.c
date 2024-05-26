#include <stdio.h>
#include <stdlib.h>
#include "./struct.h"
#include "./colors.h"

void printGrid(Case **grid, int rows, int cols)
{
    printf("row : %d, cols : %d\n", rows, cols);
    for (int row = 0; row < rows; row++)
    {
        // Print the top wall for each box
        for (int col = 0; col < cols; col++)
        {
            if (grid[row][col].wall[NORTH] == WALL_PRESENT)
            {
                printf(" __ "); // Wall above the box
            }
            else
            {
                printf("    "); // No wall
            }
        }
        printf("\n");

        // Print left walls and symbols of each square
        for (int col = 0; col < cols; col++)
        {
            if (grid[row][col].wall[WEST] == WALL_PRESENT)
            {
                printf("|"); // Wall to the left of the box
            }
            else
            {
                printf(" "); // No wall
            }

            if (grid[row][col].state == IS_EMPTY)
            {
                printf(" ."); // Empty case
            }
            else if (grid[row][col].state == IS_ROBOT)
            {
                printf(RED "%2d" DEFAULT_COLOR, grid[row][col].robot_number); // Robot
            }
            else if (grid[row][col].state == IS_TARGET)
            {
                printf(BLUE "%2d" DEFAULT_COLOR, grid[row][col].target_number); // Target
            }

            if (grid[row][col].wall[EAST] == WALL_PRESENT)
            {
                printf("|"); // Wall to the right of the box
            }
            else
            {
                printf(" "); // No wall
            }
        }

        printf("\n");

        // Print bottom wall for each box
        for (int col = 0; col < cols; col++)
        {
            if (grid[row][col].wall[SOUTH] == WALL_PRESENT)
            {
                printf(" ―― "); // Wall below the box
            }
            else
            {
                printf("    "); // No wall
            }
        }
        printf("\n");
    }
}