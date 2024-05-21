#include <stdio.h>
#include "./struct.h"
#include "./printgrid.h"

int PlayerMovement(CASE **grid, Players player_robot, int rows, int cols)
{
    char direction;
    int newRow;
    int newCol;

    while(player_robot.nb_estimated_movement>0){
        printf("Quelle direction ?:\n'z'=HAUT\n's'=BAS\n'q'=GAUCHE\n'd'=DROITE\n");
        scanf(" %c", &direction);
        if (direction == 'z' || direction == 'q' || direction || 's' || direction == 'd'){
            printf("Il te reste %d déplacements !\n",player_robot.nb_estimated_movement);
        }
        else {
            printf("Mauvaise touche\n");
        }

        newRow = player_robot.robot_row;
        newCol = player_robot.robot_col;

        switch (direction)
        {
        case 'z': // move up
            while (newRow > 0  && grid[newRow - 1][newCol].wall[SOUTH] == WALL_ABSENT)
            {   
                newRow--;
            }
            break;
        case 's': // move down
            while (newRow < rows - 1 && grid[newRow + 1][newCol].wall[NORTH] == WALL_ABSENT)
            {
                newRow++;
            }
            break;
        case 'q': // move left
            while (newCol > 0 &&  grid[newRow][newCol - 1].wall[EAST] == WALL_ABSENT)
            {
                newCol--;
            }
            break;
        case 'd': // move right
            while (newCol < cols - 1 && grid[newRow][newCol + 1].wall[WEST] == WALL_ABSENT)
            {
                newCol++;
            }
            break;
        }

        if (newRow != player_robot.robot_row || newCol != player_robot.robot_col)
        {
            grid[player_robot.robot_row][player_robot.robot_col].state = IS_EMPTY;
            player_robot.robot_row = newRow;
            player_robot.robot_col = newCol;
            grid[player_robot.robot_row][player_robot.robot_col].state = IS_ROBOT;
            player_robot.nb_estimated_movement--;
        }

    }
}