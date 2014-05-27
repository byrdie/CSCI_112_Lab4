/* 
 * File:   main.c
 * Author: roy.smart
 *
 * Created on May 27, 2014, 11:04 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*function prototype declaration*/
void problem_1(char*, char);
void problem_2();
void problem_3(char*);
void extra_credit(int);

/*
 * 
 */
int main(int argc, char** argv) {
    char* path1 = "pangram.txt";
    char* path2 = "counto.txt";

    problem_1(path1, 'y');
    problem_2();
    problem_3(path2);
    extra_credit(10);

    return (EXIT_SUCCESS);
}

/*
 * Problem 1 reads the txt file specified by the input path and 
 * prints how many times the specified character is found
 */
void problem_1(char* input_path, char search_letter) {
    /*open input file for reading*/
    FILE* fp;
    fp = fopen(input_path, "r");

    /*Read file and loop to find matching letters*/
    char current_letter = NULL;
    int scan_result = 0;
    while (scan_result != -1) {
        scan_result = fscanf(fp, "%c", &current_letter);

        /*see if scanned letter matches*/
        if (current_letter == search_letter) {
            printf("The character %c has been found\n", current_letter);
        }
    }
}

/*problem 2 prints the value and demonstrates new operators */
void problem_2() {
    int i = 3;
    int j = 0;


    j = i++; /* this is statement C */
    printf("the value of j is %i \n", j);
    
    j = --i; /* this is statement B */
    printf("the value of j is %i \n", j);
    
    j = i--; /* this is statement D */
    printf("the value of j is %i \n", j);
    
    j = ++i; /* this is statement A */
    printf("the value of j is %i \n", j);
}


/*problem 3 prints out the number of adjacent O's per file*/
void problem_3(char* input_path){
    /*open input file for reading*/
    FILE* fp;
    fp = fopen(input_path, "r");
    
    /*loop through to find adjacent matches*/
    char current_letter = NULL;
    int scan_result = 0;
    while(scan_result != -1){
        scan_result = fscanf(fp, "%c", &current_letter);
        
        /*once letter O is found loop for the remainder of adjacent letters*/
        int num_letters = 0;
        while(current_letter == 'O' && scan_result != -1){
            scan_result = fscanf(fp, "%c", &current_letter);
            num_letters++;
        }
        
        /*if any adjacent letters were found print the number of finds*/
        if(num_letters){
            printf("A group of %d capital letter O's have been found together\n", num_letters);
        }
    }
}

/*extra credit prints out the first k powers of 2*/
void extra_credit(int k){
    int power_number = 1;
    int i = 0;
    while(i < k){
        power_number *= 2;
        printf("%d\n", power_number);
        i++;
    }
}