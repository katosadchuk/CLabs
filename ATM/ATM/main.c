//Kateryna Osadchuk
// 9.13.18
// 2107 section 003
// homework 1 - ATM Lab
// Write a C Program  for  an  ATM  machine  by implementing functions.


#include <stdio.h>
#include <stdlib.h>
#define PIN 3014
//variable for balance, how much was deposited total, how much was withdrawn total, will be accessed by all functions
int bal = 5000;
int netDep = 0;
int netWithdrawl = 0;

//function to print balance
void balance(void){
    printf("Your balance is $%d.\n", bal);
}

//function to process withdrawls
void cashWithdrawl(void){
    int withdraw = 0;
    int attempts = 0;
    
    //first ask person how much do they want to withdraw
    puts("How much do you want to withdraw?");
    scanf("%d", &withdraw);
    attempts++;
    
    //handle improper values for withdrawl such as negative val, not multiples of 20, not enough balance, going past daily limit
    //runs until the user enters a valid amount
    while(!(withdraw > 0 && withdraw + netWithdrawl < 1000 && withdraw % 20 == 0 && withdraw < bal)){
       //handle negative & 0 amounts
        if(withdraw <= 0 && attempts <= 2){
            while(withdraw <= 0 && attempts <= 2){
                puts("Error, invalid value. Please try again");
                attempts++;
                scanf("%d", &withdraw);
            }
            
        }
        //if user enters a negative or 0 amount 3 times, program quits
        if(attempts == 3){
            puts("Too many unsuccessful attempts. Logging off...");
            exit(1);
        }
        
        //if user tries to withdraw more than $1000 a day
        if(withdraw + netWithdrawl > 1000){
            puts("Error, daily withdrawl limit is $1000. Please try again.");
            scanf("%d", &withdraw);
        }
        
        //if user enters an amount thats not a multiple of 20
        if(withdraw % 20 != 0){
            puts("This ATM only deposits $20 bills. Please make sure your value is a multiple of 20.");
            scanf("%d", &withdraw);
        }
        
        //if the user doesn't have enough money to withdraw
        if(withdraw > bal){
            printf("Error, you don't have enough money to withdraw $%d.\nPlease try again.\n", withdraw);
            scanf("%d", &withdraw);
        }
    }
    
    //update balance and total withdrawn after transaction
    bal = bal - withdraw;
    netWithdrawl = netWithdrawl + withdraw;
    
    //print receipt
    int choice = 0;
    puts("Would you like a receipt? 1 for yes, 2 for no.");
    scanf("%d", &choice);
    if(choice == 1){
        printf("You have withdrawn $%d. Your new balance is $%d.\n", withdraw, bal);
    }
   
}

void cashDeposit(void){
    int deposit = 0;
    int attempts = 0;
    
    //prompt user to enter how much they want to deposit
    puts("How much would you like to deposit?");
    scanf("%d", &deposit);
    attempts++;
    
    //check that amount entered is positive and total deposited is not past limit
    while (!(deposit + netDep < 10000 && deposit > 0)) {
        //prompts to re-enter amount if user enters a negative value or 0
        if(deposit <= 0 && attempts <= 2){
            while(deposit <= 0 && attempts <= 2){
                puts("Error, invalid value. Please try again");
                attempts++;
                scanf("%d", &deposit);
            }
        }
        
        //quit if user enters negative amount 3 times
        if(attempts == 3){
            puts("Too many unsuccessful attempts. Logging off...");
            exit(1);
        }
        //check to see if total deposited is not past limit
        if(deposit + netDep> 10000){
            puts("Error, daily deposit limit is $10,000. Please try again.");
            scanf("%d", &deposit);
        }
       
    }
    
    //update balance and total deposited
    bal = bal + deposit;
    netDep = netDep + deposit;
    
    //print receipt
    int choice = 0;
    puts("Would you like a receipt? 1 for yes, 2 for no.");
    scanf("%d", &choice);
    if(choice == 1){
        printf("You have deposited $%d. Your new balance is $%d.\n", deposit, bal);
    }
    
  
}

//quit program and print total number of transactions
void quit(int trans){
    printf("Thank you for using this ATM. You have made %d transactions.\n", trans);
    exit(0);
}



int main(int argc, const char * argv[]) {
    int pin;
    int pinAttempts = 0;
    
   //prompt user to enter pin
    printf("Welcome to this ATM! Please enter your PIN: ");
    scanf("%d", &pin);
    pinAttempts++;
    
    //if they enter the wrong pin, ask them to enter it again
    if(pin != PIN){
        while(pin != PIN && pinAttempts < 3){
            puts("Wrong PIN! Please try again.");
            scanf("%d", &pin);
            pinAttempts++;
        }
        //quit after three wrong attempts at entering pin
        if(pinAttempts == 3){
            puts("Error: You entered the wrong PIN too many times. Logging off...");
            exit(1);
        }
        
    }
    
    //if user enters correct pin, let them access their account
    if(pin == PIN){
        int choice = 0;
        int transactions = 0;
       
        //prints options
        printf("Welcome to your account. Please select an option:\n1 for Balance\n2 for Deposit Cash\n3 for Withdraw Cash\n4 for Quit\n");
        scanf("%d", &choice);
        
        //user selects option by entering a number. Can make multiple transactions or quit by pressing 4
        //user cannot enter random numbers
        while(choice != 4){
            if(choice == 1){
                balance();
            } else if(choice == 2){
                cashDeposit();
                transactions++;
            } else if(choice == 3){
                cashWithdrawl();
                transactions++;
            } else {
                puts("Error, not an option. Please try again:");
                scanf("%d", &choice);
                continue;
            }
            
            //check to see if user wants to make another transaction or quit
            printf("Make another transaction?\n1 for Balance\n2 for Deposit Cash\n3 for Withdraw Cash\n4 for Quit\n");
            scanf("%d", &choice);
        }
        
        //quits program when user enters 4
        if(choice == 4){
            quit(transactions);
        }
        
    }
    
    
}
