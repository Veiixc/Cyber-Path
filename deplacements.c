#include <stdio.h>
#include "./struct.h"

void PlayerMovement(CASE **grid, Players robot)
{ // La fonction prend en paramètres la grille et la structure du joueur pour récupérer ses coordonnées
    char direction;
    printf("Quelle direction ?:\n'z'=HAUT\n'q'=BAS\n's'=GAUCHE\n'd'=DROITE\n");
    scanf("%d", &direction);
    grid[robot.robot_row][robot.robot_col].state = IS_EMPTY; // Vide l'ancienne position
    while (direction != 'z' || direction != 'q' || direction != 's' || direction != 'd')
    {
        printf("Mauvaise direction !\n");
        printf("Quelle direction ?:\n'z'=HAUT\n'q'=BAS\n's'=GAUCHE\n'd'=DROITE\n");
        scanf("%c", &direction);
        
     }
    // Vérification de la direction saisie
    switch (direction)
    {
    case 'z': // aller en haut
        while (grid[robot.robot_row + 1][robot.robot_col].state == IS_EMPTY)
        {
            robot.robot_row++;                                       // Met à jour les nouvelles coordonnées
            grid[robot.robot_row][robot.robot_col].state = IS_ROBOT; // Met à jour la nouvelle position du robot
        }
        break;
    case 'q': // aller en bas
        while (grid[robot.robot_row - 1][robot.robot_col].state == IS_EMPTY)
        {
            (robot.robot_row)--;
            grid[robot.robot_row][robot.robot_col].state = IS_ROBOT;
        }
        break;
    case 's': // aller à gauche
        while (grid[robot.robot_row][robot.robot_col - 1].state == IS_EMPTY)
        {
            (robot.robot_col)--;
            grid[robot.robot_row][robot.robot_col].state = IS_ROBOT;
        }
        break;
    case 'd': // aller à droite
        while (grid[robot.robot_row][robot.robot_col + 1].state == IS_EMPTY)
        {
            (robot.robot_col)++;
            grid[robot.robot_row][robot.robot_col].state = IS_ROBOT;
        }
        break;
    }
}
