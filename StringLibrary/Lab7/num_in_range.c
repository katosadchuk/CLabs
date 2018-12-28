
// Kateryna Osadchuk

#include <stdio.h>
#include "my_string.h"

//returns the number of characters c in s1 such that b<=c<=t

int num_in_range(char *s1, char b, char t){
    int num = 0;
    int i = 0;
    while(s1[i] != NULL){
        if(s1[i] == b){
            num++;
            int j = i+1;
            while(s1[j] != t){
                if(s1[j] == NULL){
                    return -1;
                }
                num++;
                j++;
            }
            num++;
            break;
        }
        i++;
    }
    return num;
}
