#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<cs50.h>
int main(int argc,string argv[]){
    if(argc != 2){
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int key=atoi(argv[1]);
    if(key<=0)
    {
        return 2;
    }
    else{
        string ptext=GetString();
        for(int i=0,n=strlen(ptext);i<n;i++){
            if(isupper(ptext[i])){
                int temp=ptext[i]-65;
                int ctext=(temp+key)%26;
                ctext+=65;
                ptext[i]=(char)ctext;
            }
            else if(islower(ptext[i])){
                int temp=ptext[i]-97;
                int ctext=(temp+key)%26;
                ctext+=97;
                ptext[i]=(char)ctext;
            }
        }
    printf("%s\n",ptext);
        
        
        
    }
}
