#include <iostream>
#include <vector>   

using namespace std;

class Sort {
    public:
        void bubbleSort(vector<int>& arr) {
            int n = arr.size();
            bool swapped;
        
            for (int i = 0; i < n - 1; i++) {
                swapped = false;
                for (int j = 0; j < n - i - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        swap(arr[j], arr[j + 1]);
                        swapped = true;
                    }
                }
            
                // If no two elements were swapped, then break
                if (!swapped)
                    break;
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

    s.bubbleSort(myArr);

    s.printArr(myArr);

    return 0;
}