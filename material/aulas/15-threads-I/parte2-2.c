#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>  // Para a função sleep

struct entrada {
    int elemento;
    int startIndex;
    int index;
    int sliceSize;
    int *array;
    int *result;  // Para armazenar o resultado da busca
};

void *minha_thread(void *arg) {
    struct entrada *E = (struct entrada *)arg;

    for (int i = E->startIndex; i < E->startIndex + E->sliceSize; i++) {
        if (E->array[i] == E->elemento) {
            *(E->result) = i;  // Armazena o índice onde o elemento foi encontrado
            pthread_exit(NULL);  // Encerra a thread
        }
    }
    
    pthread_exit(NULL);  // Elemento não encontrado
}

int main() {
    int value;
    int arraySize;
    scanf("%d %d", &value, &arraySize);

    int *array = malloc(sizeof(int) * arraySize);
    for (int i = 0; i < arraySize; i++) {
        scanf("%d", array + i);
    }

    int qtdThreads;
    scanf("%d", &qtdThreads);

    pthread_t *tids = malloc(sizeof(pthread_t) * qtdThreads);
    struct entrada *entradas = malloc(sizeof(struct entrada) * qtdThreads);
    int result = -1;

    int sliceSize = arraySize / qtdThreads;

    for (int i = 0; i < qtdThreads; i++) {
        entradas[i].elemento = value;
        entradas[i].startIndex = i * sliceSize;
        entradas[i].sliceSize = sliceSize;
        entradas[i].array = array;
        entradas[i].result = &result;

        pthread_create(&tids[i], NULL, minha_thread, &entradas[i]);
    }

    for (int i = 0; i < qtdThreads; i++) {
        pthread_join(tids[i], NULL);
    }

    if (result != -1) {
        printf("Elemento %d encontrado pela thread %d no índice %d!\n", value, result / sliceSize, result);
    } else {
        printf("Elemento não encontrado!\n");
    }

    free(array);
    free(tids);
    free(entradas);

    return 0;
}
