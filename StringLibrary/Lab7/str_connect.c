// Kateryna Osadchuk

#include <stdio.h>
#include "my_string.h"
#include <stdlib.h>

//Returns a string consisting of the first n strings in strs with the character c used as a separator. For example, if strs contains the strings {"Washington", "Adams", "Jefferson"} and c is '+', the function returns the string "Washington+Adams+Jefferson"

char *str_connect(char **strs, int n, char c){
    int length = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; strs[i][j] != '\0'; j++){
            length++;
        }
    }
    
    char *new = (char*)malloc((length+n+1)*sizeof(char));
    
    int index = 0;
    int i;
    for(i = 0; i < n; i++){
        for(int j = 0; strs[i][j] != '\0'; j++){
            new[index+i] = strs[i][j];
            index++;
        }
        new[index+i] = c;
    }
    new[index+i-1] = '\0';
    return new;
}
