#include "conversion.h"

bool characteristic(const char numString[], int& c)
{
    int counter = 1;
    int solution = 0;
    int currentInt;
    bool negativeNum = false;
    if(CheckValidChar(numString) == false){
        return false;
    }

    if (numString[0] == '-') {
        negativeNum = true;
    }
    else if(numString[0] == '+'){
    }
    else {
        currentInt = ConvertToInt(numString[0]);
        solution = (solution * 10) + currentInt;
    }

    while (numString[counter] != '.') {
        currentInt = ConvertToInt(numString[counter]);
        solution = (solution * 10) + currentInt;
        counter++;
    }

    c = solution;
    if (negativeNum == true) {
        c = c * -1;
    }
    return true;
}

int ConvertToInt(char currentCharacter) {
    int retVal;
    int currentVal = currentCharacter;
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
    while(numString[counter] != '\0'){
        currentCharacter = numString[counter];
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
