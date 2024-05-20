#ifndef JOUEURS_H
#define JOUEURS_H
#include "./struct.h"

int Better_Scanf(char *message);
Players *createPlayers(Players *players);
void CalculScore(Players *player, int score);
void PrintWinner(Players *players);
int ChoiceDifficulty();
void Num_estimated(Players *players, int target_robot, int target_target);
void Timer(int difficulty);

#endif