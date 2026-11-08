# README FOR LAB 9

## PART 1 INFORMATION MAINTENANCE SYSTEM CALLS IN FILE INFO.C
Within this file I used and understood the fundamentals of clock_gettime, uname, gethostname, get_nprocs, sysconf, and getpagesize.
With these newly discovered functions they could be applied to finding information about the system currently being used, time of day,
as well as total memory as well as memory left in the system

## PART 2 PROCESS CONTROL SYSTEM CALLS IN FILES PINFO.C AND PMOD.C
Looked into and discovered how PIDs are used and ran within a system by having scheduling and different priorities based on what the PID is. 
Used getpid, getpriority, and sched_getscheduler to determine the priority, schedule ID of a given PID to the system.
In PMOD learned about nice and nanosleep. 

## PART 3 FILE MANAGEMENT SYSTEM CALLS IN FINFO.C 
Took a look under the hood of how I/O works within C on a low level with systems. Used the stat function call to get information about a user specified file
and from their was able to determine what the file was, who had what permissions, the file size, the files owners ID, and the date and time of the last modification of the file


### THANK YOU FOR READING THE README
