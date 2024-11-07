#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void reverseArray(int a[10],int n);
void main(int argc, char *argv[],char *envp[])
{
int i,n=0;
int a[10];
for (i=1;argv[i]!=NULL;i++)
{
a[i]=strtol(argv[i],NULL,10);
n++;
}
printf("\n");
printf("\n In Second child process id is :%d",getpid());
printf("\n My parent's process id is:%d",getppid());
reverseArray(a,n);
}
void reverseArray(int a[10],int n)
{
int start=1;
int end=n-1;
int temp;
while (start < end)
{
temp=a[start];
a[start]=a[end];
a[end]=temp;
start++;
end--;
}
int i;
printf("\n Reverse of Array:");
for(i=1;i<n;i++)
{
printf("\t %d",a[i]);
}
