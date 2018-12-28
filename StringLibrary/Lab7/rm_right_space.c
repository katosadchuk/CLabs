// Kateryna Osadchuk

#include <stdio.h>
#include "my_string.h"

//removes whitespace characters from the end of s

void rm_right_space(char *s){
    printf("The string [%s] without right whitespace is ", s);
    int length = 0;
    while (s[length] != '\0') {
        ++length;
    }
    
    
    while(s[length-1] == ' ') {
        --length;
    }
    
    s[length] = '\0';
    printf("[%s]\n\n",s);
}
