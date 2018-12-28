// Kateryna Osadchuk

#include <ctype.h>
#include <stdlib.h>
#include "my_string.h"
//Returns 1 if all of the characters in the string are either upper- or lower-case letters of the alphabet. It returns 0 otherwise

int all_letters(char *s){
    int i = 0;
    while(s[i] != '\0'){
        if(!isalpha(s[i])){
            return 0;
        }
        i++;
    }
    return 1;
}
