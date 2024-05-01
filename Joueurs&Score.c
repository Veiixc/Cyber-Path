#include "./struct.h"

int Better_Scanf(char *message) {
    int ret_var = 0;
    int value = 1;
    while (ret_var != 1 || value < 0) {
        printf("%s", message);
        ret_var = scanf("%d", &value);
        while (getchar() != '\n') {}
    }
    return value;
}

void CreatePlayers(Players *players) {
    do {
        players->num = Better_Scanf("Veuillez saisir le nombre de joueurs (doit être supérieur à 2) : ");
    } while (players->num < 2);//on a un nombre de joueur minimum de 2 joueurs 
    for (int i = 0; i < players->num; i++) {//on fait une boucle pour demandez les noms de tout les joueurs
        printf("Veuillez saisir Le nom du joueur %d : ", i + 1);
        scanf("%s", players[i].name); 
        players[i].score=0;//initialisation de tout les scores a 0
    }
}

void CalculScore(Players *player, int score ){
    for(int i=0;i<player->num;i++){//on fait une boucle pour les n nombre de joueurs
        if(player->nb_estimated_movement==player->nb_movement){
            player[i].score +=2;//si le joueur a parfaitement estimé il gagne deux points
        }
        else if(player->nb_estimated_movement < player->nb_movement){//si le joueur a mal estimé et que il a fait moins que son estimation on lui retire un points 
            player[i].score-=1;
        }
        else {
            for(int j=0;j<player->num;j++){
                if(j!=i){
                    player[j].score+=1;
                }
            }
        }
    }
}

void PrintWinner(Players *players){
    int best_score=players[0].score;
    int winner=0;
    for(int i=0;i<players->num;i++){
        if(players[i].score>best_score){//on fait une sorte de tri afin de connaitre le meilleur score, mais aussi pour avoir le numéro du joueur au sein du tableau afin de mettre son nom et son score
            best_score = players[i].score;
            winner = i;
        }
    }
    printf("Le gagnant de la partie est %s\n Son score est de %d points \nFélicitation a tout les joueurs !",players[winner].name, players[winner].score);
}

#include <stdio.h>
#include <unistd.h>

void Minuteur(){
    difficulty=ChoiceofDifficulty();
    if(difficulty==1){
    int remaining_time = 10; // Temps restant en secondes

    // Boucle pour décompter le temps
    while (remaining_time > 0) {
        sleep(1); // Pause d'une seconde
        remaining_time--;
    }

    printf("Fin du temps imparti\n");
    }
    else if(difficulty==2){
        int remaining_time = 5; // Temps restant en secondes

    // Boucle pour décompter le temps
    while (remaining_time > 0) {
        sleep(1); // Pause d'une seconde
        remaining_time--;
    }

    printf("Fin du temps imparti\n");
    }
    else if (difficulty==3){
        int remaining_time = 3; // Temps restant en secondes

    // Boucle pour décompter le temps
    while (remaining_time > 0) {
        sleep(1); // Pause d'une seconde
        remaining_time--;
    }

    printf("Fin du temps imparti\n");
    }
}




int main() {
    Players players;
    CreatePlayers(&players);
return 0;
}