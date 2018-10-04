//
//  main.c
//  Test
//
//  Created by Kat Osadchuk on 9/27/18.
//  Copyright © 2018 Kat Osadchuk. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    /*
    unsigned int year = 365;
    unsigned int week = 7;
    unsigned int yearCount = 0;
    unsigned int weekCount = 0;
    unsigned int daysLeft = 0;
    
    puts("Enter a number: ");
    unsigned int num;
    scanf("%u", &num);
    
    yearCount = num / year;
    daysLeft = num % year;
    
    weekCount = daysLeft / week;
    daysLeft = daysLeft % week;
    
    printf("%u is %u years %u weeks %u days.", num, yearCount, weekCount, daysLeft);
     */
    
    puts("Enter an integer: ");
    int num;
    scanf("%d", &num);
    
    int numCopy = num;
    int reverse = 0;
    while(numCopy != 0){
        int n = numCopy % 10;
        reverse = reverse * 10 + n;
        numCopy = numCopy/10;
    }
    printf("The reverse is: %d", reverse);
    
    if(num == reverse){
        puts("Number is a palindrome");
    } else {
        puts("Number is not a palindrome");
    }
}
