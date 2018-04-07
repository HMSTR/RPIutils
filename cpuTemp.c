#include<stdio.h>
#define TEMP_PATH "/opt/vc/bin/vcgencmd measure_temp"
#define SIZE_A 10
int main(){
FILE *pipe = popen(TEMP_PATH,"r");
char value[SIZE_A];
int i=0,j=0;
fgets(value,SIZE_A,pipe);
while(value[i++]!='=' && i<SIZE_A);
while(i+j<SIZE_A){
 value[j]=value[i+j];
 j++;
}
for(i=j+1;i<SIZE_A;i++)
 value[i]=0;
printf("%s",value);
pclose(pipe);
}
