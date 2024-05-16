#include <stdio.h>
#include "./struct.h"
#include "./printgrid.h"

void PlayerMovement(CASE **grid, Players* player_robot, int rows, int cols)
{
    char direction;
    printf("Quelle direction ?:\n'z'=HAUT\n's'=BAS\n'q'=GAUCHE\n'd'=DROITE\n");
    scanf(" %c", &direction);

    int newRow = player_robot[0].robot_row;
    int newCol = player_robot[0].robot_col;

    switch (direction)
    {
    case 'z': // move up
        while (newRow > 0 && grid[newRow - 1][newCol].state == IS_EMPTY && grid[newRow - 1][newCol].wall[SOUTH] == WALL_ABSENT)
        {
            newRow--;
        }
        break;
    case 's': // move down
        while (newRow < rows - 1 && grid[newRow + 1][newCol].state == IS_EMPTY && grid[newRow + 1][newCol].wall[NORTH] == WALL_ABSENT)
        {
            newRow++;
        }
        break;
    case 'q': // move left
        while (newCol > 0 && grid[newRow][newCol - 1].state == IS_EMPTY && grid[newRow][newCol - 1].wall[EAST] == WALL_ABSENT)
        {
            newCol--;
        }
        break;
    case 'd': // move right
        while (newCol < cols - 1 && grid[newRow][newCol + 1].state == IS_EMPTY && grid[newRow][newCol + 1].wall[WEST] == WALL_ABSENT)
        {
            newCol++;
        }
        break;
    }

    if (newRow != player_robot[0].robot_row || newCol != player_robot[0].robot_col)
    {
        grid[player_robot[0].robot_row][player_robot[0].robot_col].state = IS_EMPTY;
        player_robot[0].robot_row = newRow;
        player_robot[0].robot_col = newCol;
        grid[player_robot[0].robot_row][player_robot[0].robot_col].state = IS_ROBOT;
    }
    printGrid(grid,rows,cols,robot);
}
