// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9.
// X can be placed before L (50) and C (100) to make 40 and 90.
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given an integer, convert it to a roman numeral.

/***********************
 **  Ibraheem Rehman  **
 **  SE-Q    21i-1102 **
 ***********************/

#include <iostream>
using namespace std;

char *intToRoman(int num)
{
    char *roman = (char *)malloc(sizeof(char) * 20);
    int i = 0;
    while (num != 0)
    {
        if (num >= 1000)
        {
            roman[i] = 'M';
            i++;
            num = num - 1000;
        }
        else if (num >= 900)
        {
            roman[i] = 'C';
            i++;
            roman[i] = 'M';
            i++;
            num = num - 900;
        }
        else if (num >= 400)
        {
            roman[i] = 'C';
            i++;
            roman[i] = 'D';
            i++;
            num = num - 400;
        }

        else if (num >= 500)
        {
            roman[i] = 'D';
            i++;
            num = num - 500;
        }
        else if (num >= 100)
        {
            roman[i] = 'C';
            i++;
            num = num - 100;
        }
        else if (num >= 90)
        {
            roman[i] = 'X';
            i++;
            roman[i] = 'C';
            i++;
            num = num - 90;
        }

        else if (num >= 50)
        {
            roman[i] = 'L';
            i++;
            num = num - 50;
        }
        else if (num >= 40)
        {
            roman[i] = 'X';
            i++;
            roman[i] = 'L';
            i++;
            num = num - 40;
        }
        else if (num >= 10)
        {
            roman[i] = 'X';
            i++;
            num = num - 10;
        }
        else if (num >= 9)
        {
            roman[i] = 'I';
            i++;
            roman[i] = 'X';
            i++;
            num = num - 9;
        }
        else if (num >= 5)
        {
            roman[i] = 'V';
            i++;
            num = num - 5;
        }
        else if (num >= 4)
        {
            roman[i] = 'I';
            i++;
            roman[i] = 'V';
            i++;
            num = num - 4;
        }
        else if (num >= 1)
        {
            roman[i] = 'I';
            i++;
            num = num - 1;
        }
    }
    roman[i] = '\0'; // null character to terminate the string properly
    return roman;
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << intToRoman(num);
    return 0;
}