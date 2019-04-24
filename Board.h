//
// Created by jgreene44 on 4/16/2019.
//
#include <stdio.h>
#define MAX_WIDTH  100
#define TRUE  1
#define FALSE 0
#define UNDER_POPULATED  2
#define OVER_POPULATED  3
#define REPRODUCE  3
#define LIVE_CELL  '0'
#define NEW_CELL  'n'
#define DEAD_CELL  '.'
#define OLD_CELL  'o'
#ifndef HOMEWORK3_ASSIGNMENT_BOARD_H
#define HOMEWORK3_ASSIGNMENT_BOARD_H

#endif //HOMEWORK3_ASSIGNMENT_BOARD_H

typedef struct Board
{
    int width;
    int height;
    int underDeath;
    int overDeath;
    int reproduced;
    int lifeCycles;
    char ** board;
}Board;

int readBoard(Board *, FILE *);
void allocateBoard(FILE *, Board**);
void printBoard(Board*);
int countNeighbors(Board, int, int);
void tickTime(Board *);
void clear();
