#include<stdio.h>
#include<cs50.h>
#include<math.h>
int main(void){
float money=-2;
int coin=0,cents;
printf("Hello!How much changeis owed?");

while(money<0){
money=GetFloat();
if(money<0){
    printf("Enter positive");
}
}

money*=100;
money=round(money);
cents=money;

coin=cents/25;
cents%=25;

coin+=cents/10;
cents%=10;

coin+=cents/5;
cents%=5;

coin+=cents;

printf("%d\n",coin);
}
