//
// Kateryna Osadchuk

#include <stdio.h>
#include "my_string.h"

//returns a pointer to the first occurrence of n in the string h or NULL if it isn't found


char *ptr_to(char *h, char *n){
    char *ptr = 0;
    int index = find(h, n);
    if(index == -1){
        ptr = 0;
    } else {
        ptr = &h[index];
    }
    
    return ptr;
}
