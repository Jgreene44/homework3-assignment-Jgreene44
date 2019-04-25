//
// Created by jgreene44 on 4/16/2019.
//
#include <stdio.h>
#include <time.h>
#include "Board.h"
/// main
/// main method being ran for this program
/// \param argc -> arguments
/// \param argv[] -> arguemtns
/// \return -> returns an int
int main(int argc, const char * argv[]){

    Board **b;
    int delay =200;
    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");

    if(fp == NULL){
        printf("File could not be opened");
        return 0;
    }

    allocateBoard(fp, b);
    fclose(fp);
    printBoard(*b);

    printf("press the enter key to continue...");
    getchar();

    struct timespec ts;
    ts.tv_sec = delay / 1000;
    ts.tv_nsec = (delay & 1000) * 1000000;

    for(int i = 0; i < (*b)->lifeCycles; i++){
        tickTime(*b);
        printBoard(*b);
        nanosleep(&ts, NULL);
    }
    clear();

    printf("Death by Overpopulation: %d\n", (*b)->overDeath);
    printf("Death by Underpopulation: %d\n", (*b)->underDeath);
    printf("Number of Reproductions: %d\n", (*b)->reproduced);
    getchar();
}
