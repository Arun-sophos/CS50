#include<stdio.h>
#include<cs50.h>

int main(void){
int height=24;
while(!(height>0 && height<=23)){
printf("Please Enter a Height:");
height=GetInt();
if(height==0){
    return 0;
}
}

for(int i=1;i<=height;i++){
for(int j=height;j>i;j--){
printf(" ");
}
for(int k=0;k<i;k++){
printf("#");
}
printf("#\n");
}
}

