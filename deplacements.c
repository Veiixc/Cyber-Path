#include <stdio.h>
#include "./struct.h"
#include "./printgrid.h"

void PlayerMovement(CASE **grid, Players *player, Robot *robot, int rows, int cols, int target_robot, int target_target)
{
    char direction;
    int newRow;
    int newCol;

    while (player->nb_movement < player->nb_estimated_movement)
    {
        // ajouter un controle sur les données entrées
        printf("%s, quelle direction ?:\n'z'=HAUT\n's'=BAS\n'q'=GAUCHE\n'd'=DROITE\n", player->name);
        scanf(" %c", &direction);

        newRow = robot->actual_robot_row;
        newCol = robot->actual_robot_col;

        switch (direction)
        {
            // cas rencontre d'une autre cible
        case 'z': // move up
            while (newRow > 0 && grid[newRow - 1][newCol].wall[SOUTH] == WALL_ABSENT)
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
            while (newCol > 0 && grid[newRow][newCol - 1].wall[EAST] == WALL_ABSENT)
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
        default:
            printf("mauvaise entrée");
            break;
        }

        player->nb_movement++;
    }

    // ajout du robot sur la nouvelle case
    grid[newRow][newCol].state = IS_ROBOT;
    grid[newRow][newCol].robot_number = robot->index;

    // Suppression du robot de l'ancienne case
    grid[robot->actual_robot_row][robot->actual_robot_col].state = IS_EMPTY;
    grid[robot->actual_robot_row][robot->actual_robot_col].robot_number = -1;

    // maj des coordonnées du robot
    robot->actual_robot_row = newRow;
    robot->actual_robot_col = newCol;

    printGrid(grid, rows, cols);
    // verifie si robot est sur al case de la cible
    // ajout des scores. voir pour ajouter la structure players et non uniquement le joueur
    // pour ajouter des points aux ennemis si on perd
    if (grid[robot->actual_robot_row][robot->actual_robot_col].target_number == target_target)
    {
        printf("bien joué.\n");
    }
    else
    {
        printf("pas sur la cible\n");
    }
}