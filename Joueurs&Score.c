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
        players->num = Better_Scanf("Veuillez saisir le nombre de joueurs (doit Ãªtre supÃ©rieur Ã  2) : ");
    } while (players->num < 2);//on a un nombre de joueur minimum de 2 joueurs 
    for (int i = 0; i < players->num; i++) {//on fait une boucle pour demandez les noms de tout les joueurs
        printf("Veuillez saisir Le nom du joueur %d : ", i + 1);
        scanf("%s", players[i].name); 
    }
}

void Score(Players *players, int score, int nb_deplacement_est, int nb_reel ){
    for(int i=0;i<players->num;i++){//on fait une boucle pour les n nombre de joueurs
        if(nb_deplacement_est==nb_reel){
            players[i].score +=2;//si le joueur a parfaitement estimÃ© il gagne deux points
        }
        else if(nb_deplacement_est < nb_reel){//si le joueur a mal estimÃ© et que il a fait moins que son estimation on lui retire un points 
            players[i].score-=1;
        }
        else {
            for(int j=0;j<players->num;j++){
                if(j!=i){
                    players[j].score+=1;
                }
            }
        }
    }
}
