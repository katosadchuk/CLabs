/*
 Kateryna Osadchuk
 Lab 4: 2D Arrays
 9/27/2018
 CIS2107 Section 3
 */
#include <stdio.h>
#include <stdlib.h>
unsigned int rows;
unsigned int cols;

void printArray(int grades[][cols]);
void minimum(int grades[][cols]);
void maximum(int grades[][cols]);
void average(int grades[][cols]);
void end(int grades[][cols]);


int main(void){
    //array of pointers to functions
    void (*f[5])(int grades[][cols]) = {printArray, minimum, maximum, average, end};
    
    //get dimensions of array of grades
    puts("Enter the number of students:");
    scanf("%d", &rows);
    puts("Enter the number of grades to enter:");
    scanf("%d", &cols);
    
    int grades[rows][cols];
    
    //get data: actual grades for each student
    for(size_t i=0; i < rows; ++i){
        printf("Enter grades for student %zd:\n", i+1);
        for(size_t j=0; j < cols; ++j){
            printf("Grade number %zd\n", j+1);
            int num;
            scanf("%d", &num);
            grades[i][j] = num;
        }
    }
    
    //get user entry for which function to execute
    printf("Enter a choice:\n\t0 to print grades\n\t1 to get minimum grade\n\t2 to get maximum grade\n\t3 to get average for each student\n\t4 to quit\n");
    unsigned int choice;
    scanf("%u", &choice);
    
    while(choice >= 0 && choice < 5){
        (*f[choice])(grades);
        puts(" ");
        puts("Enter another choice:");
        scanf("%u", &choice);
    }
    
    
}

//prints array of grades
void printArray(int grades[][cols]){
    puts("The array of grades is: ");
    for(size_t i=0; i < rows; ++i){
        printf("Student %zd\t", i + 1);
        for(size_t j=0; j < cols; ++j){
            printf("%d\t", grades[i][j]);
        }
        puts(" ");
    }
}

//gets lowest grade
void minimum(int grades[][cols]){
    int min = 100;
    for(size_t i=0; i < rows; ++i){
        for(size_t j=0; j < cols; ++j){
            if(grades[i][j] < min){
                min = grades[i][j];
            }
        }
    }
    printf("The minimum grade is %d\n", min);
}

//gets highest grade
void maximum(int grades[][cols]){
    int max = 0;
    for(size_t i=0; i < rows; ++i){
        for(size_t j=0; j < cols; ++j){
            if(grades[i][j] > max){
                max = grades[i][j];
            }
        }
    }
    printf("The maximum grade is %d\n", max);
}

//prints average for each student
void average(int grades[][cols]){
    for(size_t i=0; i < rows; ++i){
        int total = 0;
        for(size_t j=0; j < cols; ++j){
            total = total + grades[i][j];
        }
        float avg = (float) total/cols;
        printf("The average for Student %zd is %0.2f\n", i+1, avg);
    }
}

//ends program
void end(int grades[][cols]){
    puts("Thank you for using this program. Goodbye.");
    exit(0);
}
