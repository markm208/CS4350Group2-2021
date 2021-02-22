#include "conversion.h"

bool characteristic(const char numString[], int& c)
{
    if(CheckValidChar(numString) == false){
        return false;
    }
    return true;
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
