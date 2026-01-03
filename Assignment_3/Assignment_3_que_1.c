#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<errno.h>

#define BUFSIZE 1024

int main(int argc,char *argv[])
{
    int fdSrc,fdDest;
    ssize_t bytesRead,bytesWritten;
    char buffer[BUFSIZE];
    struct stat statObj;

    if(argc!=3)
    {
        printf("ERROR: Invalid arguments\nSYNTAX: %s <source_file> <destination_file>\n",argv[0]);
        exit(-1);
    }

    fdSrc=open(argv[1],O_RDONLY);
    if(fdSrc==-1)
    {
        printf("%s\n",strerror(errno));
        exit(-1);
    }

    if(stat(argv[1],&statObj)==-1)
    {
        printf("%s\n",strerror(errno));
        close(fdSrc);
        exit(-1);
    }

    fdDest=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,statObj.st_mode);
    if(fdDest==-1)
    {
        printf("%s\n",strerror(errno));
        close(fdSrc);
        exit(-1);
    }

    while((bytesRead=read(fdSrc,buffer,BUFSIZE))>0)
    {
        bytesWritten=write(fdDest,buffer,bytesRead);
        if(bytesWritten!=bytesRead)
        {
            printf("%s\n",strerror(errno));
            close(fdSrc);
            close(fdDest);
            exit(-1);
        }
    }

    if(bytesRead==-1)
    {
        printf("%s\n",strerror(errno));
    }

    chmod(argv[2],statObj.st_mode);

    close(fdSrc);
    close(fdDest);

    printf("File copied successfully.\n");
    return 0;
}
