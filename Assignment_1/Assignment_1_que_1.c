/*
Que: Accept file name from user and open it using open(), print success message with file descriptor 
with error handling using perror(). 
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    // If user does not provide file name using command-line arg, return from here itself.
    if (argc < 2)
    {
        printf("Syntax: %s <file_name>\n", argv[0]);
        return -1;
    }
    
    int fd = 0;
    fd = open(argv[1], O_RDONLY);

    if (fd < 0)
    {
        perror("Error opening file");
    }
    else
    {
        printf("%s file opened successfully with fd: %d\n", argv[1], fd);
    }

    close(fd);
    return 0;
}