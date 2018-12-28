//
// Kateryna Osadchuk

#include <stdio.h>
#include "my_string.h"

//Returns the length of s1 - the length of s2


int len_diff(char *s1, char *s2){
    int s1Length = 0;
    int s2Length = 0;
    int diff = 0;
    
    int i = 0;
    while(s1[i] != NULL){
        s1Length++;
        i++;
    }
    
    i=0;
    while (s2[i] != NULL) {
        s2Length++;
        i++;
    }
    
    if(s1Length >= s2Length){
        diff = s1Length - s2Length;
    } else {
        diff = s2Length - s1Length;
    }
    
    return diff;
}
