//
// Created by jgreene44 on 4/16/2019.
//
#include "Board.h"
#include <stdlib.h>
#if defined(_WIN32) || defined(_WIN64)
#define OS_WINDOWS
#endif

/// readBoard
/// method to read in a new board
/// \param b -> board being read in
/// \param fp ->file to be read
/// \return -> returns true or false based on if the board was created
int readBoard(Board * b, FILE * fp)
{
    if (fp == NULL) {
        return FALSE;
    }
    char buff[FILENAME_MAX];
    fgets(buff,5,fp);
    b->width = atoi(buff);
    fgets(buff,5,fp);
    b->height = atoi(buff);
    fgets(buff,10,fp);
    b->lifeCycles = atoi(buff);
    b->board = malloc(sizeof(char*)*b ->height);

    for(int i = 0; i <b->height; i++)
    {
        b->board[i] = malloc(sizeof(char)*b ->width);
        fgets(buff, MAX_WIDTH, fp);
        for (int j = 0; j< b->width; j++) {
            b->board[i][j] = buff[j];
        }
    }
    return TRUE;
}
/// allocateBoard
/// creates a board using the parameters
/// \param b -> board being read
/// \param fp ->file to be read
/// \return -> returns nothing
void allocateBoard(FILE * fp, Board ** b)
{
    *b = malloc(sizeof(Board));
    if(readBoard(*b, fp) == FALSE){
        *b = NULL;
    }
    else
    {
        (*b)->underDeath = 0;
        (*b)->overDeath =0;
        (*b)->reproduced=0;
    }
}
/// printBoard
/// method to print the board
/// \param b -> board being read
/// \return -> returns nothing
void printBoard(Board * b)
{
    for (int i = 0; i < b->width;i ++)
    {
        printf("_");
    }

    printf("\n");

    for (int i = 0; i < b->height; i++)
    {
        for(int j = 0; j < b->width; j++)
        {
            if (b->board[i][j] == OLD_CELL)
            {
                b->board[i][j] = DEAD_CELL;
            }
            else if(b->board[i][j] == NEW_CELL)
            {
                b->board[i][j] = LIVE_CELL;
            }
            printf("%c", b->board[i][j]);
        }
        printf("\n");
    }
}
/// countNeighbors
/// method to count the boards neighbors or cells
/// \param b -> board passed in
/// \param row -> row of the board
/// \param col -> column of the board
/// \return -> returns the count
int countNeighbors(Board b, int row, int col)
{
    int count = 0;
    for (int i = row-1; i <= row+1; i++)
    {
        for(int j = col-1; j<= col+1; j++)
        {
            if (i == row && j == col)
            {

            }
            else if(i >=0 && j>=0 && i<b.height && j<b.width)
            {
                if(b.board[i][j] == LIVE_CELL|| b.board[i][j] == OLD_CELL)
                {
                    count++;
                }
            }
        }
    }
    return count;
}
/// tickTime
/// updates the board and data corresponding to the board
/// \param b -> board passed in
/// \return -> returns nothing
void tickTime(Board * b)
{
    int count;
    for(int i = 0; i < b->height; i++)
    {
        for(int j = 0; j < b->width; j++)
        {
            count = countNeighbors(*b, i, j);
            if (count < UNDER_POPULATED && b->board[i][j] == LIVE_CELL)
            {
                b->board[i][j] = OLD_CELL;
                b->underDeath++;
            }
            else if(count > OVER_POPULATED && b->board[i][j] == LIVE_CELL)
            {
                b->board[i][j] = OLD_CELL;
                b->overDeath++;
            }
            else if(count == REPRODUCE && b->board[i][j]==DEAD_CELL)
            {
                b->board[i][j] = NEW_CELL;
                b->reproduced++;
            }
        }
    }
}
/// clear
/// clears the screen
/// \return -> returns nothing
void clear()
{
#ifdef OS_Windows
    system("cls");
#else
    system("clear");
#endif
}
