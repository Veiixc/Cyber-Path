#ifndef JOUEURS_H
#define JOUEURS_H
#include "./struct.h"

// enlever les majuscule au debnit des methodes
int better_scanf(char *message);
void createPlayers(Player *players);
void calculScore(Player *players, int result, int currentPlayer);
void printWinner(Player *players);
int choiceDifficulty();
void num_estimated(Player *players, int target_robot, int target_target);
void timer(int difficulty);
void loadPlayers(Player players[], int *numPlayers);
void savePlayersToFile(Player players[], int numPlayers);
void addOrUpdatePlayer(Player players[], int *numPlayers, Player newPlayer);
void triPlayersScore(Player players[], int numPlayers);
void manageFile(Player gamePlayers[], int numGamePlayers);

#endif