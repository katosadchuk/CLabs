// Kateryna Osadchuk

#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

//returns a new string based on s, but without any duplicate characters. For example, if s is the string, "There's always money in the banana stand.", the function returns the string "Ther's alwymonitbd.". It is up to the caller to free the memory allocated by the function.


char *dedup(char *s){
    int length = 0;
    while(s[length] != '\0'){
        length++;
    }
    
    char *new = (char *)malloc((length+1) *sizeof(char));
    char *ptr1 = new;
    char *ptr2 = new;
    
    int i = 0;
    while(s[i] != '\0'){
        ptr1 = new;
      
        while(*ptr1 != s[i] && *ptr1 != NULL){
            ptr1++;
        }
   
        if(*ptr1 == NULL){
            *ptr2 = s[i];
            ptr2++;
        }
        i++;
    }
    new[i-1] = '\0';
    
    return new;
}
