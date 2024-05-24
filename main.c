#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./struct.h"
#include "./printgrid.h"
#include "./Joueurs.h"
#include "./deplacements.h"
#include "./grille.h"

int main()
{
    srand(time(NULL));
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
            printf("erreur d'allocation dynamique");
            free(grid);
            exit(EXIT_FAILURE);
        }
    }
    Players *player = NULL;
    player = malloc(sizeof(Players) * 4);
    if (player == NULL)
    {
        printf("Erreur d'allocation des joueurs");
        exit(EXIT_FAILURE);
    }

    Robot *robots = NULL;
    robots = malloc(sizeof(Robot) * 4);
    if (robots == NULL)
    {
        printf("Erreur d'allocation des robots");
        exit(EXIT_FAILURE);
    }

    createPlayers(player);
    createGrid(grid, rows, cols);
    addRobots(grid, rows, cols, robots);

    int round = Better_Scanf("Entrez le nombre de manche : ");
    int difficulty = ChoiceDifficulty();

    // boucle principale du jeu
    for (int actual_round = 0; actual_round < round; actual_round++)
    {
        printf("Manche %d\n\n", actual_round + 1);

        int target_robot = generateRandomNumber(0, MAX_ROBOT - 1);
        int target_target = generateRandomNumber(1, MAX_TARGET);
        printGrid(grid, rows, cols);
        printf("le robot choisi est le %d et la cible a atteindre est la %d\n", target_robot, target_target);
        Timer(difficulty);

        // estimation des mouvements pour chaque joueur
        for (int i = 0; i < player->num; i++)
        {
            Num_estimated(&player[i], target_robot, target_target);
        }
        // déplacement de chaque joueur
        for (int i = 0; i < player->num; i++)
        {
            printGrid(grid, rows, cols);
            PlayerMovement(grid, &player[i], &robots[target_robot], rows, cols, target_target);
            grid[robots[target_robot].actual_robot_row][robots[target_robot].actual_robot_col].state = IS_EMPTY;
            robots[target_robot].actual_robot_row = robots[target_robot].initial_robot_row;
            robots[target_robot].actual_robot_col = robots[target_robot].initial_robot_col;
            grid[robots[target_robot].actual_robot_row][robots[target_robot].actual_robot_col].state = IS_ROBOT;
            CalculScore(player);
        }
    }
    PrintWinner(player);
    printf("fin du programme");

    for (int i = 0; i < rows; i++)
    {
        free(grid[i]);
    }
    free(grid);
    free(player);

    return 0;
}