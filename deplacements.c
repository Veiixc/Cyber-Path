#include <stdio.h>
#include "./struct.h"
#include "./printgrid.h"

int PlayerMovement(Case **grid, Player *player, Robot *robot, int rows, int cols, int target_target)
{
    char direction;
    int newRow, newCol;

    if (player->nb_estimated_movement == 0)
        return IMPOSSIBLE;

    // Afficher la grille finale
    printGrid(grid, rows, cols);

    while (player->nb_movement < player->nb_estimated_movement && grid[robot->actual_robot_row][robot->actual_robot_col].target_number != target_target)
    {
        // Demander la direction du déplacement
        printf("%s, Quelle direction ?:\n'z'=HAUT\n's'=BAS\n'q'=GAUCHE\n'd'=DROITE\n", player->name);
        scanf(" %c", &direction);
        if (direction == 'z' || direction == 'q' || direction || 's' || direction == 'd'){
            printf("Il te reste %d déplacements !\n",player_robot.nb_estimated_movement);
        }
        else {
            printf("Mauvaise touche\n");
        }

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
            continue; // Redemander la direction si l'entrée est invalide
        }

        // Suppression du robot de l'ancienne case
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

        // Ajout du robot sur la nouvelle case
        grid[newRow][newCol].state = IS_ROBOT;
        grid[newRow][newCol].robot_number = robot->index;

        // Mise à jour des coordonnées du robot
        robot->actual_robot_row = newRow;
        robot->actual_robot_col = newCol;

        // Afficher la grille après chaque mouvement
        printGrid(grid, rows, cols);

        // Mise à jour du nombre de mouvements effectués
        player->nb_movement++;
        printf("Tu as fait %d/%d déplacements\n", player->nb_movement, player->nb_estimated_movement);
    }

    // reinitialise la position du robot apres chaque joueur.
    grid[robot->actual_robot_row][robot->actual_robot_col].state = grid[robot->actual_robot_row][robot->actual_robot_col].previousState == IS_TARGET ? IS_TARGET : IS_EMPTY;
    robot->actual_robot_row = robot->initial_robot_row;
    robot->actual_robot_col = robot->initial_robot_col;
    grid[robot->actual_robot_row][robot->actual_robot_col].state = IS_ROBOT;

    if (grid[robot->actual_robot_row][robot->actual_robot_col].target_number == target_target)
    {
        if (player->nb_movement == player->nb_estimated_movement)
            return WELL_ESTIMATED;
        else if (player->nb_movement < player->nb_estimated_movement)
            return LESS_ESTIMATED;
        else
            return MORE_ESTIMATED;
    }
    else
    {
        return MORE_ESTIMATED;
    }
}