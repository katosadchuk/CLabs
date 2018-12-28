//
// Kateryna Osadchuk

#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

//Returns a new string consisting of the characters in s repeated x times, with the character sep in between. For example, if s is the string all right, x is 3, and sep is , the function returns the new string all right,all right,all right. If s is NULL, the function returns NULL. It is up to the caller to free any memory allocated by the function.

char *repeat(char *s, int x, char sep){
    if(s == NULL){
        return NULL;
    }
    int length = 0;
    while(s[length] != '\0'){
        length++;
    }
    
    int newLength = 3*(length + 1);
    char *new = malloc(newLength*sizeof(char));
    
    for(int iter = 0; iter < x; iter++ ){
        for(int i = iter*length + iter; i < (1+iter)*length + iter; i++){
            new[i] = s[i-iter*length - iter];
        }
        new[(iter+1)*length+iter] = sep;
    }
    
    new[newLength-1] = '\0';

    return new;
}
