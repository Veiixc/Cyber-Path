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
    EAST,
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
    int target;
    int win;
    // ...
} Players;

typedef struct
{
    int index;
    char name[24];

    // row an col after a player plays
    int actual_robot_row;
    int actual_robot_col;

    // row and col at the beginning of the round
    int initial_robot_row;
    int initial_robot_col;
    // ...
} Robot;

#define WHITE "\033[0;37m"
#define BLACK "\033[1;30m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define PURPLE "\033[1;35m"
#define CYAN "\033[1;36m"
#define GREY "\033[1;37m"
#define DEFAULT_COLOR "\033[1;0m"

#endif