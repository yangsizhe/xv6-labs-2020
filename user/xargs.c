#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main (int argc, char *argv[]){
    int pid, n, status, index = 0;
    char *args[50], buf, arg[200];

    for(int i = 1; i < argc; i++){
        args[i-1] = argv[i];
    }

    while((n = read(0, &buf, 1))>0){
        if(buf =='\n'){
            arg[index] = 0;
            if((pid = fork())<0){
                printf("error\n");
                exit(0);
            }else if (pid>0){
                wait(&status);
                index = 0;
            }else{
                args[argc-1] = arg;
                args[argc] = 0;
                exec(args[0], args);
            }
        }else{
            arg[index++] = buf;
        }
        
    }
    exit(0);
}
