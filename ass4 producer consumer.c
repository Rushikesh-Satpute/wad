#include<stdlib.h> 
#include<pthread.h> 
#include<semaphore.h> 
#include<sys/types.h> 
#include<unistd.h> 
#include<stdio.h> 
void* consumer(); void *producer(); pthread_t p,c; sem_t empty,full; pthread_mutex_t mutex; pthread_attr_t attr; 
int counter=0; 
int buffer[5]; 
void init() 
{ 
pthread_attr_init(&attr); 
sem_init(&full,0,0); 
sem_init(&empty,0,5); 
pthread_mutex_init(&mutex,NULL); 
} 
int main() 
{ 
int np,nc,i; 
init(); 
printf("Enter no of producers\n"); 
scanf("%d",&np); 
printf("Enter no of consumers\n"); 
scanf("%d",&nc); 
for(i=0;i<np;i++) 
{ 
pthread_create(&p,&attr,producer,NULL);//fuction does not return any value so it is null 
for(i=0;i<nc;i++) 
} 
{ 
} 
for(i=0;i<np;i++) 
pthread_create(&c,&attr,consumer,NULL); 
pthread_join(p,NULL); for(i=0;i<nc;i++) pthread_join(c,NULL); return 0; 
} 
void *producer() 
{ 
int item=rand()%100;//it can produce any item from 0 to 99.and it will be it double digit 
if(counter>=5)//check the buffer size wether it is full or not. 
printf("buffer full..Error\t"); 
sem_wait(&empty); 
pthread_mutex_lock(&mutex); if(counter<5) { 
buffer[counter]=item; 
counter++; 
printf("Producer produced %d\n",item); 
} 
pthread_mutex_unlock(&mutex); 
sem_post(&full); 
sleep(1); 
pthread_exit(0); 
} 
void *consumer() 
{ 
int item; 
if(counter==0)//chechk if buffer is empty or not. 
{ 
printf("buffer empty...Error\t"); 
return 0; 
} 
sem_wait(&full); 
pthread_mutex_lock(&mutex); 
if(counter>0) 
{ 
item=buffer[counter-1]; 
counter--; 
printf("consumer consumed %d\n",item); 
} 
pthread_mutex_unlock(&mutex); 
sem_post(&empty); 
sleep(1); 
pthread_exit(0); 
} 
