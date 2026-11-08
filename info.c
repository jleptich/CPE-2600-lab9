/*
    Name: Joseph Leptich
    Date: 11/7/2026
    Assignment: Lab9
    Description: Learning the fundementals behind system programming
*/
// info.c
#include <time.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <unistd.h>
#include <stdio.h>


int main(int argc, char* argv[])
{
    //Printing out the current time in nanoseconds
    struct timespec time; 
    clock_gettime(CLOCK_REALTIME, &time);
    printf("Current time in nanoseconds: %ld\n\n", time.tv_nsec);

    //printing out the systems information
    struct utsname sys_info;
    uname(&sys_info);
    printf("System Name: %s\n", sys_info.sysname);
    printf("Node Name: %s\n", sys_info.nodename);
    printf("Release: %s\n", sys_info.release);
    printf("Version: %s\n", sys_info.version);
    printf("Machine: %s\n", sys_info.machine);

    //printing out the number of processors the system has
    int num_processors = get_nprocs();
    printf("Number of processors used: %d\n", num_processors);

    int page_size = getpagesize();
    
    //logic and print statement for total free memory in the system
    long int total_memory = sysconf(_SC_PHYS_PAGES) * page_size;
    long int free_memory = sysconf(_SC_AVPHYS_PAGES) * page_size;
    printf("Total memory: %ld bytes\n", total_memory);
    printf("Free memory: %ld bytes\n", free_memory);


    return 0;
}