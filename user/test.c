#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main (){
    int pipefd[2];
    char buf1[10], buf2[10], buf3[10];
    pipe(pipefd);
    //close(pipefd[1]);
    write(pipefd[1], "ping", 4);
    //close(pipefd[1]);
    write(pipefd[1], "pong", 4);
    close(pipefd[0]);
    read(pipefd[0], buf1, 4);
    printf("receive %s\n", buf1);
    read(pipefd[0], buf2, 4);
    printf("receive %s\n", buf2);
    read(pipefd[0], buf3, 4);
    printf("receive %s\n", buf3);
    
    exit(0);
}
