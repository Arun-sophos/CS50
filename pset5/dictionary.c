/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *Arun
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <string.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include "dictionary.h"

#define LENGTH 45
#define H_SIZE 65536
int words=0;
unsigned int hashfn(const char* word){
    unsigned int hash=0;
    for(int i=0,n=strlen(word);i<n;i++){
        hash=(hash<<2)^word[i];
    }
    return hash%H_SIZE;
} 
typedef struct htable{
    char word[LENGTH+1];
    struct htable* next;
}node;
node* hashtable[H_SIZE];
/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    int l=strlen(word);
    char* copy=malloc(l);
    for(int i=0;i<l;i++){
        copy[i]=tolower(word[i]);
    }
    copy[l]='\0';
    unsigned index=hashfn(copy);
    if(hashtable[index]==NULL){
        return false;
    }
    else{
        node* cursor=hashtable[index];
        while(cursor->next!=NULL){
            if(strcmp(cursor->word,copy)==0)
            return true;
            
            cursor=cursor->next;
        }
        if(strcmp(cursor->word,copy)==0){
            return true;
        }
        
    }
    return false;
    
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    FILE *fp=fopen(dictionary,"r");
    if(fp==NULL){
        printf("Cannot open dictionary");
        return false;
    }
    char buffer[LENGTH+2];
    
     while(fgets(buffer,LENGTH+2,fp)){
         node*temp=(node*)malloc(sizeof(node));
     buffer[strlen(buffer)-1]='\0';
     strncpy(temp->word,buffer,LENGTH+1);
     temp->next=NULL;
     unsigned int index=hashfn(buffer);
     
     if(hashtable[index]==NULL){
         hashtable[index]=temp;
     }
     
     else{
         temp->next=hashtable[index];
         hashtable[index]=temp;
     }
    words++;
     }
    //printf("Loaded");
    return true;
}


/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return words;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    for(int i=0;i<H_SIZE;i++){
        if(hashtable[i]!=NULL){
        node* cursor=hashtable[i];
        while(cursor->next!=NULL){
            node*temp=cursor;
            cursor=cursor->next;
            free(temp);
        }
        }
        
    }
    return true;
}
