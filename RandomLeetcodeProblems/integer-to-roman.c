// https://leetcode.com/problems/integer-to-roman/

char* intToRoman(int num) {
    int i = 0;

    int numArr[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char romArr[13][3] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    char *roman = (char *)malloc(20 * sizeof(char));
    roman[0] = '\0';

    while (num > 0) {
        while (num >= numArr[i]) {
            strcat(roman, romArr[i]);
            num -= numArr[i];
        }
        i++;
    }
    
    return roman;
}