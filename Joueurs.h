#ifndef JOUEURS_H
#define JOUEURS_H
#include "./struct.h"

// enlever les majuscule au debnit des methodes
int Better_Scanf(char *message);
void createPlayers(Player *players);
void calculScore(Player *players, int result, int currentPlayer);
void PrintWinner(Player *players);
int choiceDifficulty();
void Num_estimated(Player *players, int target_robot, int target_target);
void Timer(int difficulty);

#endif