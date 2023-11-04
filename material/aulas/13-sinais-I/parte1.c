#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

int main() {
    pid_t filho;

    filho = fork();
    if (filho == 0) {
        printf("Meu PID %d \n ", getpid());
        while (1);        
    }else{
        int status;
        int x = wait(&status);
        printf("Pid %d \n",x);
        printf("%d\n",status);

        sleep(10);
        int wait_return = waitpid(filho,&status, WNOHANG);
        printf(" wait_return: %d\n",status);
        if(wait_return ==0){
            printf("Ainda nao terminou, vou chamar o kill");
            kill(filho,SIGKILL);
            wait(&status);
        }else{
            printf("O processo filho terminou");
        }
        

        printf(
            "EXITED: %d\n"
            "SIGNALED: %d\n"
            "TERMSIG: %d\n"
            "ERROR: %s\n",
            WIFEXITED(status),
            WIFSIGNALED(status),
            WTERMSIG(status),
            strsignal(WTERMSIG(status))
        );
    }

    return 0;
}