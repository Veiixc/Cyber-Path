#ifndef STRUCT_H
#define STRUCT_H

#define MAX_TARGET 18
#define MAX_ROBOT 4
#define MIN_SIZE_GRID 15
#define MAX_SIZE_GRID 20

enum State
{
    IS_EMPTY,
    IS_TARGET,
    IS_ROBOT
};

enum Score
{
    WELL_ESTIMATED,
    LESS_ESTIMATED,
    MORE_ESTIMATED,
    IMPOSSIBLE
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

typedef struct
{
    enum State state;         // current state
    enum State previousState; // used to retrieves the old state during the moving phase
    enum IS_WALL wall[4];
    int target_number;
    int robot_number;
} Case;

typedef struct
{
    int robot;
    char name[50];
    int score;
    int nb_movement;
    int nb_estimated_movement;
    int num; // FIXME
} Player;

typedef struct
{
    int index;
    char name[24];

    // row and col after a player plays
    int actual_robot_row;
    int actual_robot_col;

    // row and col at the beginning of the round
    int initial_robot_row;
    int initial_robot_col;
} Robot;

#endif
