//
// Created by sgmason on 4/16/2019.
//
#include "Board.h"
#include <stdlib.h>

int readBoard(Board * b, FILE * fp)
{

    fopen("", "r");
    if (fp == NULL)
    {
        return FALSE;
    }
    char buff[255];
    int boardW = atoi(fgets(buff, 2, fp));
    int boardH = atoi(fgets(buff, 2, fp));
    int numGens = atoi(fgets(buff, 5, fp));

    Board ** newBoard;
    newBoard = malloc(boardW*sizeof(Board));
    for (int i = 0; i < boardW; i++)
    {
        newBoard[i] = malloc(boardH * sizeof(Board));
    }
    return 1;
}

void allocateBoard(FILE * fp, Board ** b)
{
}

void printBoard(Board * b)
{

}

int countNeighbors(Board b, int row, int col)
{

}

void tickTime(Board * b)
{

}

void clear()
{

}
