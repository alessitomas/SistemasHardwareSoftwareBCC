#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *tarefa_print_i(void *arg){
    int *i = (int *) arg;
    printf("Conteúdo: %d\n", *i);
    return NULL;
}

void* createThread(void* arg){
    tarefa_print_i(arg);
    return NULL;
}


int main(){
    int * vi = malloc(sizeof(int) * 4);
    pthread_t * tids = malloc(sizeof(pthread_t)*4);

    for(int i = 0; i < 4; i++){
        vi[i] = i;
    }
    for(int i = 0; i < 4 ;i++){
        pthread_t tid;
        int error = pthread_create( &tid, NULL, createThread, vi+i);
        tids[i] = tid;
    }
    sleep(1);

}