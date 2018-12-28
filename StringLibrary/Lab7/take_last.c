//
// Kateryna Osadchuk

#include <stdio.h>
#include "my_string.h"

//Modifies s so that it consists of only its last n characters. If n is ≥ the length of s, the original string is unmodified. For example if we call take_last("Brubeck" 5), when the function finishes, the original string becomes "ubeck"

void take_last(char *s, int n){
    printf("[%s] after taking the last %d chars is ", s, n);
    int length = 0;
    
    while(s[length] != '\0'){
        length++;
    }
    
    if(n < length){
        for(int i = 0; i < length - n; i++){
            s++;
        }
    }
    
    printf("[%s]\n\n", s);
}
