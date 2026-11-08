/*
    Name: Joseph Leptich
    Date: 11/7/2026
    Assignment: Lab9
    Description: Learning the fundementals behind system programming
*/
// pinfo.c
#define _GNU_SOURCE 
#include <stdio.h>
#include <sched.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>


int main(int argc, char* argv[])
{
    //logic to see if the given pid is real or if there wasn't a pid given then the current pid is used
    int pid;
    if (argc == 2){
         pid = atoi(argv[1]);
         if(pid == 0 || pid > 32768){
         printf("This process ID does not exist\n");
         exit(1);
        }
    }
    else{
        pid = getpid();
    }

    //prints out the priority and pid being used
    int prio = getpriority(PRIO_PROCESS, pid);
    printf("Process ID: %d\n", pid);
    printf("Priority: %d\n", prio);


    int sched = sched_getscheduler(pid);
    if(sched == -1){
        perror("sched_getscheduler");
        exit(1);
    }
    //switching logic for the scheduling policy
    switch(sched){
        case SCHED_OTHER:
            printf("Scheduling policy: SCHED_OTHER\n");
            break;
        case SCHED_FIFO:
            printf("Scheduling policy: SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("Scheduling policy: SCHED_RR\n");
            break;
        case SCHED_BATCH:
            printf("Scheduling policy: SCHED_BATCH\n");
            break;
        case SCHED_IDLE:
            printf("Scheduling policy: SCHED_IDLE\n");
            break;
        default:
            printf("Scheduling policy: Unknown\n");
    }

    return 0;
}