/*
 lab 11 - southie sherlock holmes
 Kateryna Osadchuk
 cis 2107
 12/10/18
 */


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAXLINESIZE 256
void checkForNewline(char *word);
int endsWith(char *word, char c);
void processWordInsideDialogue(char *in, char *out);
void makeItSouthy(char *in, char *out);
int isVowel(char c);

int main(int argc, const char * argv[]) {
    int insideDialogue = FALSE;
    char *inputLine = malloc(MAXLINESIZE+2);
    char *newLine = malloc(MAXLINESIZE*2+2);
    char *newWord = malloc(MAXLINESIZE*2+2);
    FILE *source = fopen("sherlock.txt", "rt");
    FILE *dest;
    if(source == NULL){
        printf("Error opening source file");
        return 1;
    }
    dest = fopen("southie-sherlock.txt", "wt");
    if(dest == NULL){
        printf("Error creating dest file");
        return 1;
    }
    //loop while source file has a new line to read
    while(fgets(inputLine, MAXLINESIZE, source) != NULL){
         //initializing new output string
        *newLine = 0;
        //split each line into words - use space as delimiter
        char *word = strtok(inputLine, " ");
        while(word != NULL){
            //clean up new line characters (ie \r \n) (if any) in word
            checkForNewline(word);
            //if word isn't inside dialogue
            if(!insideDialogue){
                //check if word begins with a quote mark - would signifiy the start of a dialogue - change boolean
                if(*word == '"')
                    insideDialogue = TRUE;
            }
            
            //add space between words (when line and word are not empty)
            if(strlen(newLine)!=0 && strlen(word)!=0){
                strcat(newLine, " ");
            }
            
            //check if word is inside dialogue
            if(insideDialogue){
                //process and change the word according to the southy rules - save it as newWord
                processWordInsideDialogue(word, newWord);
                
                //need to check if word ends with quote mark - signify end of dialogue
                if(endsWith(newWord, '"'))
                    insideDialogue=FALSE;
                //append modified word to the new line
                strcat(newLine, newWord);
            }else{
                //if the word is not in dialogue, just add it to the new line without processing
                strcat(newLine, word);
            }
            //get next word
            word = strtok(NULL, " ");
        }
        //add \n char to line since it was removed before processing
        strcat(newLine, "\n");
        //add new line to dest file
        fputs(newLine, dest);
    }
    //close all files and free memory
    fclose(source);
    fclose(dest);
    free(inputLine);
    free(newLine);
    free(newWord);
    return 0;
}


//this function will remove new line characters (\r \n) from the end of the word
//prevents buggy behavior when changing words
void checkForNewline(char *word){
    //search for first occurence of \r char
    char *tmp = strchr(word, '\r');
    //if doesn't find \r, search for \n
    if(tmp == NULL)
        tmp = strchr(word, '\n');
    // remove \r and \n characters from word if they are there
    if( tmp != NULL)
        *tmp = 0;
}

//check if a word ends with some char
int endsWith(char *word, char c){
    size_t len = strlen(word);
    //if the "word" is empty, return false
    if(len == 0)
        return FALSE;
    //move pointer to last character in word and check if it is c
    if(*(word+len-1) == c){
        return TRUE;
    }
    //if last characater isn't c, return false
    return FALSE;
}

//format word properly (punctuations and such) and make accent changes based on rules
void processWordInsideDialogue(char *in, char *out){
    char lastChar = 0;
    int beginWithQuote = FALSE;
    int endsWithQuote = FALSE;
    //check if word starts with "
    if(*in == '"'){
        in++;
        beginWithQuote = TRUE;
    }
    //check if word ends with "
    if(endsWith(in, '"')){
        *(in + strlen(in) - 1) = 0;
        endsWithQuote = TRUE;
    }
    //check if word ends with punctuation char
    lastChar = *(in + strlen(in) - 1);
    //if last character isn't a letter, cut it off and save last char
    if(!isalpha(lastChar)){
        *(in + strlen(in) - 1) = 0;
    }else{ //if last char is a letter, no need to cut it off or save what the last char is
        lastChar = 0;
    }
    //rebuild word with correct punctuations
    *out = 0;
    //add quote mark in beginning if it was on the original word
    if(beginWithQuote){
        strcat(out, "\"");
    }
    
    //make change to word based on rules
    makeItSouthy(in, out);
    
    //if last char on original word is punctuation, add it back
    if(lastChar != 0){
        size_t len = strlen(out);
        *(out + len) = lastChar;
        *(out + len + 1) = 0;
    }
    //add quote at end if it was in the original word
    if(endsWithQuote){
        strcat(out, "\"");
    }
}

//handles all accent changes based on rules
void makeItSouthy(char *in, char *out){
    //switch "very" for "wicked"
    if(strcasecmp(in, "very") == 0){
        strcat(out, "wicked");
        //no further processing needed so break out of function
        return;
    }
    
    //handles 2 exception cases
    if(endsWith(in, 'r')){
        char *wordPointer = in;
        size_t len = strlen(in);
        if(len > 3){
            
            //if ends with r and preceeded by "ee" or "i"
            //change "r" to "yah"
            if((*(wordPointer + len - 2) == 'i' )|| (*(wordPointer + len - 2) == 'e' && *(wordPointer + len - 3) == 'e')){
                strcpy(out, in);
                *(out+len-1) = 'y';
                *(out+len) = 'a';
                *(out+len+1) = 'h';
                
            }
            //if ends with r and preceeded by "oo"
            //change "r" to "wah"
            if((*(wordPointer + len - 2) == 'o' && *(wordPointer + len - 3) == 'o')){
                strcpy(out, in);
                *(out+len-1) = 'w';
                *(out+len) = 'a';
                *(out+len+1) = 'h';
                
            }
        }
        //end modification on word
        return;
        
    }
    
    //replace all r's following a vowel with an h
    char *rPointer = in;
    while(*rPointer != 0){
        if(isVowel(*rPointer) && *(rPointer + 1)=='r'){
            *(rPointer+1) = 'h';
        }
        rPointer++;
    }
    //concactenate modified "in" word into "out"
    strcat(out, in);
    //if word ends with 'a' but isn't the article "a", append an h
    if(endsWith(in, 'a')){
        if(strcmp(in, "a")!=0){
            strcat(out, "r");
        }
    }
}

//checks if char is a vowel - function just helps make cleaner clode
int isVowel(char c){
    return c=='a' || c=='e' || c=='i' || c =='o' || c=='u';
}

