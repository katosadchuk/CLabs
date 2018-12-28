//
// Kateryna Osadchuk

#include <stdio.h>
#include <ctype.h>
#include "my_string.h"

//Changes s so that the first letter of every word is in upper case and each additional letter is in lower case.


void capitalize(char *s){
    printf("Before capitalization the string is [%s]", s);
    int length = 0;
    while(s[length] != '\0'){
        length++;
    }
    
    int i = 0;
    char t[length+1];
    while(s[i] != '\0'){
        t[i] = tolower(s[i]);
        i++;
    }
    
    t[0] = toupper(t[0]);
    t[length] = '\0';
    
    for(int j = 1; j < length; j++){
        if(t[j-1] == ' '){
            t[j] = toupper(t[j]);
        }
    }
    
    s = t;
    printf(" and after it is [%s]\n\n", s);
}
