#include <iostream>
#include <vector>   

using namespace std;

class Sort {
    public:
        void insertionSort(vector<int>& arr) {
            int n = arr.size();
            
            for (int i = 1; i < n; i++) {
                int j = i;
                while (j > 0 && arr[j] < arr[j - 1]) {
                    swap(arr[j], arr[j - 1]);
                    j--;
                }
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

    s.insertionSort(myArr);

    s.printArr(myArr);

    return 0;
}