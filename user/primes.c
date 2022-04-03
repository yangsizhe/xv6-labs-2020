#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void seive(int lp[2] ){
    int first, num, status;
    if(read(lp[0], &first, sizeof(int))==0)
        exit(0);
    printf("prime %d\n", first);

    int pipefd[2];
    pipe(pipefd);
    while(read(lp[0], &num, sizeof(int))){
        if(num%first!=0){
            write(pipefd[1], &num, sizeof(int));
        }
    }
    close(lp[0]);
    close(pipefd[1]);
    int pid = fork();
    if(pid<0){
        printf("error\n");
        exit(0);
    }else if (pid>0){
        wait(&status);
    }else{
        seive(pipefd);
    }

    exit(0);
}

int main (){
    int status, pipefd[2];
    pipe(pipefd);
    for(int i = 2; i <= 35; i++){
        write(pipefd[1], &i, sizeof(int));
    }
    close(pipefd[1]);

    int pid = fork();
    if(pid<0){
        printf("error\n");
        exit(0);
    }else if (pid>0){
        wait(&status);
    }else{
        seive(pipefd);
    }
 
    exit(0);
}
