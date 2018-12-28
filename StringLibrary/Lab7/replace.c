// Kateryna Osadchuk
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "my_string.h"

//Returns a copy of the string s, but with each instance of pat replaced with rep, note that len(pat) can be less than, greater than, or equal tolen(rep). The function allocates memory for the resulting string, and it is up to the caller to free it. For example, if we call replace("NBA X", "X", "rocks"), what is returned is the new string NBA rocks (but remember, pat could be longer than an individual character and could occur multiple times).

char *replace(char *s, char *pat, char *rep){
    int lenTemp = 0;
    int lenPat = 0;
    int lenRep = 0;
    int lenS = 0;
    int k2 = 0;
    
    while (s[lenS] != '\0') {
        lenS++;
    }
    
    while (pat[lenPat] != '\0') {
        lenPat++;
    }
    while (rep[lenRep] != '\0') {
        lenRep++;
    }
    
    char *temp = s;
    char *new = malloc(2*lenS);
    
    int index = find(s, pat);
    while(index != -1){
        while (isprint(temp[lenTemp])) {
            lenTemp++;
        }
        
        for(int i = 0; i < index; i++){
            new[i] = temp[i];
        }
        
        int j1 = index;
        int j2 = 0;
        while(rep[j2] != '\0'){
            new[j1] = rep[j2];
            j1++;
            j2++;
        }
        
        
        int k1 = index+lenPat;
        k2 = index + lenRep;
        while(s[k1]!= '\0'){
            new[k2] = s[k1];
            k1++;
            k2++;
        }
        
        temp = new;
        index = find(new, pat);
        
    }
    new[k2] = '\0';
    
    return new;
}
