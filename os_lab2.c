#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char** argv) {
    FILE *fd1;
    char buf[10]="hello";
    fd1=open("File_1.txt",O_WRONLY);
    write(fd1,buf,sizeof(buf));
    close(fd1);
}