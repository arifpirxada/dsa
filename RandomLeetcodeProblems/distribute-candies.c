// https://leetcode.com/problems/distribute-candies/

int compareIntegers(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int distributeCandies(int* candyType, int candyTypeSize) {
    int i, types = 1;

    // Sorting
    qsort(candyType, candyTypeSize, sizeof(int), compareIntegers);

    // Finding total no. of types

    for (i = 1; i < candyTypeSize; i++) {
        if (candyType[i] != candyType[i - 1]) {
            types++;
        }
    }

    if (candyTypeSize / 2 < types) {
        return candyTypeSize / 2;
    }

    return types;
}