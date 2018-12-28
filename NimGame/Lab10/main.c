/*
 Kateryna Osadchuk
 Nim Game - lab 10
 Nov 15 2018
 CIS 2107
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


static unsigned int pileA = 5;
static unsigned int pileB = 7;
static unsigned int pileC = 6;

void printInstructions(void){
    printf("There are three piles of coins: A has %d, B has %d, and C has %d\n", pileA, pileB, pileC);
    puts("Each player will choose a pile and select one or more coins from the pile.");
    puts("The player who chooses the last coin loses.");
}

char getPile(char player[]){
    printf("%s, pick a pile.\n", player);
    char select;
    scanf(" %c", &select);
    
    if(!(select == 'a' || select == 'b' || select == 'c' || select == 'A' || select == 'B' || select == 'C')){
        puts("Error! Invalid input. Try again.");
        getPile(player);
    }

    return select;
}

int getNum(char player[]){
    puts("Enter the number of coins to take");
    int num;
    scanf("%d", &num);
    
    return num;
}

bool checkLegalMove(int pileNum, int numTake){
    if(numTake > pileNum){
        puts("Error! The pile doesn't have enough coins. Try again.");
        return false;
    }
    if(numTake < 0 || numTake == 0){
        puts("Error! You must take at least one coin.");
        return false;
    }

    return true;
    
}

bool checkIfEmpty(char pile){
    if(pile == 'a' || pile == 'A'){
        if(pileA == 0){
            puts("Error! Pile A is empty. Try again.");
            return true;
        }
    }
    if(pile == 'b' || pile == 'B'){
        if(pileB == 0){
            puts("Error! Pile B is empty. Try again.");
            return true;
        }
    }
    if(pile == 'c' || pile == 'C'){
        if(pileC == 0){
            puts("Error! Pile C is empty. Try again.");
            return true;
        }
    }
    
    return false;
}

void updatePiles(char pile, int num){
    if(pile == 'a' || pile == 'A'){
        pileA = pileA - num;
    } else if(pile == 'b' || pile == 'B'){
        pileB = pileB - num;
    } else {
        pileC = pileC - num;
    }
}

void playRound(char player[]){
    char pile = getPile(player);
    bool isEmpty = checkIfEmpty(pile);
    while(isEmpty){
        pile = getPile(player);
        isEmpty = checkIfEmpty(pile);
    }
    int num = getNum(player);
    
    bool legal = false;
    while(!legal){
        if(pile == 'a' || pile == 'A'){
            legal = checkLegalMove(pileA, num);
        } else if(pile == 'b' || pile == 'B'){
            legal = checkLegalMove(pileB, num);
        } else {
            legal = checkLegalMove(pileC, num);
        }
        
        if(legal == false){
            pile = getPile(player);
            num = getNum(player);
        }
    }
    updatePiles(pile, num);
}

void printCounters(void){
    printf("A: ");
    for(int i = 0; i < pileA; i++){
        printf("%c ", '*');
    }
    puts(" ");
    
    printf("B: ");
    for(int i = 0; i < pileB; i++){
        printf("%c ", '*');
    }
    puts(" ");
    
    printf("C: ");
    for(int i = 0; i < pileC; i++){
        printf("%c ", '*');
    }
    puts(" ");
}


int main(int argc, const char * argv[]) {
    puts("Welcome to the Nim Game!");
    
    char p1[15];
    char p2[15];
    char *loser = 0;
    char *winner = 0;
    puts("Player 1, enter your name:");
    scanf("%s", p1);
    puts("Player 2, enter your name:");
    scanf("%s", p2);
    
    puts("Would you like to see the instructions? Press 1 for yes and 0 for no.");
    int option;
    scanf("%d", &option);
    if(option == 1){
        printInstructions();
    }
    
    puts("Let's begin!");
    
    bool haveWinner = false;
    while(!haveWinner){
        printCounters();
        playRound(p1);
        if(pileA + pileB + pileC == 1){
            loser = p2;
            winner = p1;
            haveWinner = true;
            break;
        }
        
        printCounters();
        playRound(p2);
        if(pileA + pileB + pileC == 1){
            loser = p1;
            winner = p2;
            haveWinner = true;
            break;
        }

    }
    printCounters();
    printf("Game Over!\nThere is one coin left so the winner is %s and the loser is %s.\n", winner, loser);
    

}
