#include <iostream>
#include "conversion.h"

using namespace std;

bool characteristic(const char numString[], int& c)
{
    int counter = 1;
    int counter1 = 0;
    int counter2 = 0;
    int solution = 0;
    int currentInt;
    bool negativeNum = false;
    bool hitChar = false;
    bool hitSpace = false;
    string tempString;

    while (numString[counter1] != '\0') {
        if (numString[counter1] != ' ') {
            hitChar = true;
            tempString += numString[counter1];
        }
        if (hitChar == true && numString[counter1] == ' ') {
            hitSpace = true;
        }
        if (hitSpace == true && numString[counter1] != ' ') {
            return false;
        }
        counter1++;
    }
    tempString += '\0';
    counter1 = 0;
    char* fixedNumString = new char[tempString.length()];
    while (numString[counter1] != '\0') {
        if (numString[counter1] != ' ') {
            fixedNumString[counter2] = numString[counter1];
            counter2++;
        }
        counter1++;
    }
    fixedNumString[counter2] = '\0';

    // This calls upon CheckValidChar to make sure the c-string only has numbers 0-9, '.', '+', '-', or ' '.
    if(checkValidChar(numString) == false){
        return false;
    }
    // This calls upon CheckDecimalPoint to make sure the c-string only has one decimal point.
    if(checkDecimalPoint(numString) == false){
        return false;
    }
    // This calls upon CheckSigns to make sure there is only one '+' or '-' and that it is at the start of the c-string.
    if(checkSigns(numString) == false){
        return false;
    }
    // Checks if the number is negative
    if (numString[0] == '-') {
        negativeNum = true;
    }
    else if(numString[0] == '+'){ // This if statement is empty because we don't need to do anything if there is a plus sign but we need to skip over it if there is one present.
    }
    else {
        currentInt = convertToInt(numString[0]);
        solution = (solution * 10) + currentInt;
    }
    // Moves through the c-string until it reaches a '.' or the null terminator.
    while (numString[counter] != '.' && numString[counter] != '\0') {
        currentInt = convertToInt(numString[counter]);  // Converts the current character in the c-string to an integer.
        solution = (solution * 10) + currentInt;        // Formula used to get the correct final integer.
        counter++;
    }

    c = solution;
    if (negativeNum == true) {
        c = c * -1;
    }
    return true;
}

bool checkSigns(const char numString[]) {
    bool retVal = true;
    int counter = 0;
    int numSigns = 0;
    // Moves through the c-string until it reaches a null terminator.
    while (numString[counter] != '\0') {
        // This if statement makes sure there is no '+' or '-' signs in the middle of the c-string.
        if (counter >= 1 && (numString[counter] == '+' || numString[counter] == '-')) {
            retVal = false;
            break;
        }
        counter++;
    }
    return retVal;
}


bool checkDecimalPoint(const char numString[]){
    bool retVal = true;
    int counter = 0;
    int numDecimals = 0;
    // Moves through the c-string until it reaches a null terminator.
    while(numString[counter] != '\0'){
            if(numString[counter] == 46){
                numDecimals++;
            }
            counter++;
    }
    // This if statement makes sure there is only one decimal point in the c-string.
    if(numDecimals > 1){
        retVal = false;
    }
    return retVal;
}

int convertToInt(char currentCharacter) {
    int retVal;
    int currentVal = currentCharacter;
    // These if statements converts the current character in the c-string to its corresponding integer value.
    if (currentVal == '0') {
        retVal = 0;
    }
    else if (currentVal == '1') {
        retVal = 1;
    }
    else if (currentVal == '2') {
        retVal = 2;
    }
    else if (currentVal == '3') {
        retVal = 3;
    }
    else if (currentVal == '4') {
        retVal = 4;
    }
    else if (currentVal == '5') {
        retVal = 5;
    }
    else if (currentVal == '6') {
        retVal = 6;
    }
    else if (currentVal == '7') {
        retVal = 7;
    }
    else if (currentVal == '8') {
        retVal = 8;
    }
    else if (currentVal == '9') {
        retVal = 9;
    }
    else{
        cout << "Error when converting to an int.";
    }
    return retVal;
}


bool checkValidChar(const char numString[]){
    bool retVal = true;
    int counter = 0;
    char currentCharacter;
    // Moves through the c-string until it reaches a null terminator.
    while(numString[counter] != '\0'){
        currentCharacter = numString[counter];
        // These if statements makes sure that the current character is valid 
         if (currentCharacter == '0') {
            counter++;
        }
        else if (currentCharacter == '1') {
            counter++;
        }
        else if (currentCharacter == '2') {
            counter++;
        }
        else if (currentCharacter == '3') {
            counter++;
        }
        else if (currentCharacter == '4') {
            counter++;
        }
        else if (currentCharacter == '5') {
            counter++;
        }
        else if (currentCharacter == '6') {
            counter++;
        }
        else if (currentCharacter == '7') {
            counter++;
        }
        else if (currentCharacter == '8') {
            counter++;
        }
        else if (currentCharacter == '9') {
            counter++;
        }
        else if (currentCharacter == '.') {
            counter++;
        }
        else if (currentCharacter == '+') {
            counter++;
        }
        else if (currentCharacter == '-') {
            counter++;
        }
        else if(currentCharacter == ' '){
            counter++;
        }
        else {
            retVal = false;
            break;
        }
    }
    
    return retVal;
}
//--
bool mantissa(const char numString[], int& numerator, int& denominator)
{
    return true;
}
