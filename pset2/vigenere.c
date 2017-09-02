#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<cs50.h>
int main(int argc,string argv[]){
    if(argc != 2){
        printf("Usage: ./vigenere key\n");
        return 1;
    }
    string keyw=argv[1];
    for(int k=0,w=strlen(keyw);k<w;k++){
            if(isalpha(keyw[k])==0){
                printf("Invalid Key");
                return 1;
            }
    }
    
        
        for(int k=0;k<strlen(keyw);k++){
        }
        string ptext=GetString();
        int key=0;
        int i=0,j=0;
        
        for(int n=strlen(ptext);i<n;i++){
            if(isalpha(ptext[i])){
                int tem=j%strlen(keyw);
                key=toupper(keyw[tem])-65;
                j++;
            }
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
