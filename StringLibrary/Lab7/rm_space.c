//
// Kateryna Osadchuk

#include <stdio.h>
#include <ctype.h>
#include "my_string.h"

//removes whitespace characters from the beginning and the ending s

void rm_space(char *s){
    printf("[%s] without whitespaces is ", s);
    //remove at end
    int length = 0;
    while (s[length] != '\0') {
        ++length;
    }
    while(s[length-1] == ' ') {
        --length;
    }
    s[length] = '\0';
    
    //remove at beginning
    int numSpaces = 0;
    while(isspace(s[numSpaces])) {
        numSpaces++;
    }
    s += numSpaces;
    
    printf("[%s]\n\n", s);
    
}
