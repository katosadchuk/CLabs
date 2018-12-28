//
// Kateryna Osadchuk
#include <stdio.h>
#include <ctype.h>
#include "my_string.h"

//returns 1 if suff is a suffix of s ignoring case or 0 otherwise.


int ends_with_ignore_case(char *s, char *suff){
    int lengthS = 0;
    while(s[lengthS] != '\0'){
        s[lengthS] = tolower(s[lengthS]);
        lengthS++;
    }
    
    int lengthSuff = 0;
    while(suff[lengthSuff] != '\0'){
        suff[lengthSuff] = tolower(suff[lengthSuff]);
        lengthSuff++;
    }
    
    int iteration = 1;
    for(int i = lengthSuff-1; i >= 0; i--){
        if(s[lengthS-iteration] == suff[i]){
            iteration++;
            continue;
        } else {
            return 0;
        }
    }
    return 1;
}
