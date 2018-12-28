// Kateryna Osadchuk

#include <stdio.h>
#include "my_string.h"

//Shortens the string s to new_len. If the original length of s is less than or equal to new_len, s is unchanged

void shorten(char *s, int new_len){
    int i = 0;
    int sLength = 0;
    while(s[i] != NULL){
        sLength++;
        i++;
    }
    
    if(sLength > new_len){
        s[new_len] = '\0';
    }
}
