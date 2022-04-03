#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main (){
    int pid, status, pipefd1[2], pipefd2[2];
    char buf = 'p' ;
    pipe(pipefd1);
    pipe(pipefd2);
    pid = fork();
    if(pid<0){
        printf("error\n");
        exit(1);
    }else if (pid>0){
        write(pipefd1[1], &buf, 1);
        read(pipefd2[0], &buf, 1);
        wait(&status);
        printf("%d: received pong\n", getpid());
        // printf("%d: receive pong\n", getpid());
    }else{      
        read(pipefd1[0], &buf, 1);
        printf("%d: received ping\n", getpid());
        // printf("%d: receive ping\n", getpid());
        write(pipefd2[1], &buf, 1);
    }
    exit(0);
}
