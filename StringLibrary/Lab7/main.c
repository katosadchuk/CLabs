// Kateryna Osadchuk

#include <stdio.h>
#include "my_string.h"


int main(int argc, const char * argv[]) {
    
    //test all_letters
    char *s1 = "computer";
    int ret1 = all_letters(s1);
    if(ret1 == 1){
        printf("All characters in [%s] are letters\n\n", s1);
    } else {
        printf("Not all characters in [%s] are letters\n\n", s1);
    }
    
    char *t1 = "Hello there!";
    int retval1 = all_letters(t1);
    if(retval1 == 1){
        printf("All characters in [%s] are letters\n\n", t1);
    } else {
        printf("Not all characters in [%s] are letters\n\n", t1);
    }
    
    //test num_in_range
    char c1 = 'H';
    char c2 = 'r';
    int ret2 = num_in_range(t1, c1, c2);
    printf("The number of chars in [%s] between %c and %c is %d\n\n", t1, c1, c2, ret2);
    
    char *t2 = "This is a sentence.";
    char c3 = 'i';
    char c4 = '.';
    int retval2 = num_in_range(t2, c3, c4);
    printf("The number of chars in [%s] between %c and %c is %d\n\n", t2, c3, c4, retval2);
    
    
    //test diff
    char s2[] = "Temple";
    char *s3 = "Philly";
    int ret3 = diff(s2, s3);
    printf("The number of positions in which [%s] and [%s] differ is %d\n\n", s2, s3, ret3);
    
    //test shorten
    shorten(s2, 3);
    printf("After shortening to a length of 3, [Temple] becomes [%s]\n\n", s2);
   
    //test len diff
    char *t3 = "cats";
    char *t4 = "dogs";
    printf("The difference in length between [%s] and [%s] is %d\n\n", t3, t4, len_diff(t3, t4));
    
    char *t5 = "Hello world";
    char *t6 = "This is a sentence";
    printf("The difference in length between [%s] and [%s] is %d\n\n", t5, t6, len_diff(t5, t6));
    
    
    //test removing spaces
    char s4[] = "   hello   ";
    char t15[] = "   hello   ";
    rm_left_space(s4);
    rm_right_space(s4);
    rm_space(t15);
    
    //test find
    char *s5 = "hello";
    char *c = "lo";
    int n = find(s5, c);
    if(n == -1){
        printf("[%s] was not found in [%s]\n\n", c, s5);
    } else {
        printf("[%s] was found in [%s] at index %d\n\n", c, s5, n);
    }
    
    char *t7 = "I want to sleep";
    char *toFind = "cat";
    int retval3 = find(t7, toFind);
    if(retval3 == -1){
        printf("[%s] was not found in [%s]\n\n", toFind, t7);
    } else {
        printf("[%s] was found in [%s] at index %d\n\n", toFind, t7, retval3);
    }
    
    //test ptr_to
    char *ptr = ptr_to(s5, c);
    printf("The pointer to [%s] in [%s] is [%s]\n\n", c, s5, ptr);
    
    
    char *toFind2 = "want";
    char *ptr2 = ptr_to(t7, toFind2);
    printf("The pointer to [%s] in [%s] is [%s]\n\n", toFind2, t7, ptr2);
    
    //test is_empty
    int val = is_empty(s5);
    if(val == 0){
        printf("The string [%s] is not empty\n\n", s5);
    } else {
        printf("The string [%s] is empty\n\n", s5);
    }
    
    char *t8 = " ";
    int val2 = is_empty(t8);
    if(val2 == 0){
        printf("The string [%s] is not empty\n\n", t8);
    } else {
        printf("The string [%s] is empty\n\n", t8);
    }
    
    //test str_zip
    char s6[] = "Spongebob";
    char s7[] = "Patrick";
    char *s8 = str_zip(s6, s7);
    printf("[%s] interleaved with [%s] is [%s]\n\n", s6, s7, s8);
     
    //test capitalize
    char *s9 = "HeLlO tHerE world";
    capitalize(s9);
    
    //test strcmp_ign_case
    char s10[] = "bob";
    char s11[] = "baracuda";
    int retval4 = strcmp_ign_case(s10, s11);
    if(retval4 == 0){
        printf("The strings [%s] and [%s] are equal.\n\n", s10, s11);
    } else if(retval4 < 0){
        printf("The string [%s] appears before [%s].\n\n", s10, s11);
    } else {
        printf("The string [%s] appears after [%s].\n\n", s10, s11);
    }
    
    char t12[] = "baracuda";
    char t13[] = "baracuda";
    int retval5 = strcmp_ign_case(t12, t13);
    if(retval5 == 0){
        printf("The strings [%s] and [%s] are equal.\n\n", t12, t13);
    } else if(retval4 < 0){
        printf("The string [%s] appears before [%s].\n\n", t12, t13);
    } else {
        printf("The string [%s] appears after [%s].\n\n", t12, t13);
    }
    
    //test take_last
    char *s12 = "Hello";
    take_last(s12, 2);
    
    //test dedup
    char s13[] = "Hello there, general kenobi";
    char *s14 = dedup(s13);
    printf("After taking out duplicates, [%s] becomes [%s]\n\n", s13, s14);
     
    
    //test pad
    char s15[] = "123456";
    char *s16 = pad(s15, 4);
    printf("the string [%s] becomes [%s] after padding 4 spaces\n\n", s15, s16);
    
    //test ends_with_ignore_case
    char s17[] = "jumped";
    char s18[] = "eD";
    int retval6 = ends_with_ignore_case(s17, s18);
    if(retval6 == 1){
        printf("[%s] ends with [%s]\n\n", s17, s18);
    } else {
        printf("[%s] does not end with [%s]\n\n", s17, s18);
    }
    
    char t9[] = "jumped";
    char t10[] = "ing";
    int retval7 = ends_with_ignore_case(t9, t10);
    if(retval7 == 1){
        printf("[%s] ends with [%s]\n\n", t9, t10);
    } else {
        printf("[%s] does not end with [%s]\n\n", t9, t10);
    }
    
    //test repeat
    char s19[] = "all right";
    char *s20 = repeat(s19, 3, ',');
    printf("[%s] repeated 3 times with [,] as a deliminator is [%s]\n\n", s19, s20);
    
    
    //test replace
    char s21[] = "Hello world!";
    char pat[] = "world";
    char rep[] = "Professor";
    char *s22 = replace(s21, pat, rep);
    printf("Original string was [%s] and we replace [%s] with [%s] to get [%s]\n\n", s21, pat, rep, s22);
    
    char *s23[5] = {"These", "are", "words", "to", "connect"};
    puts("The words to connect are:");
    for(int i = 0; i < 5; i++){
        printf("%s\n", s23[i]);
    }
    
    //test str_connect
    char *s24 = str_connect(s23, 5, '-');
    printf("After connecting, the string is [%s]\n\n", s24);
    
    //test rm_empties
    char *s25[5] = {"Hello", "I am Kat", "", "", "Good bye"};
    int j = 0;
    while(s25[j] != NULL){
        j++;
    }
    printf("The number of strings we start with is: %d\n", j);
    rm_empties(s25);
    j = 0;
    while(s25[j] != NULL){
        j++;
    }
    printf("After removing the empty strings, we have %d strings in our array\n\n", j);
    
    //test str_chop_all
    char s26[] = "Hello there I am Kat";
    printf("The string to be chopped is [%s]\n", s26);
    str_chop_all(s26, ' ');
    
    char s27[] = "This-is-a-sentance-to-split-on-dash";
    printf("The string to be chopped is [%s]\n", s27);
    str_chop_all(s27, '-');
    
}
