#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *func(void * var){
    sleep(2);
    printf("we are using thread\n");
    return NULL;
}

int main() {
    pthread_t t_id;
    printf("Before ursing thrading\n");
    pthread_create(&t_id, NULL, func, NULL);
    pthread_join(t_id, NULL);
    printf("After thrad\n");

    return 0;
}