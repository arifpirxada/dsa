// https://www.youtube.com/watch?v=nttpF8kwgd4
#include <iostream>
using namespace std;

void swapNumbers(int& a, int& b);
int isIthBitSet(int num, int i);
int setIthBit(int num, int i);
int clearIthBit(int num, int i);
int toggleIthBit(int num, int i);
int removeRightMostSetBit(int num);
int isPowerOfTwo(int num);

int main() {
    int a = 5, b = 10;
    cout << "Before swaping: a => " << a << "; " << "b => " << b << endl;
    swapNumbers(a, b);
    cout << "After swaping: a => " << a << "; " << "b => " << b << endl;

    string bitSet = isIthBitSet(13, 2) ? "Yes": "No";
    cout << "Is 2nd Bit(1101) of 13 set: " << bitSet << endl;

    cout << "After setting 1st bit of 13(1101): " << setIthBit(13, 1) << " (1111)" << endl;

    return 0;
}

void swapNumbers(int& a, int& b) {
    // we know that XOR of a number with itself is zero
    a = a ^ b;
    b = a ^ b; // a = a ^ b; so a ^ b ^ b = a; bcz b ^ b = 0
    a = a ^ b; // a = a ^ b; b = a; so a ^ b ^ a = b
}

int isIthBitSet(int num, int i) {
    return (num & (1 << i)) != 0;
}

int setIthBit(int num, int i) {
    return (num | (1 << i));
}

int clearIthBit(int num, int i) {
    return (num & (~(1 << i)));
}

int toggleIthBit(int num, int i) {
    return (num ^ (1 << i));
}

int removeRightMostSetBit(int num) {
    return (num & num - 1);
}

int isPowerOfTwo(int num) {
    return (num & num - 1) == 0;
}