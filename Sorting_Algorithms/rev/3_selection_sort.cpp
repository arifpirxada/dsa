#include <iostream>
#include <vector>   

using namespace std;

class Sort {
    public:
        void selectionSort(vector<int>& arr) {
            int len = arr.size();
            int temp;

            for (int i = 0; i < len; i++) {
                int minIndex = i;
                for (int j = i + 1; j < len; j++) {
                    if (arr[j] < arr[minIndex]) {
                        minIndex = j;
                    }
                }
                temp = arr[i];
                arr[i] = arr[minIndex];
                arr[minIndex] = temp;
            }
        }

        void printArr(vector<int>& arr) {
            for (int i = 0; i < arr.size(); i++) {
                cout << arr[i] << " ";
            }
        }
};

int main() {
    vector<int> myArr = {3, 4, 2, 1, 8, 6, 7, 5};

    Sort s;

    s.selectionSort(myArr);

    s.printArr(myArr);

    return 0;
}