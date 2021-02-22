#include "math.h"
#include <iostream>

using namespace std;

bool add(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
    return true;
}
//--
bool subtract(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
    return true;
}
//--
bool multiply(int characteristic1, int numerator1, int denominator1, int characteristic2, int numerator2, int denominator2, char result[], int len)
{
    //Checks inputs to make sure they are valid
    if(numerator1 < denominator1 && numerator2 < denominator2 && denominator1 != 0 && denominator2 != 0){
        //Converting both inputted mixed numbers to improper fractions
        int improperNumerator1 = (characteristic1 * denominator1) + numerator1;
        int improperNumerator2 = (characteristic2 * denominator2) + numerator2;
        
        //Multiplies the two improper fractions which results in the product
        int productNumerator = (improperNumerator1 * improperNumerator2);
        int productDenominator = (denominator1 * denominator2);
        
        //Converts the improper fraction to a mixed number
        int wholeNumber = (productNumerator / productDenominator);
        int mixedNumerator = (productNumerator % productDenominator);
        
        //Converts the fraction
        //Needs to be finished
        int decimal = (mixedNumerator / productDenominator);
        
        //Converts wholeNumber and decimal to seperate arrays of chars
        char characteristic[len];
        char mantissa[len];
        sprintf(characteristic, "%d", wholeNumber);
        sprintf(mantissa, "%d", decimal);
        
        //Checks the length of each array
        int lengthOfCharacteristic = lengthOfArray(characteristic, len);
        int lengthOfMantissa = lengthOfArray(mantissa, len);
        
        //Adds a decimal point to the characteristic array to seperate the whole number from the decimal
        characteristic[lengthOfCharacteristic] = '.';
        
        //Updates lengthOfCharacteristicr to account for the decimal point
        lengthOfCharacteristic++;
        
        //Copies characteristic array into result array
        for(int i = 0; i < lengthOfCharacteristic; i++){
            result[i] = characteristic[i];
        }
        
        //Checks to make sure the characteristic and mantissa will fit within the result array and adjusts the lengthOfMantissa if it will not fit
        if(lengthOfCharacteristic + lengthOfMantissa >= len){
            int difference = (lengthOfCharacteristic + lengthOfMantissa) - len;
            lengthOfMantissa = lengthOfMantissa - difference;
        }
        
        //Copies mantissa array into result array after the characteristic already in result
        for(int i = 0; i < lengthOfMantissa; i++){
            result[i + lengthOfCharacteristic] = mantissa[i];
        }
    }
    else{
        return false;
    }
    return true;
    /*
     Test code to be put in main():
     multiply(3, 1, 4, 3, 1, 3, result, lengthOfResult);
     */
}

int lengthOfArray(char array[], int len){
    //Loop to determine the length of the array so far
    int lengthSoFar = 0;
    for(int i = 0; i < len; i++){
        if(array[i] == '\0'){
            break;
        }
        else{
            lengthSoFar++;
        }
    }
    return lengthSoFar;
}
//--
bool divide(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
    return true;
}
