// Kateryna Osadchuk

#include <stdio.h>
#include <ctype.h>
#include "my_string.h"

//returns 1 if s is NULL, consists of only the null character ('') or only whitespace. returns 0 otherwise.

int is_empty(char *s){
    if(*s == NULL || *s == '\0'){
        return 1;
    }
    int i = 0;
    while (s[i] != '\0') {
        if(!isspace(s[i])){
            return 0;
        }
        i++;
    }
    return 1;
}
