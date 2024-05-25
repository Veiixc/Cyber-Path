#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./struct.h"
#include "./printgrid.h"
#include "./Joueurs.h"
#include "./deplacements.h"

/**
 * Generate a random number between the given min and max integer
 */
int generateRandomNumber(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

/**
 * This method add walls all around the grid
 */
void addBorderWall(Case **grid, int rows, int cols)
{
    int col;
    for (int i = 0; i < 2; i++)
    {
        col = generateRandomNumber(1, cols - 2);
        grid[0][col].wall[EAST] = WALL_PRESENT;
    }
    for (int i = 0; i < 2; i++)
    {
        col = generateRandomNumber(1, cols - 2);
        grid[rows - 1][col].wall[EAST] = WALL_PRESENT;
    }
    for (int i = 0; i < 2; i++)
    {
        col = generateRandomNumber(1, rows - 2);
        grid[col][0].wall[SOUTH] = WALL_PRESENT;
    }
    for (int i = 0; i < 2; i++)
    {
        col = generateRandomNumber(1, rows - 2);
        grid[col][cols - 1].wall[SOUTH] = WALL_PRESENT;
    }
}

/**
 * This method add walls around a target
 */
void addWall(Case *caseGrid)
{
    int direction = generateRandomNumber(0, 3);
    switch (direction)
    {
    case 0: // mur au sud et à l'ouest
        caseGrid->wall[SOUTH] = WALL_PRESENT;
        caseGrid->wall[WEST] = WALL_PRESENT;
        break;

    case 1: // mur au sud et à l'est
        caseGrid->wall[SOUTH] = WALL_PRESENT;
        caseGrid->wall[EAST] = WALL_PRESENT;
        break;

    case 2: // mur au nord et à l'ouest
        caseGrid->wall[NORTH] = WALL_PRESENT;
        caseGrid->wall[WEST] = WALL_PRESENT;
        break;

    case 3: // mur au nord et à l'est
        caseGrid->wall[NORTH] = WALL_PRESENT;
        caseGrid->wall[EAST] = WALL_PRESENT;
        break;
    }
}

/**
 * This method add targets to grid and wall around it
 */
void addTargetAndWall(Case **grid, int cols, int rows)
{
    int placedTargets = 0;
    while (placedTargets < MAX_TARGET)
    {
        int targetRow = generateRandomNumber(1, rows - 2);
        int targetCol = generateRandomNumber(1, cols - 2);

        if (grid[targetRow][targetCol].state == IS_EMPTY &&
            grid[targetRow - 1][targetCol].state == IS_EMPTY &&
            grid[targetRow + 1][targetCol].state == IS_EMPTY &&
            grid[targetRow - 1][targetCol - 1].state == IS_EMPTY &&
            grid[targetRow - 1][targetCol + 1].state == IS_EMPTY &&
            grid[targetRow + 1][targetCol - 1].state == IS_EMPTY &&
            grid[targetRow + 1][targetCol + 1].state == IS_EMPTY &&
            grid[targetRow][targetCol - 1].state == IS_EMPTY &&
            grid[targetRow - 1][targetCol + 1].state == IS_EMPTY &&
            grid[targetRow][targetCol + 1].state == IS_EMPTY)
        {
            placedTargets++;
            grid[targetRow][targetCol].state = IS_TARGET;
            grid[targetRow][targetCol].previousState = IS_TARGET;
            grid[targetRow][targetCol].target_number = placedTargets;
            addWall(&grid[targetRow][targetCol]);
        }
    }
}

/**
 * This method add robots to the grid
 */
void addRobots(Case **grid, int rows, int cols, Robot *robots)
{
    int robotRow;
    int robotCol;

    int i = 0;
    while (i < MAX_ROBOT)
    {
        robotRow = generateRandomNumber(0, rows - 1);
        robotCol = generateRandomNumber(0, cols - 1);
        if (grid[robotRow][robotCol].state == IS_EMPTY)
        {
            grid[robotRow][robotCol].state = IS_ROBOT;
            grid[robotRow][robotCol].previousState = IS_ROBOT;
            grid[robotRow][robotCol].robot_number = i;

            robots[i].actual_robot_row = robotRow;
            robots[i].actual_robot_col = robotCol;
            robots[i].initial_robot_row = robotRow;
            robots[i].initial_robot_col = robotCol;
            robots[i].index = i;

            i++;
        }
    }
}

/**
 * this method create the grid of the game
 */
void createGrid(Case **grid, int rows, int cols)
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {

            grid[row][col].state = IS_EMPTY;
            grid[row][col].previousState = IS_EMPTY;

            if (row == 0)
            {
                grid[row][col].wall[NORTH] = WALL_PRESENT; // Bord supérieur
            }
            if (row == rows - 1)
            {
                grid[row][col].wall[SOUTH] = WALL_PRESENT; // Bord inférieur
            }
            if (col == 0)
            {
                grid[row][col].wall[WEST] = WALL_PRESENT; // Bord gauche
            }
            if (col == cols - 1)
            {
                grid[row][col].wall[EAST] = WALL_PRESENT; // Bord droit
            }
        }
    }
    addBorderWall(grid, rows, cols);
    addTargetAndWall(grid, cols, rows);
}