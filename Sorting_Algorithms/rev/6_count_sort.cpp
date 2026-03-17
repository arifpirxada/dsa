#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Sort {
    public:
        void printArr(vector<int>& arr) {
            for (int i = 0; i < arr.size(); i++) {
                cout << arr[i] << " ";
            }
        }
        void countSort(vector<int>& arr) {
            int mx = *max_element(arr.begin(), arr.end());

            vector<int> count(mx + 1, 0);

            for (int x : arr)
                count[x]++;

            int idx = 0;

            for (int i = 0; i <= mx; i++) {
                while (count[i] > 0) {
                    arr[idx++] = i;
                    count[i]--;
                }
            }
        }
};

int main() {
    vector<int> myArr = {3, 4, 2, 1, 8, 6, 7, 5};

    Sort s;

    s.countSort(myArr);

    s.printArr(myArr);

    return 0;
}