#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    int rodando = 0;
    pid_t pai ,filho;
    filho = fork();
    filho = fork();
    filho = fork();
    if(filho !=0){

        pai = getppid();
        filho = getpid();
        printf("PID DO PAI %d, MEU PID %d\n", pai,filho);
    }
    else{
        pai = getppid();
        filho = getpid();
        printf("PID DO PAI %d, MEU PID %d\n",pai,filho);
    }
    return 0;
}
