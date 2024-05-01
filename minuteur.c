#include <stdio.h>
#include <unistd.h>

void Minuteur(){
    if(ChoiceOfDifficulty==1){
    int remaining_time = 10; // Temps restant en secondes

    // Boucle pour décompter le temps
    while (remaining_time > 0) {
        sleep(1); // Pause d'une seconde
        remaining_time--;
    }

    printf("Fin du temps imparti\n");
    }
    else if(ChoiceOfDifficulty==2){
        int remaining_time = 5; // Temps restant en secondes

    // Boucle pour décompter le temps
    while (remaining_time > 0) {
        sleep(1); // Pause d'une seconde
        remaining_time--;
    }

    printf("Fin du temps imparti\n");
    }
    else if (ChoiceOfDifficulty()==3){
        int remaining_time = 3; // Temps restant en secondes

    // Boucle pour décompter le temps
    while (remaining_time > 0) {
        sleep(1); // Pause d'une seconde
        remaining_time--;
    }

    printf("Fin du temps imparti\n");
    }
}
    

    return 0;
}
