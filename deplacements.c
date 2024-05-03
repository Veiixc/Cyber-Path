#include <stdio.h>
#include "./struct.h"

void deplacementsJoueur(CASE** grid,int* robotRow,int* robotCol){ //La fonction prend en paramètres les coordonnées du joueur et la grille
    int direction;
    printf("Wich direction:\n'z'=UP\n'q'=DOWN\n's'=LEFT\n'd'=RIGHT\n");
    scanf("%d",&direction);
    // Vérification de la direction saisie
    switch(direction) {
        case 'z': // aller en haut
            while (grid[*robotRow + 1][*robotCol].state == IS_EMPTY) {
                grid[*robotRow][*robotCol].state = IS_EMPTY; // Vide l'ancienne position
                *robotRow--; // Met à jour les nouvelles coordonnées
                grid[*robotRow][*robotCol].state = IS_ROBOT; // Met à jour la nouvelle position du robot
            }
            break;
        case 'q': // aller en bas
            while (grid[*robotRow - 1][*robotCol].state == IS_EMPTY) {
                grid[*robotRow][*robotCol].state = IS_EMPTY;
                (*robotRow)++;
                grid[*robotRow][*robotCol].state = IS_ROBOT;
            }
            break;
        case 's': // aller à gauche
            while (grid[*robotRow][*robotCol - 1].state == IS_EMPTY) {
                grid[*robotRow][*robotCol].state = IS_EMPTY;
                (*robotCol)--;
                grid[*robotRow][*robotCol].state = IS_ROBOT;
            }
            break;
        case 'd': // aller à droite
            while (grid[*robotRow][*robotCol + 1].state == IS_EMPTY) {
                grid[*robotRow][*robotCol].state = IS_EMPTY;
                (*robotCol)++;
                grid[*robotRow][*robotCol].state = IS_ROBOT;
            }
            break;
        default:
            printf("Invalid direction.\n");
    }
}