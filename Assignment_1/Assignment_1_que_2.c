/*
Que: Accept file name from user and open it using open(), print success message with file descriptor 
with error handling using perror(). 
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // If user does not provide file name and mode using command-line arg, return from here itself.
    if (argc < 3)
    {
        printf("Syntax: %s <file_name> <file_mode>\nFile modes can be any from [R, W, RW, A]\n", argv[0]);
        return -1;
    }
    
    int fd = 0, flags = 0;
    
    if(strcmp(argv[2], "r") == 0 || strcmp(argv[2], "R") == 0)
    {
        flags += O_RDONLY;
    }
    else if(strcmp(argv[2], "w") == 0 || strcmp(argv[2], "W") == 0)
    {
        flags += O_WRONLY;
    }
    else if(strcmp(argv[2], "rw") == 0 || strcmp(argv[2], "RW") == 0 ||
            strcmp(argv[2], "wr") == 0 || strcmp(argv[2], "WR") == 0)
    {
        flags += O_RDWR;
    }
    else if(strcmp(argv[2], "a") == 0 || strcmp(argv[2], "A") == 0)
    {
        flags += O_APPEND + O_CREAT;
    }
    else
    {
        flags = -1;
    }

    fd = open(argv[1], flags);

    if (fd < 0)
    {
        perror("Error opening file");
    }
    else
    {
        printf("%s file opened successfully with fd in mode %s\n", argv[1], argv[2]);
    }

    close(fd);
    return 0;
}