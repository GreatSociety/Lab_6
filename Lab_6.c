//
// Created by Great_Society on 17.01.2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compareValueBrackets(char *userString);

int recursiveVerification (char *userString);

int main(){

    char *inputString = malloc(256);
    char *pAnswer = malloc(2);

    do {

        puts("Please, write a string for verify:");
        fgets(inputString, 256, stdin);

        compareValueBrackets(inputString);
        //recursiveVerification(inputString);

        puts("You wanta verify another string? (Y/N)");
        fgets(pAnswer,2,stdin);
        fflush(stdin);

    } while (*pAnswer == 'Y'|| *pAnswer == 'y');

    return 0;
}

/******************************** Function for compare number of brackets *********************************/

int compareValueBrackets(char *userString){

    int counter_Standard = 0;
    int counter_Square = 0;
    int counter_Figure = 0;
    int flag = 0;

    for (int i = 0; i < strlen(userString); i++) {

        // скобка открывается
        if (userString[i] == '(' || userString[i] == '[' || userString[i] == '{') {

            flag = 1; // в этой строке точно есть скобки

            if (userString[i] == '(') {
                ++counter_Standard;

            } else if (userString[i] == '[') {
                ++counter_Square;

            } else {
                ++counter_Figure;

            }
        }

        // скобка закрывается

        else if (userString[i] == ')' || userString[i] == ']' || userString[i] == '}') {

            if (userString[i] == ')') {
                --counter_Standard;

            } else if (userString[i] == ']') {
                --counter_Square;

            } else {
                --counter_Figure;
            }

        }
    }


    if (!flag) {
        return puts("This line has no brackets");
    }
    else{
        if (!counter_Standard && !counter_Square && !counter_Figure){
            recursiveVerification(userString);
            return puts("Very Well!"); //"Brackets equality passed!"
        }
        else{
            return puts("No equality of opening and closing brackets, or type of.");

        }

    }
}

/*********************** Function for verify correct placement of brackets (within recursive) ********************/

int recursiveVerification (char *userString){

    if(*userString == '\0'){
        return puts("String is complete verification");
    }

    if (*userString == '(' || *userString == '[' || *userString == '{' ){
        if(*(userString+1) == '*' || *(userString+1) == '/' || *(userString+1) == '+'
        || *(userString+1) == '^' || *(userString+1) == '\0'){

            puts((userString+1));
            return puts("False in open brackets");
        }
        else recursiveVerification(++userString);
    }
    else if(*userString == ')' || *userString == ']' || *userString == '}' ){

        if(*(userString+1) == '(' || *(userString+1) == '[' || *(userString+1) == '{' ){
            return puts("False in close brackets");
        }
        else recursiveVerification(++userString);

    }
    else recursiveVerification(++userString);
}