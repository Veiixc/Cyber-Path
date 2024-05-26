#include <stdio.h>
#include "./struct.h"
#include "./printGrid.h"

int playerMovement(Case **grid, Player *player, Robot *robot, int rows, int cols, int target_target)
{
    char direction;
    int newRow, newCol;
    int score = IMPOSSIBLE;

    if (player->nb_estimated_movement == 0)
        return score;

    // Show the final grid
    printGrid(grid, rows, cols);

    while (player->nb_movement < player->nb_estimated_movement && grid[robot->actual_robot_row][robot->actual_robot_col].target_number != target_target)
    {
        // Ask for the direction of travel
        printf("%s, Quelle direction ?:\n'z'=HAUT\n's'=BAS\n'q'=GAUCHE\n'd'=DROITE\n", player->name);
        scanf(" %c", &direction);

        // Set the new coordinates to the current ones
        newRow = robot->actual_robot_row;
        newCol = robot->actual_robot_col;

        // Determine the new position according to direction
        switch (direction)
        {
        case 'z': // Go up
            while (newRow > 0 && grid[newRow - 1][newCol].wall[SOUTH] == WALL_ABSENT && grid[newRow][newCol].wall[NORTH] == WALL_ABSENT && grid[newRow - 1][newCol].state != IS_ROBOT)
            {
                newRow--;
            }
            break;
        case 's': // Go down
            while (newRow < rows - 1 && grid[newRow + 1][newCol].wall[NORTH] == WALL_ABSENT && grid[newRow][newCol].wall[SOUTH] == WALL_ABSENT && grid[newRow + 1][newCol].state != IS_ROBOT)
            {
                newRow++;
            }
            break;
        case 'q': // Move to the left
            while (newCol > 0 && grid[newRow][newCol - 1].wall[EAST] == WALL_ABSENT && grid[newRow][newCol].wall[WEST] == WALL_ABSENT && grid[newRow][newCol - 1].state != IS_ROBOT)
            {
                newCol--;
            }
            break;
        case 'd': // Move to the right
            while (newCol < cols - 1 && grid[newRow][newCol + 1].wall[WEST] == WALL_ABSENT && grid[newRow][newCol].wall[EAST] == WALL_ABSENT && grid[newRow][newCol + 1].state != IS_ROBOT)
            {
                newCol++;
            }
            break;
        default:
            printf("Mauvaise entrée\n");
            continue; // Request direction again if entry is invalid
        }

        // Robot removed from old box
        /*
            if (grid[robot->actual_robot_row][robot->actual_robot_col].previousState == IS_TARGET)
            {
                grid[robot->actual_robot_row][robot->actual_robot_col].state = IS_TARGET;
            }
            else
            {
                grid[robot->actual_robot_row][robot->actual_robot_col].state = IS_EMPTY;
            }
        */
        grid[robot->actual_robot_row][robot->actual_robot_col].state = grid[robot->actual_robot_row][robot->actual_robot_col].previousState == IS_TARGET ? IS_TARGET : IS_EMPTY;
        // grid[robot->actual_robot_row][robot->actual_robot_col].robot_number = -1; //FIXME

        // Adding the robot to the new square
        grid[newRow][newCol].state = IS_ROBOT;
        grid[newRow][newCol].robot_number = robot->index;

        // Updating the robot's coordinates
        robot->actual_robot_row = newRow;
        robot->actual_robot_col = newCol;

        // Show the grid after each movement
        printGrid(grid, rows, cols);

        // Updating the number of movements made
        player->nb_movement++;
        printf("Tu as fait %d/%d déplacements\n", player->nb_movement, player->nb_estimated_movement);
    }

    if (grid[robot->actual_robot_row][robot->actual_robot_col].target_number == target_target)
    {
        if (player->nb_movement == player->nb_estimated_movement)
            score = WELL_ESTIMATED;
        else if (player->nb_movement < player->nb_estimated_movement)
            score = LESS_ESTIMATED;
        else
            score = MORE_ESTIMATED;
    }
    else
    {
        score = MORE_ESTIMATED;
    }
    // resets the robot's position after each player.
    grid[robot->actual_robot_row][robot->actual_robot_col].state = grid[robot->actual_robot_row][robot->actual_robot_col].previousState == IS_TARGET ? IS_TARGET : IS_EMPTY;
    robot->actual_robot_row = robot->initial_robot_row;
    robot->actual_robot_col = robot->initial_robot_col;
    grid[robot->actual_robot_row][robot->actual_robot_col].state = IS_ROBOT;

    return score;
}