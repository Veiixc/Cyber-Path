#include "./struct.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#define MaxPlayerInFile 10 // there is a maximum of 10 players in the file;
#define MaxPlayerInGame 4

int better_scanf(char *message)
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

void createPlayers(Player *players)
{
    do
    {
        players->num = better_scanf("Veuillez saisir le nombre de joueurs (doit être supérieur à 1 et inférieur à 5) : ");
    } while (players->num < 2 || players->num > 4); // we have a minimum of 2 players and a maximum of 4 players
    for (int i = 0; i < players->num; i++)
    { // make a loop to ask for the names of all the players
        printf("Veuillez saisir Le nom du joueur %d : ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0; // set all scores to 0
        players[i].nb_movement = 0;
    }
}

void calculScore(Player *players, int result, int currentPlayer)
{

    switch (result)
    {
    case LESS_ESTIMATED:
        players[currentPlayer].score++;
        break;
    case WELL_ESTIMATED:
        players[currentPlayer].score += 2;
        break;
    case MORE_ESTIMATED:
        for (int i = 0; i < players->num; i++)
        {
            if (i != currentPlayer)
            {
                players[i].score++;
            }
        }
        break;
    case IMPOSSIBLE:
        players[currentPlayer].score += 0;
        break;
    default:
        break;
    }
}

void printWinner(Player *players)
{
    int best_score = players[0].score;
    int num_winner = 0;
    bool draw = false;

    for (int i = 1; i < players[0].num; i++)
    {
        if (players[i].score > best_score)
        {
            best_score = players[i].score;
            num_winner = i;
            draw = false;
        }
        else if (players[i].score == best_score)
        {
            draw = true;
        }
    }

    if (!draw)
    {
        printf("Le gagnant de la partie est %s avec le score de %d\n",
               players[num_winner].name, players[num_winner].score);
    }
    else
    {
        printf("Il y a égalité !\nLes joueurs ex aequo sont :\n");
        for (int i = 0; i < players[0].num; i++)
        {
            if (players[i].score == best_score)
            {
                printf("%s avec le score de %d\n", players[i].name, players[i].score);
            }
        }
    }
}

int choiceDifficulty()
{
    int difficulty;
    do
    {
        difficulty = better_scanf("Entrez le niveau de difficulté : \n1. Niveau Facile\n2. Niveau Moyen\n3. Niveau Difficile\n");
        if (difficulty < 1 || difficulty > 3)
        {
            printf("Erreur ! Merci de bien vouloir saisir une valeur entre 1, 2 et 3 pour choisir le niveau de difficulté.\n");
        }
    } while (difficulty < 1 || difficulty > 3);

    return difficulty;
}

void num_estimated(Player *player, int target_robot, int target_target)
{
    do
    {
        printf("%s,vous devez atteindre la cible %d avec le robot %d?\n", player->name, target_target, target_robot);
        player->nb_estimated_movement = better_scanf("Entrez le nombre de coups que vous estimez faire (remplissez 0 si la cible n'est pas possible) : \n");

        player->nb_movement = 0;
    } while (player->nb_estimated_movement < 0);
}

void timer(int difficulty)
{
    int remaining_time;

    switch (difficulty)
    {
    case 1:
        remaining_time = 40;
        break;
    case 2:
        remaining_time = 20;
        break;
    case 3:
        remaining_time = 1;
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

// Fonction pour charger les joueurs depuis le fichier
void loadPlayers(Player players[], int *numPlayers)
{
    *numPlayers = 0;
    FILE *file = fopen("score.txt", "r");
    if (file == NULL)
    {
        printf("Le fichier ne peut pas être lu\n");
        return;
    }
    while (fscanf(file, "Nom : %49s | Score : %d\n", players[*numPlayers].name, &players[*numPlayers].score) == 2 && *numPlayers < MaxPlayerInFile)
    {
        (*numPlayers)++;
    }
    fclose(file);
}

// Fonction pour sauvegarder les joueurs dans le fichier
void savePlayersToFile(Player players[], int numPlayers)
{
    FILE *file = fopen("score.txt", "w");
    if (file == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier\n");
        return;
    }
    for (int i = 0; i < numPlayers; i++)
    {
        fprintf(file, "Nom : %s | Score : %d\n", players[i].name, players[i].score);
    }
    fclose(file);
}

// Fonction pour ajouter ou mettre à jour un joueur dans le tableau
void addOrUpdatePlayer(Player players[], int *numPlayers, Player newPlayer)
{
    for (int i = 0; i < *numPlayers; i++)
    {
        if (strcmp(players[i].name, newPlayer.name) == 0)
        { // Vérifie si le nom du joueur existe déjà
            if (newPlayer.score > players[i].score)
            {
                players[i].score = newPlayer.score; // Met à jour le score si le nouveau score est supérieur
            }
            return;
        }
    }
    if (*numPlayers < MaxPlayerInFile)
    { // Si le fichier a un nombre de joueurs inférieur a 10, alors il peut ajouter des joueurs
        players[*numPlayers] = newPlayer;
        (*numPlayers)++;
    }
}

// Fonction pour trier les joueurs par score en ordre décroissant
void triPlayersScore(Player players[], int numPlayers)
{
    for (int i = 0; i < numPlayers - 1; i++)
    {
        for (int j = 0; j < numPlayers - i - 1; j++)
        {
            if (players[j].score < players[j + 1].score)
            {
                Player temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp; // Place le score le plus élevé en haut
            }
        }
    }
}

// Fonction pour gérer les joueurs et mettre à jour le fichier
void manageFile(Player gamePlayers[], int numGamePlayers)
{
    Player players[MaxPlayerInFile + MaxPlayerInGame]; // Capacité pour les joueurs existants et nouveaux
    int numPlayers;

    loadPlayers(players, &numPlayers); // Charge les joueurs existants depuis le fichier

    for (int i = 0; i < numGamePlayers; i++)
    {
        addOrUpdatePlayer(players, &numPlayers, gamePlayers[i]);
    }

    triPlayersScore(players, numPlayers);

    if (numPlayers > MaxPlayerInFile)
    {
        numPlayers = MaxPlayerInFile;
    }

    savePlayersToFile(players, numPlayers);
}