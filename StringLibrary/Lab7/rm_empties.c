// Kateryna Osadchuk

#include <stdio.h>
#include "my_string.h"

//words is an array of string terminated with a NULL pointer. The function removes any empty strings (i.e., strings of length 0) from the array.

void rm_empties(char **words){
    int numWords = 0;
    int numRemoved=0;
    while(words[numWords] != NULL){
        numWords++;
    }
    for(int i = 0; i < numWords; i++){
        if(is_empty(words[i])){
            int num = i;
            while(words[num + 1] != NULL){
                words[num] = words[num+1];
                num++;
            }
            numRemoved++;
            i--;
        }
    }
    words[numWords - numRemoved] = '\0';
    
    
}
