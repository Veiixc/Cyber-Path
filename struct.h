#ifndef STRUCT_H
#define STRUCT_H

#define MAX_TARGET 18
#define MAX_ROBOT 4

enum State
{
    IS_EMPTY,
    IS_TARGET,
    IS_ROBOT
};
enum WALL
{
    NORTH,
    EST,    
    SOUTH,
    WEST
};
enum IS_WALL
{
    WALL_ABSENT,
    WALL_PRESENT
};

typedef struct CASE
{
    enum State state; // IS_EMPTY, IS_TARGET, IS_ROBOT
    enum IS_WALL wall[4];
    int target_number;
    int robot_number;
    // ...
} CASE;

typedef struct Players
{   
    int robot;
    char name[24];
    int score;
    int nb_movement;
    int nb_estimated_movement;
    int robot_row;
    int robot_col;
    int num;
    // ...
}Players;

#endif 
