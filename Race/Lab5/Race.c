/*
 Kateryna Osadchuk
 CIS 2107 Section 3
 10/4/2018
 Lab 5: Race - To design and implement functions to process pointers.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void moveTortoise(int *tortPoint){
    //get how much the tortoise moves
    int num = rand()%10 + 1 ;
    int move = 0;
    if(1 <= num && num <=5){
        move = 3;
    } else if(6 == num || num ==7){
        move = -6;
    } else if(8 <= num && num <=10){
        move = 1;
    }
    
    *tortPoint += move;
    
    //handles if tortoise is outside of the racing track
    if(*tortPoint < 1){
        *tortPoint = 1;
    }
    
    if(*tortPoint > 70){
        *tortPoint = 70;
    }
    

}

void moveHare(int *harePoint){
 
    //gets how much the hare moves
    int num = rand()%10 + 1 ;
    int move = 0;
    if(1 == num || num ==2){
        move = 0;
    } else if(3 == num || num ==4){
        move = 9;
    } else if(5 == num){
        move = -12;
    } else if(6 <= num && num <= 8){
        move = 1;
    } else if(9 == num || num == 10){
        move = -2;
    }
    
    *harePoint += move;
    
    // handle if hare is moved outside the racing track
    if(*harePoint < 1){
        *harePoint = 1;
    }
    
    if(*harePoint > 70){
        *harePoint = 70;
    }
}

void printPos(int *tortPos, int *harePos){
    //print if on the same square
    if(*tortPos == *harePos){
        for(unsigned int i = 0; i < *tortPos; i++){
            printf("%s", " ");
        }
        printf("%s", "OUCH");
    }
    else {
        //get which is ahead (max) and which is behind (min): tortoise or hare
        int min;
        int max;
        if(*tortPos < *harePos){
            min = *tortPos;
            max = *harePos;
        } else {
            min = *harePos;
            max = *tortPos;
        }
        
        //print empty spaces until first position (behind)
        for(unsigned int i = 1; i < min; i++){
            printf("%s", " ");
        }
        
        //print the one who is behind
        if(min == *tortPos){
            printf("%s", "T");
        } else {
            printf("%s", "H");
        }
       
        //print more empty spaces between the two animals
        for(unsigned int i = min + 1; i < max; i++){
            printf("%s", " ");
        }
        
        //print the one who is ahead
        if(max == *tortPos){
            printf("%s", "T");
        } else {
            printf("%s", "H");
        }
        
        
    }
    puts(" ");
    
}

int main(int argc, const char * argv[]) {
    srand(time(NULL));
    puts("BANG!!!!\nAND THEY'RE OFF!!!!");
   
    int tort = 1;
    int hare = 1;
    
    //while there is no winner, move the animals
    while(tort < 70 && hare < 70){
        moveHare(&hare);
        moveTortoise(&tort);
        printPos(&tort, &hare);
        sleep(1);
        
    }
    
    //tie
    if(hare == 70 && tort == 70){
        puts("It's a tie!");
        exit(0);
    }
    //hare wins
    if(hare == 70){
        puts("Hare wins. Yuch.");
        exit(0);
    }
    //tortoise wins
    if(tort == 70){
        puts("TORTOISE WINS! YAY!");
        exit(0);
    }
}
