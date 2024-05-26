#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./struct.h"
#include "./printGrid.h"
#include "./Joueurs.h"
#include "./deplacements.h"
#include "./grille.h"
#include <unistd.h>

int compareItems(const void *a, const void *b)
{
    // Convertir les pointeurs en pointeurs vers des Item
    Player *itemA = (Player *)a;
    Player *itemB = (Player *)b;

    // Comparer les champs movement
    if (itemA->nb_estimated_movement < itemB->nb_estimated_movement)
    {
        return -1;
    }
    else if (itemA->nb_estimated_movement > itemB->nb_estimated_movement)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

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

    int round = better_scanf("Entrez le nombre de manche : ");
    int difficulty = choiceDifficulty();

    // main game loop
    for (int actual_round = 0; actual_round < round; actual_round++)
    {
        printf("Manche %d\n\n", actual_round + 1);

        int target_robot = generateRandomNumber(0, MAX_ROBOT - 1);
        int target_target = generateRandomNumber(1, MAX_TARGET);
        printGrid(grid, rows, cols);
        printf("La cible à atteindre est la cible %d avec le robot %d?\n", target_target, target_robot);
        timer(difficulty);

        // estimated movements for each player
        printf("Manche %d\n\n", actual_round + 1);
        for (int i = 0; i < players->num; i++)
        {
            num_estimated(&players[i], target_robot, target_target);
        }
        /*
        The sorting method only works if the first player has the lowest estimate.The sorting method only works if the first player has the lowest estimate.
        */
        // Trier le tableau
        // size_t size = players->num;
        // qsort(players, size, sizeof(Player), compareItems);
        for (int i = 0; i < players->num; i++)
        {
            printf("Manche %d\n\n", actual_round + 1);
            int result = playerMovement(grid, &players[i], &robots[target_robot], rows, cols, target_target);
            sleep(2);
            calculScore(players, result, i);
            fflush(stdout);
            printf("Le score de %s est actuellement de %d points\n", players[i].name, players[i].score);
        }
        for (int i = 0; i < players->num; i++)
        {
            printf("Le score de %s pour cette manche est actuellement de %d points\n", players[i].name, players[i].score);
        }
        printf("Manche %d\n\n", actual_round + 1);
    }

    printWinner(players);
    manageFile(players, players->num);
    printf("\nfin du programme");

    for (int i = 0; i < rows; i++)
    {
        free(grid[i]);
    }
    free(grid);
    free(players);

    return 0;
}