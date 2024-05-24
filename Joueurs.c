#include "./struct.h"
#include <stdio.h>
#include <unistd.h>

int Better_Scanf(char *message)
{
    int ret_var = 0;
    int value = 1;
    while (ret_var != 1 || value < 0)
    {
        printf("%s", message);
        ret_var = scanf("%d", &value);
        while (getchar() != '\n')
        {
        }
    }
    return value;
}

Players *createPlayers(Players *players)
{
    do
    {
        players->num = Better_Scanf("Veuillez saisir le nombre de joueurs (doit être supérieur à 2 et inférieur à 4) : ");
    } while (players->num < 2 || players->num > 4); // on a un nombre de joueur minimum de 2 joueurs
    for (int i = 0; i < players->num; i++)
    { // on fait une boucle pour demandez les noms de tout les joueurs
        printf("Veuillez saisir Le nom du joueur %d : ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0; // initialisation de tout les scores a 0
        players[i].nb_movement = 0;
    }
    return players; //
}

void CalculScore(Players *player, int score)
{
    for (int i = 0; i < player->num; i++)
    { // on fait une boucle pour les n nombre de joueurs
        if (player->nb_estimated_movement == player->nb_movement)
        {
            player[i].score += 2; // si le joueur a parfaitement estimé il gagne deux points
        }
        else if (player->nb_estimated_movement < player->nb_movement)
        { // si le joueur a mal estimé et que il a fait moins que son estimation on lui retire un points
            player[i].score -= 1;
        }
        else
        {
            for (int j = 0; j < player->num; j++)
            {
                if (j != i)
                {
                    player[j].score += 1;
                }
            }
        }
    }
}

void PrintWinner(Players *players)
{
    int best_score = players[0].score;
    int winner = 0;
    for (int i = 0; i < players->num; i++)
    {
        if (players[i].score > best_score)
        { // on fait une sorte de tri afin de connaitre le meilleur score, mais aussi pour avoir le numéro du joueur au sein du tableau afin de mettre son nom et son score
            best_score = players[i].score;
            winner = i;
        }
    }
    printf("Le gagnant de la partie est %s\n Son score est de %d points \nFélicitation a tout les joueurs !", players[winner].name, players[winner].score);
}

int ChoiceDifficulty()
{
    int difficulty;
    do
    {
        difficulty = Better_Scanf("Entrez le niveau de difficulté : \n1. Niveau Facile\n2. Niveau Moyen\n3. Niveau Difficile\n");
        if (difficulty < 1 || difficulty > 3)
        {
            printf("Erreur ! Merci de bien vouloir saisir une valeur entre 1, 2 et 3 pour choisir le niveau de difficulté.\n");
        }
    } while (difficulty < 1 || difficulty > 3);

    return difficulty;
}

void Num_estimated(Players *player, int target_robot, int target_target)
{
    do
    {
        printf("%s, en combien de coups estimez-vous atteindre la cible %d avec le robot %d?\n", player->name, target_target, target_robot);
        scanf("%d", &player->nb_estimated_movement);
        player->nb_movement = 0;
    } while (player->nb_estimated_movement < 0);
}

void Timer(int difficulty)
{
    int remaining_time;

    switch (difficulty)
    {
    case 1:
        remaining_time = 15;
        break;
    case 2:
        remaining_time = 10;
        break;
    case 3:
        remaining_time = 1;
        break;
    default:
        remaining_time = 10;
        break;
    }

    for (int i = 1; i <= remaining_time; i++)
    {
        sleep(1); // Attendre une seconde
        printf("\r%d/%d", i, remaining_time);
        fflush(stdout);
    }
    // system("clear"); //
    printf("\033[H\033[2J");
    printf("\nTemps écoulé !\n");
}