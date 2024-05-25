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
    int rows = generateRandomNumber(MIN_SIZE_GRID, MAX_SIZE_GRID);
    int cols = generateRandomNumber(MIN_SIZE_GRID, MAX_SIZE_GRID);

    Case **grid = (Case **)malloc(rows * sizeof(Case *));
    if (grid == NULL)
    {
        printf("erreur d'allocation dynamique");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < rows; i++)
    {
        grid[i] = (Case *)malloc(cols * sizeof(Case));

        if (grid[i] == NULL)
        {
            printf("erreur d'allocation dynamique");
            free(grid);
            exit(EXIT_FAILURE);
        }
    }
    Player *players = NULL;
    players = malloc(sizeof(Player) * 4);
    if (players == NULL)
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

    createPlayers(players);
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
        timer(difficulty);

        // estimation des mouvements pour chaque joueur
        for (int i = 0; i < players->num; i++)
        {
            Num_estimated(&players[i], target_robot, target_target);
        }

        // TODO commencer par le joueur avec le plus petit mouvement
        //  déplacement de chaque joueur
        for (int i = 0; i < players->num; i++)
        {
            int result = playerMovement(grid, &players[i], &robots[target_robot], rows, cols, target_target);
            calculScore(players, result, i);
        }
    }
    PrintWinner(players);
    printf("\nfin du programme");

    for (int i = 0; i < rows; i++)
    {
        free(grid[i]);
    }
    free(grid);
    free(players);

    return 0;
}