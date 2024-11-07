#include<stdio.h> 
#include<fcntl.h> 
#include<sys/stat.h> 
#include<unistd.h> 
#include<string.h> #define S_C "myfifo1" 
#define C_S "myfifo2" 
int main() 
{ 
char str[100]; 
char readbuf[80]; 
char temp[80]=""; 
int s2c,c2s; 
int i=0, j=0; 
printf("Create fifo\n"); mkfifo(S_C,0666); 
s2c = open(S_C,O_RDWR); 
printf("Enter a sentance:\n"); scanf("%[^\n]s",str); 
printf("Writing to myfifo1\n"); 
write(s2c,str,sizeof(str)); 
mkfifo(C_S,0777); 
c2s=open(C_S,O_RDWR); 
printf("\nReading from myfifo2\n"); 
read(c2s,readbuf,80); 
while(readbuf[i] != '\0'); 
{ 
while(readbuf[i] !=',') 
{ 
temp[j]=readbuf[i]; 
j++; 
j++; 
} 
temp[j]='\0'; 
printf("\n%s\n",temp); 
strcpy(temp,""); 
i++; j=0; 
} 
close(s2c); 
close(c2s); 
return 0; 
} 

