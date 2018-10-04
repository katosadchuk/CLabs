/*
 Kateryna Osadchuk
 Sept 27 2018
 CIS 2107
 Lab #4 Part 1
 Design and implement functions for 2D arrays
 
 */

#include <stdio.h>
unsigned int rows;
unsigned int cols;

//display array
void displayOutputs(int array[][cols]){
    puts("Your 2D array is:");
    for(size_t i = 0; i<rows; ++i){
        for(size_t j = 0; j < cols; ++j){
            printf("%d\t", array[i][j]);
        }
        puts(" ");
    }
    puts(" ");
}

//find max in array
int max(int array[][cols]){
    int max = array[0][0];
    for(size_t i = 0; i<rows; ++i){
        for(size_t j = 0; j < cols; ++j){
            if(array[i][j] > max){
                max = array[i][j];
            }
        }
    }
    return max;
}

//calculate sum of each row
int rowSum(int array[][cols], int row){
    int sum = 0;
    for(size_t i = 0; i < cols; ++i){
        sum = sum + array[row][i];
    }
    
    return sum;
}

//calculate sum of each column
int columnSum(int array[][cols], int col){
    int sum = 0;
    for(size_t i = 0; i < rows; ++i){
        sum = sum + array[i][col];
    }
    return sum;
}

//print if array is square or not
void isSquare(){
    if(rows == cols){
        puts("This is a square array");
    }
    else {
        puts("This is not a square array");
    }
}

int main(int argc, const char * argv[]) {
    //get user input for array dimensions
    puts("Lets create a 2D array!");
    puts("How many rows?");
    scanf("%d", &rows);
    puts("How many columns?");
    scanf("%d", &cols);
    
    int array[rows][cols];
    
    //get data to store in array
    for(size_t i = 0; i<rows; ++i){
        for(size_t j = 0; j < cols; ++j){
            printf("Enter the number to store in array[%zd][%zd]:\n", i, j);
            int num;
            scanf("%d", &num);
            array[i][j] = num;
        }
    }
    
    //print max
    printf("The max of the array is: %d\n\n", max(array));
    
    //print sum of each row
    for(unsigned int i = 0; i < rows; i++){
         printf("The sum of row %d is %d\n", i, rowSum(array, i));
    }
    puts(" ");
    
    //print sum of each column
    for(unsigned int i = 0; i < cols; i++){
        printf("The sum of column %d is %d\n", i, columnSum(array, i));
    }
    puts(" ");
    
    //determine if array is square
    isSquare();
    puts(" ");
    
    //display array
    displayOutputs(array);
   
    
}
