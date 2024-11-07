#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void bubbleSort(int a[],int n);
pid_t id;
void main() {
int a[10], n, i;
char *argv[12];
for(i=0; i<12; i++) {
argv[i] = (char *) malloc(20);
}
printf("\n\nENTER NUMBER OF ELEMENTS: ");
scanf("%d", &n);
printf("\nENTER THE ELEMENTS:");
for(i=0; i<n; i++) {
scanf("%d", &a[i]);
}
printf("\n PARENT PROCESS \n PARENT PROCESS ID IS: %d", getpid());
bubbleSort(a,n);
switch(id = fork()) {
case -1: printf("\nERROR IN FORK");
break;
case 0: printf("\n CHILD PROCESS \n CHILD PROCESS ID IS:\n %d ", getpid());
printf("\nPARENT PROCESS ID OF CHILD PROCESS IS:\n: %d ", getppid());
for(i=0; i<n; i++) {
sprintf(argv[i+1], "%d", a[i]);
}
argv[0] = "ass2b";
argv[n+2] = NULL;
printf("\n");
execv("ass2b", argv);
printf("\nERROR");
break;
default: printf("\nSORTED ELEMENTS:\n");
for(i=1;i<n;i++) printf(" %d", a[i]);
printf("\n");
sleep(5);
printf("\nEND OF PARENT PROCESS\n.");
}
}
void bubbleSort(int a[],int n) {
int i,j,temp;
for(i=0; i<n; i++) {
for(j=0; j<n-1; j++) {
if(a[j] > a[j+1]) {
temp = a[j];
a[j] = a[j+1];

a[j+1] = temp;
}
}
}
printf("\n");
}
