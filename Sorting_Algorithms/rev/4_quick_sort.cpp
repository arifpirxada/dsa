#include <iostream>
#include <vector>   

using namespace std;

class Sort {
    public:
        void printArr(vector<int>& arr) {
            for (int i = 0; i < arr.size(); i++) {
                cout << arr[i] << " ";
            }
        }
        int partition(vector<int>& arr, int st, int end) {
            int idx = st - 1;

            for (int j = st; j < end; j++) {
                if (arr[j] < arr[end]) {
                    idx++;
                    swap(arr[j], arr[idx]);
                }
            }

            idx++;
            swap(arr[idx], arr[end]);
            return idx;
        }

        void quickSort(vector<int>& arr, int st, int end) {
            if (st >= end) return;

            int pivIndex = partition (arr, st, end);

            quickSort(arr, st, pivIndex - 1);
            quickSort(arr, pivIndex + 1, end);
        }
};

int main() {
    vector<int> myArr = {3, 4, 2, 1, 8, 6, 7, 5};

    Sort s;

    s.quickSort(myArr, 0, myArr.size() - 1);

    s.printArr(myArr);

    return 0;
}