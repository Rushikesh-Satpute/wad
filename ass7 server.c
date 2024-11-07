#include<sys/types.h> #include<sys/ipc.h> 
#include <sys/shm.h> 
#include<stdio.h> 
#include<stdlib.h> 
#include <unistd.h> 
#define MAXSIZE 30 
void die(char *s) 
{ 
perror(s); 
exit(1); 
} 
int main() 
{ 
char c; int shmid; 
key_t key; 
— 
char *shm, *s; 
key=5678; 
if ((shmid=shmget(key,MAXSIZE,IPC_CREAT |0666))<0)die("shmat"); if((shm=shmat(shmid, NULL, 0))==(char *)-1)die("shmat"); 
printf("\n SERVER..!!"); 
printf("\n shmid=%d", shmid); 
s=shm; 
for(c='A';c <= 'Z';c++) 
*s++=c; 
while(*shm !='*') 
sleep(1); 
//if (shmdt(shm)==0) 
//printf("\n SERVER DETACHED SUCCESSFULLY..!!"); 
exit(0)} 

