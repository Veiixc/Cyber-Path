#ifndef GRILLE_H
#define GRILLE_H
#include "./struct.h"

void createGrid(CASE **grid, int rows, int cols);
void addRobots(CASE **grid, int rows, int cols, Robot *robot);
int generateRandomNumber(int min, int max);

#endif