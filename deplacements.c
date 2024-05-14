#include <stdio.h>
#include "./struct.h"
#include "./printgrid.h"

void PlayerMovement(CASE **grid, Players* robot,int rows, int cols)
{ // La fonction prend en paramètres la grille et la structure du joueur pour récupérer ses coordonnées
    char direction;
    printf("Quelle direction ?:\n'z'=HAUT\n's'=BAS\n'q'=GAUCHE\n'd'=DROITE\n");
    scanf("%c", &direction);
    
    // Vérification de la direction saisie
    switch (direction)
    {
    case 'z': // aller en haut
        while (grid[robot[0].robot_row - 1][robot[0].robot_col].state == IS_EMPTY && robot[0].robot_row>0)
        {
            grid[robot[0].robot_row][robot[0].robot_col].state = IS_EMPTY; // Vide l'ancienne position       
            robot[0].robot_row--; // Met à jour les nouvelles coordonnées
            grid[robot[0].robot_row][robot[0].robot_col].state = IS_ROBOT; // Met à jour la nouvelle position du robot
        }
        break;
    case 's': // aller en bas
        while (grid[robot[0].robot_row + 1][robot[0].robot_col].state == IS_EMPTY && robot[0].robot_row<rows)
        {
             grid[robot[0].robot_row][robot[0].robot_col].state = IS_EMPTY; // Vide l'ancienne position       
            (robot[0].robot_row)++;
            grid[robot[0].robot_row][robot[0].robot_col].state = IS_ROBOT;
        }
        break;
    case 'q': // aller à gauche
        while (grid[robot[0].robot_row][robot[0].robot_col - 1].state == IS_EMPTY && robot[0].robot_row>0)
        {
            grid[robot[0].robot_row][robot[0].robot_col].state = IS_EMPTY; // Vide l'ancienne position       
            (robot[0].robot_col)--;
            grid[robot[0].robot_row][robot[0].robot_col].state = IS_ROBOT;
        }
        break;
    case 'd': // aller à droite
        while (grid[robot[0].robot_row][robot[0].robot_col + 1].state == IS_EMPTY && robot[0].robot_row<cols)
        {
            grid[robot[0].robot_row][robot[0].robot_col].state = IS_EMPTY; // Vide l'ancienne position       
            (robot[0].robot_col)++;
            grid[robot[0].robot_row][robot[0].robot_col].state = IS_ROBOT;
        }
        break;
    }
    printGrid(grid,rows,cols,robot);
}
