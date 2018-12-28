//
// Kateryna Osadchuk

#include <stdio.h>
#include "my_string.h"

//Returns a new string consisting of all of the characters of s1 and s2 interleaved with each other. For example, if s1 is "Spongebob" and s2 is "Patrick", the function returns the string "SPpaotnrgiecbkob"


char *str_zip(char *s1, char *s2){
    int length1 = 0;
    while (s1[length1] != '\0') {
        length1++;
    }
    int length2 = 0;
    while (s2[length2] != '\0') {
        length2++;
    }
    
    int max = 0;
    if(length1 >= length2){
        max = length1;
    } else {
        max = length2;
    }
    
    char s[length2 + length1 - 1];
    int i;
    for(i = 0; i < 2*max; i++){
        if(i%2 == 0){
            s[i] = *s1;
            s1++;
        } else {
            s[i] = *s2;
            s2++;
        }
    }
    
    if(length1 > length2){
        while(*s1 != '\0'){
            s[i] = *s1;
            i++;
            s1++;
        }
    } else if(length2 > length1) {
        while(*s2 != '\0'){
            s[i] = *s2;
            i++;
            s2++;
        }
    }
    
    char *t = s;
    return t;
}
