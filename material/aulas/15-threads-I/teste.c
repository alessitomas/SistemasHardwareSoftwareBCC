#include <pthread.h>
#include <stdio.h>

void *th1(void *arg) {
    printf("1-thread!\n");
    return NULL;
}
void *th2(void *arg) {
    printf("2-Hello thread!\n");
    return NULL;
}
void *th3(void *arg) {
    printf("3-Hello thread!\n");
    return NULL;
}
void *th4(void *arg) {
    printf("4-Hello thread!\n");
    return NULL;
}

int main() {
    pthread_t tid;
    
    int error1 = pthread_create(&tid, NULL, th1, NULL);
    int error2 = pthread_create(&tid, NULL, th2, NULL);
    int error3 = pthread_create(&tid, NULL, th3, NULL);
    int error4 = pthread_create(&tid, NULL, th4, NULL);


    printf("Hello main\n");
    sleep(1);
    
    return 0;
}