#include "conversion.h"

bool characteristic(const char numString[], int& c)
{
    int counter = 1;
    int solution = 0;
    int currentInt;
    bool negativeNum = false;
    // This calls upon CheckValidChar to make sure the c-string only has numbers 0-9, '.', '+', '-', or ' '.
    if(CheckValidChar(numString) == false){
        return false;
    }
    // This calls upon CheckDecimalPoint to make sure the c-string only has one decimal point.
    if(CheckDecimalPoint(numString) == false){
        return false;
    }
    // This calls upon CheckSigns to make sure there is only one '+' or '-' and that it is at the start of the c-string.
    if(CheckSigns(numString) == false){
        return false;
    }
    // Checks if the number is negative
    if (numString[0] == '-') {
        negativeNum = true;
    }
    else if(numString[0] == '+'){
    }
    else {
        currentInt = ConvertToInt(numString[0]);
        solution = (solution * 10) + currentInt;
    }
    // Moves through the c-string until it reaches a '.' or the null terminator.
    while (numString[counter] != '.' && numString[counter] != '\0') {
        currentInt = ConvertToInt(numString[counter]);  // Converts the current character in the c-string to an integer.
        solution = (solution * 10) + currentInt;        // Formula used to get the correct final integer.
        counter++;
    }

    c = solution;
    if (negativeNum == true) {
        c = c * -1;
    }
    return true;
}

bool CheckSigns(const char numString[]) {
    bool retVal = true;
    int counter = 0;
    int numSigns = 0;
    // Moves through the c-string until it reaches a null terminator.
    while (numString[counter] != '\0') {
        // This if statement makes sure there is no '+' or '-' signs in the middle of the c-string.
        if (counter >= 1 && (numString[counter] == 43 || numString[counter] == 45)) {
            retVal = false;
            break;
        }
        counter++;
    }
    return retVal;
}


bool CheckDecimalPoint(const char numString[]){
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

int ConvertToInt(char currentCharacter) {
    int retVal;
    int currentVal = currentCharacter;
    // These if statements converts the current character in the c-string to its corresponding integer value.
    if (currentVal == 48) {
        retVal = 0;
    }
    else if (currentVal == 49) {
        retVal = 1;
    }
    else if (currentVal == 50) {
        retVal = 2;
    }
    else if (currentVal == 51) {
        retVal = 3;
    }
    else if (currentVal == 52) {
        retVal = 4;
    }
    else if (currentVal == 53) {
        retVal = 5;
    }
    else if (currentVal == 54) {
        retVal = 6;
    }
    else if (currentVal == 55) {
        retVal = 7;
    }
    else if (currentVal == 56) {
        retVal = 8;
    }
    else if (currentVal == 57) {
        retVal = 9;
    }
    return retVal;
}


bool CheckValidChar(const char numString[]){
    bool retVal = true;
    int counter = 0;
    char currentCharacter;
    // Moves through the c-string until it reaches a null terminator.
    while(numString[counter] != '\0'){
        currentCharacter = numString[counter];
        // These if statements makes sure that the current character is valid 
         if (currentCharacter == '0') {
            counter++;
            continue;
        }
        else if (currentCharacter == '1') {
            counter++;
            continue;
        }
        else if (currentCharacter == '2') {
            counter++;
            continue;
        }
        else if (currentCharacter == '3') {
            counter++;
            continue;
        }
        else if (currentCharacter == '4') {
            counter++;
            continue;
        }
        else if (currentCharacter == '5') {
            counter++;
            continue;
        }
        else if (currentCharacter == '6') {
            counter++;
            continue;
        }
        else if (currentCharacter == '7') {
            counter++;
            continue;
        }
        else if (currentCharacter == '8') {
            counter++;
            continue;
        }
        else if (currentCharacter == '9') {
            counter++;
            continue;
        }
        else if (currentCharacter == '.') {
            counter++;
            continue;
        }
        else if (currentCharacter == '+') {
            counter++;
            continue;
        }
        else if (currentCharacter == '-') {
            counter++;
            continue;
        }
        else if(currentCharacter == ' '){
            counter++;
            continue;
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
