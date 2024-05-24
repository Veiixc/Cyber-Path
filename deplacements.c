#include <stdio.h>
#include "./struct.h"
#include "./printgrid.h"

void PlayerMovement(CASE **grid, Players *player, Robot *robot, int rows, int cols, int target_robot, int target_target)
{
    char direction;
    int newRow, newCol;

    while (player->nb_movement < player->nb_estimated_movement)
    {
        // Demander la direction du déplacement
        printf("%s, Quelle direction ?:\n'z'=HAUT\n's'=BAS\n'q'=GAUCHE\n'd'=DROITE\n", player->name);
        scanf(" %c", &direction);

        // Initialiser les nouvelles coordonnées à celles actuelles
        newRow = robot->actual_robot_row;
        newCol = robot->actual_robot_col;

        // Déterminer la nouvelle position en fonction de la direction
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
                while (newCol > 0 && grid[newRow][newCol - 1].wall[EAST] == WALL_ABSENT && grid[newRow][newCol - 1].state != IS_ROBOT)
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
                continue; // Redemander la direction si l'entrée est invalide
        }

        // Ajout du robot sur la nouvelle case
        grid[newRow][newCol].state = IS_ROBOT;
        grid[newRow][newCol].robot_number = robot->index;

        // Suppression du robot de l'ancienne case
        if(newRow != robot->actual_robot_row || newCol != robot->actual_robot_col){
            grid[robot->actual_robot_row][robot->actual_robot_col].state = IS_EMPTY;
            grid[robot->actual_robot_row][robot->actual_robot_col].robot_number = -1;
        }

        // Mise à jour des coordonnées du robot
        robot->actual_robot_row = newRow;
        robot->actual_robot_col = newCol;

        printGrid(grid, rows, cols); // Afficher la grille après chaque mouvement
        // Mise à jour du nombre de mouvements effectués
        printf("Tu as fait %d/%d déplacements\n",player->nb_movement+1,player->nb_estimated_movement);
        player->nb_movement++;
    }

        // Vérifie si le robot est sur la case de la cible
        if (grid[robot->actual_robot_row][robot->actual_robot_col].target_number == target_target)
        {
            printf("Bien joué.\n");
        }
        else
        {
            printf("Pas sur la cible\n");
        }

    // Afficher la grille finale
    printGrid(grid, rows, cols);
}