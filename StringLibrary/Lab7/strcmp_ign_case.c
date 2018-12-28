//
// Kateryna Osadchuk

#include <stdio.h>
#include <ctype.h>
#include "my_string.h"

//Compares s1 and s2 ignoring case. Returns a positive number if s1 would appear after s2 in the dictionary, a negative number if it would appear before s2, or 0 if the two are equal.


int strcmp_ign_case(char *s1, char *s2){
    int retval = 0;
    int length1 = 0;
    int length2 = 0;
    
    while(s1[length1] != '\0'){
        s1[length1] = tolower(s1[length1]);
        length1++;
    }
    while(s2[length2] != '\0'){
        s2[length2] = tolower(s2[length2]);
        length2++;
    }
    
    if(length1 == length2){
        for(int j = 0; j < length1; j++){
            if(s1[j] < s2[j]){
                return -1;
            } else if (s1[j] > s2[j]) {
                return 1;
            }
        }
        return 0;
    } else if (length1 < length2){
        for(int j = 0; j < length1; j++){
            if(s1[j] < s2[j]){
                return -1;
            } else if (s1[j] > s2[j]) {
                return 1;
            } else {
                continue;
            }
        }
        retval = -1;
    } else if (length1 > length2){
        for(int j = 0; j < length2; j++){
            if(s1[j] < s2[j]){
                return -1;
            } else if (s1[j] > s2[j]) {
                return 1;
            }
        }
        retval = 1;
    }
    return retval;
}
