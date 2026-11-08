/*
    Name: Joseph Leptich
    Date: 11/7/2026
    Assignment: Lab9
    Description: Learning the fundementals behind system programming
*/

// pmod.c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char* argv[])
{
    //Changes the schedule priority of the program by decreasing priority by ten
    int change = nice(10);
    printf("New priority: %d\n", change);
    struct timespec ts;
    ts.tv_nsec = 837272639;
    ts.tv_sec = 1;

    //stalls the program for a given amount of time
    nanosleep(&ts, NULL);

    printf("Goodbye\n");

    return 0;
}