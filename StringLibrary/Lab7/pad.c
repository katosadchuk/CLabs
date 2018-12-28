//
// Kateryna Osadchuk

#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

//returns a new string consisting of all of the letters of s, but padded with spaces at the end so that the total length of the returned string is an even multiple of d. If the length of s is already an even multiple of d, the function returns a copy of s. The function returns NULL on failure or if s is NULL. Otherwise, it returns the new string. It is up to the caller to free any memory allocated by the function.

char *pad(char *s, int d){
    if(s == NULL){
        return NULL;
    }
    
    int length = 0;
    while(s[length] != '\0'){
        length++;
    }
    
    if((length % d == 0) && (length % 2 == 0)){
        return s;
    }
    
    int newLength = length;
    while ((newLength % d != 0) || (newLength %2 != 0)) {
        newLength++;
    }
    
    char *new = (char *)malloc(newLength*sizeof(char));
    for(int i = 0; i < length; i++){
        new[i] = s[i];
    }
    
    for(int j = length; j < newLength; j++){
        new[j] = ' ';
    }
    new[newLength] = '\0';

    return new;
}
