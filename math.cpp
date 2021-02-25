#include "math.h"

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
    //Checks inputs to make sure they are valid. Function returns false if inputs are not valid
    if(numerator1 < denominator1 && numerator2 < denominator2 && denominator1 != 0 && denominator2 != 0){
        
        //Converts both inputted mixed numbers to improper fractions
        int improperNumerator1 = (characteristic1 * denominator1) + numerator1;
        int improperNumerator2 = (characteristic2 * denominator2) + numerator2;
        
        //Calculates the greatest common divisor(gcd) for both sets of numbers
        int gcd1 = greatestCommonDivisor(improperNumerator1, denominator1);
        int gcd2 = greatestCommonDivisor(improperNumerator2, denominator2);
        
        //Reduces the improper fractions by dividing by the gcd
        improperNumerator1 = improperNumerator1 / gcd1;
        improperNumerator2 = improperNumerator2 / gcd2;
        denominator1 = denominator1 / gcd1;
        denominator2 = denominator2 / gcd2;
        
        //Multiplies the two improper fractions which results in the product if there is no integer overflow. Function returns false if integer overflow occurs
        int productNumerator = 0;
        int productDenominator = 0;
        if(isOverflow(improperNumerator1, improperNumerator2) == false){
            productNumerator = (improperNumerator1 * improperNumerator2);
        }
        else{
            return false;
        }
        if(isOverflow(denominator1, denominator2) == false){
            productDenominator = (denominator1 * denominator2);
        }
        else{
            return false;
        }
        
        //Converts the resulted improper fraction to a mixed number
        int wholeNumber = (productNumerator / productDenominator);
        int mixedNumerator = (productNumerator % productDenominator);
        
        //Initializes two new char arrays to store the characteristic and mantissa
        char characteristic[len];
        characteristic[0] = '\0';
        char mantissa[len];
        mantissa[0] = '\0';
        
        //Adds each digit of the characteristic to the corresponding char array in reverse order due to modular divison
        int digit = wholeNumber;
        int counter1 = 0;
        while(digit != 0 && counter1 != len){
            int newDigit = digit % 10;
            characteristic[counter1] = newDigit + 48;
            digit = digit / 10;
            counter1++;
        }
        characteristic[counter1] = '\0';
        
        //Adds each digit of the mantissa to the corresponding char array
        int newNumerator = mixedNumerator;
        int counter2 = 0;
        while(newNumerator != 0 && counter2 != len - 1){
            newNumerator = newNumerator * 10;
            if(newNumerator >= productDenominator){
                int newDigit = newNumerator / productDenominator;
                mantissa[counter2] = newDigit + 48;
                newNumerator = newNumerator % productDenominator;
                counter2++;
            }
            else{
                mantissa[counter2] = 48;
                counter2++;
            }
        }
        mantissa[counter2] = '\0';
        
        //Checks the length used of each array
        int lengthOfCharacteristic = lengthSoFar(characteristic, len);
        int lengthOfMantissa = lengthSoFar(mantissa, len);
        
        //Copies characteristic array into result array by reversing the order of digits
        int resultPosition = 0;
        for(int i = lengthOfCharacteristic - 1; i >= 0; i--){
            result[resultPosition] = characteristic[i];
            resultPosition++;
        }
        
        //Adds a decimal point to the result array to seperate the characteristic from the mantissa if the length of mantissa is greater than zero
        if(lengthOfMantissa > 0){
            result[lengthOfCharacteristic] = '.';
        }
        
        //Updates lengthOfCharacteristicr to account for the decimal point
        lengthOfCharacteristic++;
        
        //Checks to make sure the characteristic and mantissa will fit within the result array and adjusts the lengthOfMantissa if it will not fit
        if(lengthOfCharacteristic + lengthOfMantissa >= len){
            int difference = (lengthOfCharacteristic + lengthOfMantissa) - len;
            lengthOfMantissa = lengthOfMantissa - difference;
        }
        
        //Copies mantissa array into result array after the characteristic already in result array
        for(int i = 0; i < lengthOfMantissa; i++){
            result[i + lengthOfCharacteristic] = mantissa[i];
        }
        result[len - 1] = '\0';
    }
    else{
        return false;
    }
    return true;
}

int lengthSoFar(char array[], int len){
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

int greatestCommonDivisor(int numerator, int denominator){
    //Recursively calls the function to return the greatest common divisor
    if(denominator == 0){
        return numerator;
    }
    return greatestCommonDivisor(denominator, numerator % denominator);
}

bool isOverflow(int value1, int value2){
    //Checks to see if there is an int overflow
    if (value1 == 0 || value2 == 0){
        return false;
    }
    int result = value1 * value2;
    if (value1 == result / value2){
        return false;
    }
    else{
        return true;
    }
}

//--
bool divide(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
    return true;
}
