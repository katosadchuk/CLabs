// Kateryna Osadchuk

#include <stdio.h>
#include "my_string.h"

//returns the index of the first occurrence of n in the string h or -1 if it isn't found.

int find(char *h, char *n){
    int lengthN = 0;
    while (n[lengthN] != '\0') {
        lengthN++;
    }
    
    int index = -1;
    int num = 0;
    int i = 0;
    while(h[num] != '\0'){
        while(n[i] != '\0'){
            if(h[num + i] == n[i]){
                index = num;
                i++;
            } else {
                index = -1;
                break;
            }
        }
        num++;
    }
    return index;
}
