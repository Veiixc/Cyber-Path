// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include "./struct.h"
// #include "./printgrid.h"
// #include "./Joueurs.h"
// #include "./deplacements.h"

// #define MIN_SIZE 15
// #define MAX_SIZE 20

// int generateRandomNumber(int min, int max)
// {
//     return (rand() % (max - min + 1)) + min;
// }

// void addBorderWall(CASE **grid, int rows, int cols)
// {
//     int col;
//     for (int i = 0; i < 2; i++)
//     {
//         col=generateRandomNumber(1, cols - 2);
//         grid[0][col].wall[EAST] = WALL_PRESENT;
//     }
//     for (int i = 0; i < 2; i++)
//     {
//         col=generateRandomNumber(1, cols - 2);
//         grid[rows - 1][col].wall[EAST] = WALL_PRESENT;
//     }
//     for (int i = 0; i < 2; i++)
//     {
//         col=generateRandomNumber(1, rows - 2);
//         grid[rows - 1][0].wall[SOUTH] = WALL_PRESENT;
//     }
//     for (int i = 0; i < 2; i++)
//     {
//         col=generateRandomNumber(1, rows - 2);
//         grid[rows - 1][cols - 1].wall[SOUTH] = WALL_PRESENT;
//     }
// }

// void addWall(CASE *caseGrid)
// {
//     int direction = generateRandomNumber(0, 3);
//     switch (direction)
//     {
//     case 0: // mur au sud et à l'ouest
//         caseGrid->wall[SOUTH] = WALL_PRESENT;
//         caseGrid->wall[WEST] = WALL_PRESENT;
//         break;

//     case 1: // mur au sud et à l'est
//         caseGrid->wall[SOUTH] = WALL_PRESENT;
//         caseGrid->wall[EAST] = WALL_PRESENT;
//         break;

//     case 2: // mur au nord et à l'ouest
//         caseGrid->wall[NORTH] = WALL_PRESENT;
//         caseGrid->wall[WEST] = WALL_PRESENT;
//         break;

//     case 3: // mur au nord et à l'est
//         caseGrid->wall[NORTH] = WALL_PRESENT;
//         caseGrid->wall[EAST] = WALL_PRESENT;
//         break;
//     }
// }

// void addTargetAndWall(CASE **grid, int cols, int rows)
// {
//     int placedTargets = 0;
//     int compteurTargets = 1;
//     while (placedTargets < 18)
//     {
//         int targetRow = generateRandomNumber(1, rows - 2);
//         int targetCol = generateRandomNumber(1, cols - 2);

//         if (grid[targetRow][targetCol].state == IS_EMPTY &&
//             grid[targetRow - 1][targetCol].state == IS_EMPTY &&
//             grid[targetRow + 1][targetCol].state == IS_EMPTY &&
//             grid[targetRow - 1][targetCol - 1].state == IS_EMPTY &&
//             grid[targetRow - 1][targetCol + 1].state == IS_EMPTY &&
//             grid[targetRow + 1][targetCol - 1].state == IS_EMPTY &&
//             grid[targetRow + 1][targetCol + 1].state == IS_EMPTY &&
//             grid[targetRow][targetCol - 1].state == IS_EMPTY &&
//             grid[targetRow - 1][targetCol + 1].state == IS_EMPTY &&
//             grid[targetRow][targetCol + 1].state == IS_EMPTY)
//         {
//             placedTargets++;
//             grid[targetRow][targetCol].state = IS_TARGET;
//             grid[targetRow][targetCol].target_number = compteurTargets;
//             compteurTargets++;
//             addWall(&grid[targetRow][targetCol]);
//         }
//     }
// }
// //     switch(k)
// //     {
// //         case 0 :
// //             printf("%d\n",i/j);
// //             break;
// //         case 1 :
// //             printf("%f\n",(float)i/j);
// //             break;
// //        default :
// //             printf("il faut entrer 0 ou 1\n");
// //             printf("relancez l'execution\n");
// //     }
// // }

// Players* addRobots(CASE **grid, int rows, int cols,Players* player_robot)
// {
//     int robotRow;
//     int robotCol;
//     int compteurRobots = 0;
//     for (int i = 0; i < player_robot->num; i++)
//     {
//         robotRow = generateRandomNumber(0, rows - 1);
//         robotCol = generateRandomNumber(0, cols - 1);
//         if (grid[robotRow][robotCol].state == IS_EMPTY)
//         {
//             grid[robotRow][robotCol].state = IS_ROBOT;
//             player_robot[i].robot_row = robotRow;
//             player_robot[i].robot_col = robotCol;
//             grid[robotRow][robotCol].robot_number = compteurRobots;
//             compteurRobots++;
//         }
//         else{
//             i--;
//         }
//     }
//     return player_robot;
// }

// CASE** createGrid(CASE** grid,int rows,int cols)
// {
//     for (int row = 0; row < rows; row++)
//     {
//         for (int col = 0; col < cols; col++)
//         {

//             grid[row][col].state = IS_EMPTY;

//                 if (row ==0)
//                 {
//                     grid[row][col].wall[NORTH] = WALL_PRESENT; // Bord supérieur
//                 }
//                 if (row == rows - 1)
//                 {
//                     grid[row][col].wall[SOUTH] = WALL_PRESENT; // Bord inférieur
//                 }
//                 if (col == 0)
//                 {
//                     grid[row][col].wall[WEST] = WALL_PRESENT; // Bord gauche
//                 }
//                 if (col == cols - 1)
//                 {
//                     grid[row][col].wall[EAST] = WALL_PRESENT; // Bord droit
//                 }

//         }
//     }
//     addBorderWall(grid, rows, cols);
//     addTargetAndWall(grid, cols, rows);
//     return grid;
// }

// int main()
// {
//     srand(time(NULL));
//     int rows = generateRandomNumber(15, 20);
//     int cols = generateRandomNumber(15, 20);
//     CASE **grid = (CASE **)malloc(rows * sizeof(CASE *));
//     if (grid == NULL)
//     {
//         printf("erreur d'allocation dynamique");
//         exit(EXIT_FAILURE);
//     }
//     for (int i = 0; i < rows; i++)
//     {
//         grid[i] = (CASE *)malloc(cols * sizeof(CASE));

//         if (grid[i] == NULL)
//         {
//             printf("erreur d'allocation dynamique");
//             for (int j = 0; j < i; j++)
//             {
//                 free(grid[j]);
//             }

//             free(grid);
//             exit(EXIT_FAILURE);
//         }
//     }
//     Players *player = NULL;
//     player = malloc(sizeof(Players) * 4);
//     if (player == NULL)
//     {
//         printf("Erreur d'allocation");
//         exit(1);
//     }
//     player=CreatePlayers(player);
//     grid=createGrid(grid,rows,cols);
//     player=addRobots(grid,rows,cols,player);
//     printGrid(grid, rows, cols);
//     Timer();
//     for (int i=0;i<player->num;i++){
//         player[i]=Num_estimated(player[i]);
//         player[i].win=PlayerMovement(grid,player[i],rows,cols);
//         printGrid(grid, rows, cols);
//     }
//     for (int i=0;i<player->num;i++){
//         if (player[i].win==1){
//             printf("Le joueur %d a gagné",i);
//             break;
//         }
//     }

//     for (int i = 0; i < rows; i++)
//     {
//         free(grid[i]);
//     }
//     free(grid);

//     return 0;
// }

#include "./struct.h"
#include "./printgrid.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_SIZE 15
#define MAX_SIZE 20
int generateRandomNumber(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}
void addBorderWall(CASE **grid, int rows, int cols)
{
    int col;
    for (int i = 0; i < 2; i++)
    {
        col = generateRandomNumber(1, cols - 2);
        grid[0][col].wall[EAST] = WALL_PRESENT;
    }
    for (int i = 0; i < 2; i++)
    {
        col = generateRandomNumber(1, cols - 2);
        grid[rows - 1][col].wall[EAST] = WALL_PRESENT;
    }
    for (int i = 0; i < 2; i++)
    {
        col = generateRandomNumber(1, rows - 2);
        grid[rows - 1][0].wall[SOUTH] = WALL_PRESENT;
    }
    for (int i = 0; i < 2; i++)
    {
        col = generateRandomNumber(1, rows - 2);
        grid[rows - 1][cols - 1].wall[SOUTH] = WALL_PRESENT;
    }
}
void addWall(CASE *caseGrid)
{
    int direction = generateRandomNumber(0, 3);
    switch (direction)
    {
    case 0: // mur au sud et à l'ouest
        caseGrid->wall[SOUTH] = WALL_PRESENT;
        caseGrid->wall[WEST] = WALL_PRESENT;
        break;
    case 1: // mur au sud et à l'est
        caseGrid->wall[SOUTH] = WALL_PRESENT;
        caseGrid->wall[EAST] = WALL_PRESENT;
        break;
    case 2: // mur au nord et à l'ouest
        caseGrid->wall[NORTH] = WALL_PRESENT;
        caseGrid->wall[WEST] = WALL_PRESENT;
        break;
    case 3: // mur au nord et à l'est
        caseGrid->wall[NORTH] = WALL_PRESENT;
        caseGrid->wall[EAST] = WALL_PRESENT;
        break;
    }
}
void addTargetAndWall(CASE **grid, int cols, int rows)
{
    int placedTargets = 0;
    int compteurTargets = 1;
    while (placedTargets < 18)
    {
        int targetRow = generateRandomNumber(1, rows - 2);
        int targetCol = generateRandomNumber(1, cols - 2);
        if (grid[targetRow][targetCol].state == IS_EMPTY &&
            grid[targetRow - 1][targetCol].state == IS_EMPTY &&
            grid[targetRow + 1][targetCol].state == IS_EMPTY &&
            grid[targetRow - 1][targetCol - 1].state == IS_EMPTY &&
            grid[targetRow - 1][targetCol + 1].state == IS_EMPTY &&
            grid[targetRow + 1][targetCol - 1].state == IS_EMPTY &&
            grid[targetRow + 1][targetCol + 1].state == IS_EMPTY &&
            grid[targetRow][targetCol - 1].state == IS_EMPTY &&
            grid[targetRow - 1][targetCol + 1].state == IS_EMPTY &&
            grid[targetRow][targetCol + 1].state == IS_EMPTY)
        {
            placedTargets++;
            grid[targetRow][targetCol].state = IS_TARGET;
            grid[targetRow][targetCol].target_number = compteurTargets;
            compteurTargets++;
            addWall(&grid[targetRow][targetCol]);
        }
    }
}
//     switch(k)
//     {
//         case 0 :
//             printf("%d\n",i/j);
//             break;
//         case 1 :
//             printf("%f\n",(float)i/j);
//             break;
//        default :
//             printf("il faut entrer 0 ou 1\n");
//             printf("relancez l'execution\n");
//     }
// }

void addRobots(CASE **grid, int rows, int cols)
{
    int compteurRobots = 1;
    Players *player_robot = NULL;
    player_robot = malloc(sizeof(Players) * 4);
    if (player_robot == NULL)
    {
        printf("Erreur d'allocation");
        exit(1);
    }
    for (int i = 0; i < 4; i++)
    {
        int robotRow = generateRandomNumber(0, rows - 1);
        int robotCol = generateRandomNumber(0, cols - 1);
        if (grid[robotRow][robotCol].state == IS_EMPTY)
        {
            grid[robotRow][robotCol].state = IS_ROBOT;
            player_robot[i].robot_row = robotRow;
            player_robot[i].robot_col = robotCol;
            grid[robotRow][robotCol].robot_number = compteurRobots;
            compteurRobots++;
        }
    }
    printGrid(grid, rows, cols, player_robot);
}

void createGrid()
{
    int rows = generateRandomNumber(15, 20);
    int cols = generateRandomNumber(15, 20);
    CASE **grid = (CASE **)malloc(rows * sizeof(CASE *));
    if (grid == NULL)
    {
        printf("erreur d'allocation dynamique");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < rows; i++)
    {
        grid[i] = (CASE *)malloc(cols * sizeof(CASE));

        if (grid[i] == NULL)
        {
            printf("erreur d'allocation dynamique");
            for (int j = 0; j < i; j++)
            {
                free(grid[j]);
            }

            free(grid);
            exit(EXIT_FAILURE);
        }
    }

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            grid[row][col].state = IS_EMPTY;

            if (row == 0)
            {
                grid[row][col].wall[NORTH] = WALL_PRESENT; // Bord supérieur
            }
            if (row == rows - 1)
            {
                grid[row][col].wall[SOUTH] = WALL_PRESENT; // Bord inférieur
            }
            if (col == 0)
            {
                grid[row][col].wall[WEST] = WALL_PRESENT; // Bord gauche
            }
            if (col == cols - 1)
            {
                grid[row][col].wall[EAST] = WALL_PRESENT; // Bord droit
            }
        }
    }
    addBorderWall(grid, rows, cols);
    addTargetAndWall(grid, cols, rows);
    addRobots(grid, rows, cols);

    for (int i = 0; i < rows; i++)
    {
        free(grid[i]);
    }
    free(grid);
}

int main()
{
    srand(time(NULL));
    createGrid();
    return 0;
}