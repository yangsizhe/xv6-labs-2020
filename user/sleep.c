#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]){
    if(argc < 2){
        write(1, "no arg\n", 7);
    }else if(argc < 2){
        write(1, "one arg, please\n", 16);
    }else{
        int stime = atoi(argv[1]);
        sleep(stime);
    }
    exit(0);
}


