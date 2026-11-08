/*
    Name: Joseph Leptich
    Date: 11/7/2026
    Assignment: Lab9
    Description: Learning the fundementals behind system programming
*/
// finfo.c
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char* argv[])
{
    //the following conditional logic is to see if their is a file name given and if it exists
    if(argc < 2){
        printf("Please provide a file as an argument\n");
        exit(1);
    }
    char *file_name = argv[1];
    struct stat buff;

    int error_check = stat(file_name, &buff);
    if(error_check == -1){
        perror("Error with stat: ");
        exit(1);
    }



    //getting the file type
    mode_t file_type = (buff.st_mode & S_IFMT);
    //switch logic for what type of file it is
    switch(file_type){
        case(S_IFSOCK):
            printf("The file is a socket\n");
            break;
        case(S_IFLNK):
            printf("The file is a symbolic link\n");
            break;
        case(S_IFREG):
            printf("This file is a regular file\n");
            break;
        case(S_IFBLK):
            printf("This file is a block device\n");
            break;
        case(S_IFDIR):
            printf("The file is a directory\n");
            break;
        case(S_IFCHR):
            printf("The file is a character device\n");
            break;
        case(S_IFIFO):
            printf("This file is a FIFO\n");
            break;
        default:
            printf("No file type detected\n");
            break;
    }

    //following logic for determining the privileges on the file
    mode_t perm = (buff.st_mode & 0777);
    printf("Owner has access to the following privileges: ");
    if(perm & S_IRWXU){
        printf("read, write, execute");
    }
    else{
        if(perm & S_IRUSR){
            printf("read");
        }
        if(perm & S_IWUSR){
            printf(" write ");
        }
        if(perm & S_IXUSR){
            printf(" Execute ");
        }
    }
    printf("\n");
    printf("Groups have access to the following privilages: ");
    if(perm & S_IRWXG){
        printf("Read Write Execute");
    }
    else{
        if(perm & S_IRGRP){
            printf(" read ");
        }
        if(perm & S_IWGRP){
            printf(" write ");
        }
        if(perm & S_IXGRP){
            printf(" Execute ");
        }
    }
    printf("\n");
    printf("Global has access to the following permissions: ");
    if(perm & S_IRWXO){
        printf("Read Write Execute");
    }
    else{
        if(perm & S_IROTH){
            printf(" read ");
        }
        if(perm & S_IWOTH){
            printf(" Write ");
        }
        if(perm & S_IXOTH){
            printf(" Execute ");
        }
    }
    printf("\n\n");

    //Prints out the files owner id
    printf("File owner ID: %u\n", buff.st_uid);

    //prints the file size in bytes
    printf("The size of the file in bytes: %0lx\n", buff.st_size);

    time_t secs = buff.st_mtime;


    //uses the ctime function to convert st_mtime from seconds into a date 
    char *tim = ctime(&secs);
    if( tim == NULL){
        perror("Error with ctime function call: ");
        exit(1);
    }

    //prints the date
    printf("The file was last modified on: %s\n", tim);
    return 0;
}