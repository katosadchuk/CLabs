/*
 Kateryna Osadchuk
 CIS2107
 Lab 6: Manual
 10/11/18
 
 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//used to clear scanner later on
char temp;


//function 1 - converts string to upper and lower case
void upperLower(void){
    puts("Enter a string to convert to uppercase and lowercase");
    char s[100];
    scanf("%[^\n]s", s);
    
    char upperString[100];
    char lowerString[100];
    int index = 0;
    while(s[index] != '\0'){
        int c = toupper(s[index]);
        int d = tolower(s[index]);
        upperString[index] = c;
        lowerString[index] = d;
        index++;
    }
    
    puts("Upper case is: ");
    printf("%s\n", upperString);

    puts("Lower case is: ");
    printf("%s\n", lowerString);
    
}

//function 2 - convert strings to ints and find sum
void convertStrToInt(void){
    puts("Enter four integers as strings:");
    char s1[100], s2[100], s3[100], s4[100];
    scanf("%s", s1);
    scanf("%s", s2);
    scanf("%s", s3);
    scanf("%s", s4);
    
    int num1, num2, num3, num4 = 0;
    num1 = atoi(s1);
    num2 = atoi(s2);
    num3 = atoi(s3);
    num4 = atoi(s4);
    int sum = num1 + num2 + num3 + num4;
    
    printf("The sum is %d\n", sum);
}

//function 3 - convert strings to floats and find sums
void convertStrToFloat(void){
    puts("Enter four floats as strings:");
    char s1[100], s2[100], s3[100], s4[100];
    scanf("%s", s1);
    scanf("%s", s2);
    scanf("%s", s3);
    scanf("%s", s4);
    
    float num1 = atof(s1);
    float num2 = atof(s2);
    float num3 = atof(s3);
    float num4 = atof(s4);
    float sum = num1 + num2 + num3 + num4;
    
    printf("The sum is %f\n", sum);
}

//function 4 - compare strings
void compareStr(void){
    char s1[100], s2[100];
    puts("Enter first string to compare:");
    scanf("%s", s1);
    puts("Enter second string to compare:");
    scanf("%s", s2);
    
    int result = strcmp(s1, s2);
    if(result == 0){
        puts("The strings are equal.");
    } else if(result < 0){
        printf("[%s] is less than [%s]\n", s1, s2);
    } else {
       printf("[%s] is greater than [%s]\n", s1, s2);
    }
}

//function 5 - compare first n chars of two strings
void comparePartialStr(void){
    char s1[100], s2[100];
    size_t numChar;
    puts("Enter first string to compare:");
    scanf("%s", s1);
    puts("Enter second string to compare:");
    scanf("%s", s2);
    puts("Enter number of characters to compare:");
    scanf("%zu", &numChar);
    
    int result = strncmp(s1, s2, numChar);
    if(result == 0){
        printf("The first %zu characters of [%s] are equal to [%s]\n", numChar, s1, s2 );
    } else if(result < 0){
         printf("The first %zu characters of [%s] are less than [%s]\n", numChar, s1, s2 );
    } else {
        printf("The first %zu characters of [%s] are greater than [%s\n", numChar, s1, s2 );
    }
}

// function 8 - print a line in reverse order
void reverse(char *string1){
    //count number of words
    int numWords = 1;
    for(size_t i = 0; i < strlen(string1); i++){
        if(isspace(string1[i])){
            numWords++;
        }
    }
    
    //get tokens and store in array
    char *tokenPtr = strtok(string1, " ");
    char *array[numWords];
    int i=0;
    while(tokenPtr !=NULL){
        array[i] = tokenPtr;
        tokenPtr = strtok(NULL," ");
        i++;
    }
    
    //iterate through array of tokens in reverse order
    puts("The reverse is:");
    for(int j = numWords - 1; j >=0; j--){
        printf("%s\n", array[j]);
    }
}

//function 9 - count occurences of a substring
void countSubstr(void){
    puts("Enter a line of text:");
    scanf("%c", &temp); //clears scanner memory
    char text[300];
    scanf("%[^\n]s", text);
    
    puts("Enter a string to search for:");
    scanf("%c", &temp);//clears scanner
    char strSearch[100];
    scanf("%s", strSearch);
    
    int occurences = 0;
    char *ptr = text;
    while(ptr = strstr(ptr, strSearch)){
        occurences++;
        ptr++;
    }
    printf("The string [%s] occurs %d times\n", strSearch, occurences);

}

//function 10 - count occurence of a char in a string
int countChar(char text[], char charSearch){
    int occurences = 0;
    char *ptr1 = text;
    while(ptr1 = strchr(ptr1, charSearch)){
        occurences++;
        ptr1++;
    }
    return occurences;
}

//function 11 - get counts for each letter in alphabet
void countAlpha(void){
    puts("Enter a line of text:");
    scanf("%c", &temp);//clear scanner
    char text[500];
    scanf("%[^\n]s", text);

    int counts[26];
    char letter[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
   
    for(size_t i = 0; i < 26; i++){
        //get counts for each letter in alphabet, count upper and lower case as the same
        int num1 = countChar(text, letter[i]);
        int num2 =countChar(text, tolower(letter[i]));
        counts[i] = num1+num2;
    }
    
    for(size_t i = 0; i < 26; i++){
        printf("%c: %d\t",letter[i], counts[i]);
    }
    puts(" ");
}

//function 12 - count number of words
void countWords(void){
    puts("Enter a line of text:");
    char string[100];
    scanf("%c", &temp);
    scanf("%[^\n]s", string);
    char stringcpy[strlen(string)];
    
    int counts1 = 0;
    int counts2 = 0;
    
    strcpy(stringcpy, string);
    
    //count using spaces
    char *tokenPtr1 = strtok(string, " ");
    while(tokenPtr1 !=NULL){
        tokenPtr1 = strtok(NULL," ");
        counts1++;
    }
    
    //count using new line
    char *tokenPtr2 = strtok(stringcpy, "\n");
    while(tokenPtr2 !=NULL){
        tokenPtr2 = strtok(NULL,"\n");
        counts2++;
    }
    
    
    int total = counts1+counts2-1;
    printf("There are %d words\n", total);
}

//function 13 - print all strings beginning with b
void startsWithB(void){
    puts("Enter number of strings you will enter:");
    int num;
    scanf("%c", &temp);
    scanf("%d", &num);
    
    puts("Enter strings:");
    char word[100];
    char allStrings[num][100];
    
    //get user input and store in array
    for(size_t i = 0; i < num; i++){
        scanf("%c", &temp);
        scanf("%s", word);
        strcpy(allStrings[i], word);
    }
    
    //print all beginning with b
    for(size_t i = 0; i < num; i++){
        if(allStrings[i][0] == 'b' || allStrings[i][0] == 'B'){
            printf("%s\n", allStrings[i]);
        }
    }
   
}

//function 14 - print all ending with ed
void endsWithed(void){
    puts("Enter number of strings you will enter:");
    int num;
    scanf("%c", &temp);//clear scanner
    scanf("%d", &num);
    
    //store strings in array
    puts("Enter strings:");
    char word[100];
    char allStrings[num][100];
    
    
    for(size_t i = 0; i < num; i++){
        scanf("%c", &temp);
        scanf("%s", word);
        strcpy(allStrings[i], word);
    }
    
    //print all where last char is d and second to last is e
    for(size_t i = 0; i < num; i++){
        size_t last = strlen(allStrings[i])-1;
        size_t secondToLast = strlen(allStrings[i])-2;
        if(allStrings[i][last] == 'd' && allStrings[i][secondToLast] == 'e'){
            printf("%s\n", allStrings[i]);
        }
    }
}

//function 6 - make random sentences
void randomize(void){
    char *article[] = {"the", "a", "one", "some", "any"};
    char *noun[] = {"boy", "girl", "town", "car", "dog"};
    char *verb[] = {"drove", "jumped", "ran", "walked", "skipped"};
    char *preposition[] = {"to", "from", "over", "under", "on"};
    char sent[300];
    
    puts("Here is a story:");
    //make 20 sentences
    for(unsigned i=0; i < 20; i++){
        
        int ran1 = rand()%5;
        char *word = article[ran1];
        strcat(sent, word);
        strcat(sent, " ");
        
        int ran2 = rand()%5;
        char *word2 = noun[ran2];
        strcat(sent, word2);
        strcat(sent, " ");
        
        int ran3 = rand()%5;
        char *word3 = verb[ran3];
        strcat(sent, word3);
        strcat(sent, " ");
        
        int ran4 = rand()%5;
        char *word4 = preposition[ran4];
        strcat(sent, word4);
        strcat(sent, " ");
        
        int ran5 = rand()%5;
        char *word5 = article[ran5];
        strcat(sent, word5);
        strcat(sent, " ");
        
        int ran6 = rand()%5;
        char *word6 = noun[ran6];
        strcat(sent, word6);
        strcat(sent, ".");
        
        //capitalize first letter of each word
        sent[0] = toupper(sent[0]);
        printf("%s\n", sent);

        memset(sent, 0, 300);
    }
    puts("The end!");
        
}

//function 7 - tokenize phone number
void tokenizeTelNum(char *num){
    char lastSeven[8] = {0};
    char areaCode[4] = {0};
    
    char *tokenPtr = strtok(num, " ( ) ");
    strncpy(areaCode, tokenPtr, 3);
    
    tokenPtr = strtok(NULL, " - ");
    strcat(lastSeven, tokenPtr);
    
    tokenPtr = strtok(NULL, " ");
    strcat(lastSeven, tokenPtr);
  
    char *rem;
    long last = strtol(lastSeven, &rem, 0);
    
    printf("Area code is: %d\n", atoi(areaCode));
    printf("Phone number is: %ld\n", last);
    
  

    

    
    
}


int main(int argc, const char * argv[]) {
    
    //test functions
    upperLower();
    convertStrToInt();
    convertStrToFloat();
    comparePartialStr();
    compareStr();
    countSubstr();
    
    //test for count char
    char string1[300];
    puts("Enter a line of text");
    scanf("%c", &temp);
    scanf("%[^\n]s", string1);
    int num = countChar(string1, 'b');
    printf("'b' occurs %d times in the string [%s]\n", num, string1);
    
    //test for reverse
    char string2[300];
    puts("Enter a line of text");
    scanf("%c", &temp);
    scanf("%[^\n]s", string2);
    reverse(string2);
    
    //test more functions
    countAlpha();
    countWords();
    startsWithB();
    endsWithed();
    
    
    //test randomize
    srand(time(0));
    randomize();
    
    //test tokenize
    char phone[15] = "(215) 800-1111";
    printf("The number to tokenize is: [%s]\n", phone);
    tokenizeTelNum(phone);
    return 0;
}
