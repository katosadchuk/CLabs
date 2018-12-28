// Kateryna Osadchuk

#include <stdio.h>
#include <ctype.h>
#include "my_string.h"

//removes whitespace characters from the beginning of s

void rm_left_space(char *s){
    int numSpaces = 0;
    char *t = s;
    while(isspace(t[numSpaces])) {
        numSpaces++;
    }
    t += numSpaces;
    
    printf("[%s] without left spaces is [%s]\n\n", s, t );
    
}
