/*
	Producer / consumer example in C 
        semaphores/mutex based
        compile as: cc producer_consumer.c -o producer_consumer -lpthread
        Author: Angelo Poerio <angelo.poerio@gmail.com>
*/
 
#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <semaphore.h>

#define SHARED_SEM 1
#define CONSUMERS_NUM 5

sem_t empty, full;    
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int data;             


void *producer(void *arg) {
  int produced; 
  srand(time(NULL));
  while (1) {
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);
    printf("producer [%d]\n", produced);
    data = rand() % 1000000;
    pthread_mutex_unlock(&mutex);
    sem_post(&full);
  }
}

void *consumer(void *arg) {
  int total = 0, consumed;
  while (1) {
    sem_wait(&full);
    pthread_mutex_lock(&mutex);
    printf("consumer id: %lu [%d]\n", (unsigned long)pthread_self(), data);
    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
  }
}


int main(int argc, char *argv[]) {
  pthread_t producer_id;
  pthread_t consumer_ids[CONSUMERS_NUM];  
  int consumer_cnt = 0;
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);

  sem_init(&empty, SHARED_SEM, 1);  
  sem_init(&full, SHARED_SEM, 0);   

  pthread_create(&producer_id, &attr, producer, NULL);

  for(consumer_cnt = 0;consumer_cnt < CONSUMERS_NUM;consumer_cnt++)
  	pthread_create(&consumer_ids[consumer_cnt], &attr, consumer, NULL);
  
  pthread_join(producer_id, NULL);
  for(consumer_cnt = 0;consumer_cnt < CONSUMERS_NUM;consumer_cnt++)
  	pthread_join(consumer_ids[consumer_cnt], NULL);
}
