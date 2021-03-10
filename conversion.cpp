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
    bool isNum = false;

    while (numString[counter1] != '\0') {
        if (numString[counter1] != ' ') {
            hitChar = true;
            counter2++;
        }
        if (hitChar == true && numString[counter1] == ' ') {
            hitSpace = true;
        }
        if (hitSpace == true && numString[counter1] != ' ') {
            return false;
        }
        if (numString[counter1] >= '0' && numString[counter1] <= '9') {
            isNum = true;
        }
        counter1++;
    }
    if (isNum == false) {
        return false;
    }
    counter1 = 0;
    counter2++;
    char* fixedNumString = new char[counter2];
    counter2 = 0;
    while (numString[counter1] != '\0') {
        if (numString[counter1] != ' ') {
            fixedNumString[counter2] = numString[counter1];
            counter2++;
        }
        counter1++;
    }
    fixedNumString[counter2] = '\0';

    // This calls upon CheckValidChar to make sure the c-string only has numbers 0-9, '.', '+', '-', or ' '.
    if(checkValidChar(fixedNumString) == false){
        return false;
    }
    // This calls upon CheckDecimalPoint to make sure the c-string only has one decimal point.
    if(checkDecimalPoint(fixedNumString) == false){
        return false;
    }
    // This calls upon CheckSigns to make sure there is only one '+' or '-' and that it is at the start of the c-string.
    if(checkSigns(fixedNumString) == false){
        return false;
    }
    // Checks if the number is negative
    if (fixedNumString[0] == '-') {
        negativeNum = true;
    }
    else if(fixedNumString[0] == '+'){ // This if statement is empty because we don't need to do anything if there is a plus sign but we need to skip over it if there is one present.
    }
    else if(fixedNumString[0] == '.'){
        c = 0;
        return true;
    }
    else {
        currentInt = convertToInt(fixedNumString[0]);
        solution = (solution * 10) + currentInt;
    }
    // Moves through the c-string until it reaches a '.' or the null terminator.
    while (fixedNumString[counter] != '.' && fixedNumString[counter] != '\0') {
        currentInt = convertToInt(fixedNumString[counter]);  // Converts the current character in the c-string to an integer.
        solution = (solution * 10) + currentInt;        // Formula used to get the correct final integer.
        counter++;
    }

    c = solution;
    if (negativeNum == true) {
        c = c * -1;
    }

    delete [] fixedNumString;
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
            if(numString[counter] == '.'){
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
        if ((currentCharacter >= '0' && currentCharacter <= '9') || currentCharacter == '+' || currentCharacter == '-' || currentCharacter == '.') {
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
    bool retval = false;

    int checkNumerator = getNumerator(numString[]);
    int checkDenominator = getDenominator(checkNumerator);

    //checks if the numerator and denominator of the char array are the same as the ones passed into the function
    if (checkNumerator == numerator && checkDenominator == denominator)
        retval = true;

    return retval;
}

bool validNumber(char place)
{
    //checks to see if the character is a number (0-9)
    if (place == '0' || place == '1' || place == '2' || place == '3' || place == '4' || place == '5' || place == '6' || place == '7' || place == '8' || place == '9')
        return true;
    else
        return false;
}

char[] getNumeratorString(char numString[]);
{
    char numeratorString[];
    bool passedDecimal = false;
    int nsIndex = 0;
    for (int i = 0; i < charArraySize(numString[]); i++)
    {
        if (passedDecimal == true && validNumber(numstr[i]))
        {
            numeratorString[nsIndex] = numString[i];
            nsIndex++;
        }
        if (numString[i] == '.')
        {
            passedDecimal = true;
        }
    }
    return numeratorString[];
}

int getNumerator(char mantissaString[])
{
    int gotNumerator = 0;
    char numeratorString[] = getNumeratorString(mantissaString);
    int numeratorInt[charArraySize(numeratorString)];

    //converts each of the characters to integers using the convertCharToInt() function below
    for (int i = 0; i < charArraySize(numeratorString); i++)
    {
        numeratorInt[i] = convertCharToInt(numeratorString[i]);
    }
    int reversedNumeratorInt[] = reverse(numeratorInt);
    int place = 1;
    /*
        after reversing/flipping the integer array (ex: "456" to "654"), it multiplies each number by the place it would be in
        as if it was a stand-alone number (6 in the 1s place, 5 in the 10s place, and 4 in the 100s place)

        then adds them together (6 + 50 + 400 = 456)
    */
    for (int i = 0; i < intArraySize(reversedNumeratorInt); i++)
    {
        gotNumerator += i * place;
        place *= 10;
    }
    return gotNumerator;
}

int convertCharToInt(char number)
{
    //casting the char to an int
    return (int)number;
}

int getDenominator(int numerator)
{
    int gotDenominator = 10;

    while (true)
    {
        //checks when the remainder of dividing the numerator by the denominator would be 0 (int division)
        if (numerator % gotDenominator == 0)
        {
            break;
        }
        gotDenominator *= 10;
    }
    return gotDenominator
}

int charArraySize(char number[])
{
    int size = 0;
    for (int i = 0; number[i] != '\0'; i++)
        size++;

    return size;
}

int intArraySize(int arr[])
{
    return sizeof(arr)/sizeof(arr[0]);
}

int[] reverse(int number[])
{
    int index = 0;
    int reversedNumber[intArraySize(number)];
    //starts at the end of the original array and adds the number into the new one
    for (int i = intArraySize(number) - 1; i >= 0; i--)
    {
        reversedNumber[index] = number[i];
        index++;
    }
}
