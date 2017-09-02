#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<string.h>
#include<cs50.h>
int main(void){
    string name=GetString();
    //int len=strlen(name);
    int i=0;
    while(name[i]!='\0'){
        printf("%c",toupper(name[i]));
        while(name[i]!='\0' && name[i]!=' '){
            i++;
        }
        i++;
    }
    printf("\n");
}