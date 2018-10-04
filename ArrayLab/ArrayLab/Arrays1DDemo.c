/*
 Kateryna Osadchuk
 Sep 20 2018
 CIS2107
 Homework #3
 Processing 1D arrays
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//create global variables to store array and its size
int array[];
int size = 0;

//populate array with random ints
void fillArray(void) {
    int low = 0;
    int high = 0;
    
    //get user input for the size of the array and the range for the random numbers
    puts("What is the size of the array?");
    scanf("%d", &size);
    
    puts("What is the lower bound for the integers?");
    scanf("%d", &low);
    
    puts("What is the upper bound for the integers?");
    scanf("%d", &high);
    
    //populate array with random numbers in range
    srand(time(NULL));
    for(size_t i = 0; i < size; i++){
        int ran = rand() % (high + 1 - low) + low;
        array[i] = ran;
    }

    //print array
    puts("Array is: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d\t", array[i]);
    }
    puts(" ");
}

//find max in a range
void findWithRange(void){
    unsigned int lowIndex = 0;
    unsigned int highIndex = 0;
    int max = 0;
    
    //get user input for the indeces
    puts("What is the lower index?");
    scanf("%d", &lowIndex);
    
    puts("What is the higher index?");
    scanf("%d", &highIndex);
    
    //iterate through the range of the array and find max
    for(size_t i = lowIndex; i <= highIndex; i++){
        if(max < array[i]){
            max = array[i];
        }
    }
    
    //print out maximum
    printf("The max between index %d and index %d is: %d\n", lowIndex, highIndex, max);
}

//reverse array
void reverseArray(void){
    int reverse[size];
    puts("The reverse array is: ");
    //populate new array with values from original in reverse order
    //so first item of the reverse array is the last item of the original, etc.
    for(size_t i = 0; i < size; i++ ){
        reverse[i]=array[size - i - 1];
        //print the values, seperate with a tab
        printf("%d\t", reverse[i]);
    }
    puts(" ");
}

//reverse part of the array
void reverseRange(void){
    int arr[size];
    int low;
    int high;
    
    //ask for user input on the range
    puts("What is the lower index?");
    scanf("%d", &low);
   
    puts("What is the higher index?");
    scanf("%d", &high);
    
    //if the user enters bounds that are outside of size of array or negative
    if(high >= size || low < 0){
        puts("Error, index out of bounds! Please try again!");
        //runs function again
        reverseRange();
    }
    //if value of high is less than low, simply swap them
    if(high < low){
        int temp = high;
        high = low;
        low = temp;
       
    }
    //if everything is okay, so no out of bounds ranges & high < low
    if(high > low && high < size && low >= 0){
        //before range: copy original array into new array
        for(size_t i = 0; i < low; i++){
            arr[i] = array[i];
        }
        //in range: reverse by copying in values from original array to new array in reverse order
        for(size_t j = low; j <= high; j++){
            arr[j]=array[high - j + low];
        }
        //after range: copy original array into new array
        for(size_t k = high + 1; k < size; k++){
            arr[k] = array[k];
        }
        //prints the array
        for(size_t i = 0; i < size; i ++){
            printf("%d\t", arr[i]);
        }
        puts(" ");
    }
    
}

//find sequence in array
int findSequence(void){
    int index = -1;
    int first;
    int second;
    
    //get user input for the sequence they want
    puts("Enter the first item in the sequence:");
    scanf("%d", &first);
    
    puts("Enter the second item in the sequence:");
    scanf("%d", &second);
    
    //if the sequence exists, set "index" to the index of the first element
    for(size_t i = 0; i < size - 1; i++){
        if(array[i] == first && array[i+1] == second){
            index = i;
        }
    }
    
    return index;
}


int main(int argc, const char * argv[]) {
  
    //test all functions
    fillArray();
    
    findWithRange();
    
    reverseArray();
    
    reverseRange();
    
    int sequenceNum = findSequence();
    //prints if sequence exists, ie function returned value != -1
    if(sequenceNum != -1){
        printf("Sequence found at index %d\n", sequenceNum);
    }
    //prints if sequence doesn't exist, ie function returned -1
    else {
        puts("Sequence doesn't exist.");
    }
    
    
}
