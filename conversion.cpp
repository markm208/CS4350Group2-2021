#include "conversion.h"

bool characteristic(const char numString[], int& c)
{
    return true;
}
//--
bool mantissa(const char numString[], int& numerator, int& denominator)
{
    bool retval = false;

    int checkNumerator = getNumerator(numString[]);
    int checkDenominator = getDenominator(checkNumerator);
    if (checkNumerator == numerator && checkDenominator == denominator)
        retval = true;

    return retval;
}

bool validNumber(char place)
{
    //checks to see if the character is a number
    if (place == '0' || place == '1' || place == '2' || place == '3' || place == '4' || place == '5' || place == '6' || place == '7' || place == '8' || place == '9')
        return true;
    else
        return false;
}

char[] getNumeratorString(char numString[]);
{
    char numeratorString[arraySizeChar(numString[])];
    bool passedDecimal = false;
    int nsIndex = 0;
    for (int i = 0; i < arraySizeChar(numeratorString[]); i++)
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
    int numeratorInt[arraySizeChar(numeratorString)];
    for (int i = 0; i < arraySizeChar(numeratorString); i++)
    {
        numeratorInt[i] = convertCharToInt(numeratorString[i]);
    }
    int reversedNumeratorInt[] = reverse(numeratorInt);
    int place = 1;
    for (int i = 0; i < arraySizeInt(reversedNumeratorInt); i++)
    {
        gotNumerator += i * place;
        place *= 10;
    }
    return gotNumerator;
}

int convertCharToInt(char number)
{
    return (int)number;
}

int getDenominator(int numerator)
{
    int gotDenominator = 10;

    while (true)
    {
        if (numerator % gotDenominator == 0)
        {
            break;
        }
        gotDenominator *= 10;
    }
    return gotDenominator
}

int arraySizeChar(char number[])
{
    int size = 0;
    for (int i = 0; number[i] != '\0'; i++)
        size++;

    return size;
}

int arraySizeInt(int arr[])
{
    return sizeof(arr)/sizeof(arr[0]);
}

int[] reverse(int number[])
{
    int index = 0;
    int reversedNumber[arraySizeInt(number)];
    //starts at the end of the original array and adds the number into the new one
    for (int i = arraySizeInt(number) - 1; i >= 0; i--)
    {
        reversedNumber[index] = number[i];
        index++;
    }
}
