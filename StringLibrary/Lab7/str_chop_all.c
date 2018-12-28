// Kateryna Osadchuk

#include <stdio.h>
#include "my_string.h"

//Returns an array of string consisting of the characters in s split into tokens based on the delimeter c, followed by a NULL pointer. For example, if s is "I am ready for a nice vacation" and c is ' ', it returns {"I", "am", "ready", "for", "a", "nice", "vacation", NULL}

char **str_chop_all(char *s, char c){
    int i = 0;
    int numToks = 1;
    while(s[i] != '\0'){
        if(s[i] == c){
            numToks++;
        }
        i++;
    }
    char listWords[numToks+ 1][20];
   
    int index = 0;;
    int j = 0;
    while(s[j] != '\0'){
        char word[20];
        int wordIndex = 0;
        int len = 0;
        
        while (s[j] != c && s[j] != '\0') {
            word[wordIndex] = s[j];
            j++;
            wordIndex++;
            len++;
        }
        word[len] = '\0';
        for(int i = 0; i < len; i++){
            listWords[index][i] = word[i];
        }
        listWords[index][len] = '\0';

        j++;
        index++;
    }
    listWords[index][0] = NULL;
    
    int k = 0;
    puts("Which becomes the tokens: ");
    while(listWords[k][0] != NULL){
        printf("%s\n", listWords[k]);
        k++;
    }
    
    char **listWordsPtr = listWords;
    return listWordsPtr;
}
