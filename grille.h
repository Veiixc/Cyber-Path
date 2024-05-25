#ifndef GRILLE_H
#define GRILLE_H
#include "./struct.h"

void createGrid(Case **grid, int rows, int cols);
void addRobots(Case **grid, int rows, int cols, Robot *robot);
int generateRandomNumber(int min, int max);

#endif