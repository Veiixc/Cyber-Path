#ifndef JOUEURS_H
#define JOUEURS_H
#include "./struct.h"

int Better_Scanf(char *message);
Players* CreatePlayers(Players *players);
void CalculScore(Players *player, int score);
void PrintWinner(Players *players);
int ChoiceDifficulty();
Players Num_estimated(Players players);
void Timer();



#endif