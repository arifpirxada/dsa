### Bit Manipulation
[Bit Manipulation playlist](https://www.youtube.com/playlist?list=PLgUwDviBIf0rnqh8QsJaHyIX7KUiaPUv7)

### 1. Decimal & Binary Conversion

***Decimal to Binary Conversion:***
    - [Conversion video](https://youtu.be/qQd-ViW7bfk?si=vxOA6r8Z25KuF4y9&t=70)    
    - Divide the number by 2 until you reach 1 and keep track of the reminder.    
    - Write all the reminders in reverse order - this is your Binary number.    

    ```
        Example: Convert 7 to its Binary form.
        * 7 / 2 = 3; 7 % 2 = 1 (reminder)
        * 3 / 2 = 1 (first of binary number); 3 % 2 = 1
        * 1 / 2 = 0; 1 % 2 = 1

        Binary number = 111
    - Example: Convert 13 to its Binary form.

        * 13 / 2 = 6; 13 % 2 = 1 (reminder)
        * 6 / 2 = 3; 6 % 2 = 0
        * 3 / 2 = 1; 3 % 2 = 1
        * 1 / 2 = 0; 1 % 2 = 1

        Binary number = 1101
    ```

***Binary to Decimal Conversion:***
    - Index the digits of Binary number in reverse order (0-indexed).    
    - Multiply each digit with 2^i - where i is the index of that digit.   
    - Calculate their sum and this is your Decimal number.    

    ```
        Example: Convert 1101 to its Decimal form.
        Solution:
        * step1: 1 -> 3, 1 -> 2, 0 -> 1, 1 -> 0 - Numbers after arrows represent indices.
        * step2: 1 * 2^0 + 0 * 2^1 + 1 * 2^2 + 1 + 2^3
        * step3: 1 + 0 + 4 + 8 = 13

        Decimal number = 13
    ```

### 2. How does the computer store numbers
    - Lets say we declare a variable
    ```
    int n = 13;
    ```
    - The computer will store its binary form that is, 1101
    - Each 1 or 0 takes one bit storage.
    - int can store 32 bits and long long can store 64 bits.
    - This 1101 will be stored, it will take 4 bits and remaining bits will store zeroes.
    - When we will print(n), it is again converted to decimal and then printed.

### 3. 1's complement and 2's complement

***1's complement: ***
- Convert 1 to 0 and 0 to one in binary number.
- That is your 1's complement.
- Example:
- 1's complement of 1101 is 0010.

***2's complement: ***
- Do the 1's complement to the binary name.
- Then add one to it, this is your 2's complement.
- Example:
- 2's complement of 1101 is 0011.

### 4. Bitwise Operators:

***1. AND Operator -->***
- If all true -> returns true
- If one false -> returns false
- Example:
```
n = 13 & 7

    1 1 0 1
&   0 1 1 1
    -------
    0 1 0 1 = 5 (result)

Here we are comparing digits of binary number 1 means true and 0 means false;
```

***2. OR Operator -->***
- one true -> returns true
- all false -> returns false
- Example:
```
n = 13 | 7

    1 1 0 1
|   0 1 1 1
    -------
    1 1 1 1 = 15 (result)

```

***3. XOR Operator -->***
- Number of one's is odd -> 1 -> true
- Number of one's is even -> 0 -> false
- Example:
```
n = 13 ^ 7

    0  0  1  1  0  1
^   0  0  0  1  1  1
    ----------------
    0  0  1  0  1  0 = 1010 =  (result)

    Here we compare first: 1 & 1, Number of one's is even so it returns 0
    second: 0 & 1, no. of one's is odd, so it returns 1
    ...
    
    left zeros are the zeros which are stored in the remaining bits by default.
```

***4. RIGHT SHIFT Operator (>>) -->***
- It shifts n binary digits to the right, where n is given like: 13 >> 2, n = 2
- Formula: n / 2^k.
- Example:
```
n = 13 >> 1
Initial: ...0001101
After right shift: ...0000110 = 6

n = 13 >> 2
Initial: ...0001101
After: ...0000011 = 3

```

***IMPORTANT: How does the computer store negative numbers***
- The last or 31st bit is reserved for the sign.
- 0 -> positive, 1 -> negative.
- Computer uses 2's complement to store negative number.
- Example
- 13 = 000...0001101
- After 2's complement: 13 = 111...1110011
- Now the 31st bit is 1 which is negative.

***Largest number that INT datatype can store:***
- 2^30 + 2^29 + 2^28 ... = (2^31 - 1) -> INT_MAX

***Smallest number that INT datatype can store:  -2^31 = INT_MIN***

***5. LEFT SHIFT Operator (<<) -->***
- It shifts n binary digits to the left, where n is given like: 13 << 2, n = 2
- Formula: n * 2^k.
- Remember overflow is cause when you do left shift to INT_MAX.
- Example:
```
n = 13 << 1
Initial: 000...0001101
After left shift: 000...0011010 = 26

n = 13 >> 2
Initial: 000...0001101
After: 000...0110100 = 52

```

***6. NOT Operator (~) -->***
- steps:
- Flips the digits
- Checks if it is a negative number.
- If it is -ve, convert to its 2's complement, else do nothing.
- Example:
```
n = ~(5)
Initial: 000...101
After left shift:
first-step: 111...010
convert to its 2's complement (-ve): 100...110 = -6 => First one is not fliped bcz it is the sign.

n = ~(-6)
6 = 000...110
But -6: 1...11010 
After Not:
first-flip: 0...00101
it is not negative so stop. it is 5.

```