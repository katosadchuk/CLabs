// Kateryna Osadchuk

#include <stdio.h>
#include "my_string.h"

//returns the number of positions in which s1 and s2 differ, i.e., it returns the number of changes that would need to be made in order to transform s1 into s2, where a change could be a character substitution, an insertion, or a deletion.

int diff(char *s1, char *s2){
    int num = 0;
    int i = 0;
    int s1Length = 0;
    int s2Length = 0;
    
    while(s1[i] != NULL){
        s1Length++;
        i++;
    }
    
    i=0;
    while(s2[i] != NULL){
        s2Length++;
        i++;
    }
    
    if(s1Length > s2Length){
        num += s1Length - s2Length;
        i=0;
        while (s2[i] != NULL) {
            if(s2[i] != s1[i]){
                num++;
            }
            i++;
        }
    } else if(s1Length <= s2Length){
        num += s2Length - s1Length;
        i=0;
        while (s1[i] != NULL) {
            if(s2[i] != s1[i]){
                num++;
            }
            i++;
        }
    }
    return num;
}
