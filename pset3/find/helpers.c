/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    int first=0;
    int last=n;
    int middle=(0+n-1)/2;
    while(first<=last){
     if(values[middle]==value){
         return true;
     }
     if(value<values[middle]){
        
        last=middle-1; 
     }
     if(value>values[middle]){
         first=middle+1;
     }
     middle=(first+last)/2;
    }
    return false;
    }

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    for(int i=0;i<n;i++){
        for(int j=0;j<=n-i-1;j++){
            if(values[j+1]<values[j]){
                int temp=values[j];
                values[j]=values[j+1];
                values[j+1]=temp;
            }
        }
    }
    return;
}