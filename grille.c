#include "./struct.h" 
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
 

#define MIN_SIZE 15
#define MAX_SIZE 20


void createGrille(){
    int rows = MIN_SIZE +rand() % 16;
    int cols = MIN_SIZE +rand() % 16;
    CASE** grille = (CASE**)malloc(rows*sizeof(CASE*));
    if(grille==NULL){
        exit(EXIT_FAILURE);
    }
    for(int i=0;  i<rows;i++ ){
        grille[i]=(CASE*)malloc(cols*sizeof(CASE));
        if(grille[i]==NULL){
            exit(EXIT_FAILURE);
        }
    }

        //toutes les differnets fonctions 




    for(int i=0;  i<rows ;i++ ){
        free(grille[i]);
    }
    free(grille);
}

void putcible(){
        
}





int main(){
    creationGrille();
   
    return 0;   
}   