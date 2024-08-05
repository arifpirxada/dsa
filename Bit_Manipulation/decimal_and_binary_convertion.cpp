#include <iostream>
#include <string>
#include <algorithm>
#include <cmath> // for pow
using namespace std;

string decimal_to_binary(int n);
int binary_to_decimal(string binary);

int main () {
    cout << "Binary of 7: " << decimal_to_binary(7) << endl;
    cout << "Binary of 13: " << decimal_to_binary(13) << endl;

    cout << "\nDecimal of 111: " << binary_to_decimal("111") << endl;
    cout << "Decimal of 1101: " << binary_to_decimal("1101") << endl;

    return 0;
}

// first Approach =>
// string decimal_to_binary(int n) {
//     string binary;
//     while (n > 1) {
//         binary.push_back(n % 2 + '0');
//         n /= 2;
//     }
//     binary.push_back(n + '0');
//     reverse(binary.begin(), binary.end());
//     return binary;
// }

// int binary_to_decimal(string binary) {
//     int decimal = 0;
//     int index = 0;
//     for (int i = binary.size() - 1; i >= 0; i--) {
//         decimal += (binary[i] - '0') * pow(2, index);
//         index++;
//     }
//     return decimal;
// }

// Second approach =>
string decimal_to_binary(int n) {
    if (n == 0) return "0";

    string binary;
    while (n > 0) {
        if (n % 2 == 1) {
            binary += '1';
        } else {
            binary += '0';
        }
        n /= 2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

int binary_to_decimal (string binary) {
    int decimal = 0, p2 = 1;
    for (int i = binary.size() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += p2;
        }
        p2 *= 2;
    }
    return decimal;
}