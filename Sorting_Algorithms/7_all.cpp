#include <iostream>
#include <vector>
#include <utility> // header for std::swap
using namespace std;

class SortingAlgos
{
public:
    void printArray(vector<int> arr)
    {
        for (int num : arr)
        {
            cout << num << " ";
        }
    }
    void bubbleSort(vector<int> &arr)
    {
        int j, n = arr.size();
        for (int i{}; i < n; i++)
        {
            j = 0;
            while (j < n - i - 1)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                }
                j++;
            }
        }
    }
    void insertionSort(vector<int> &arr)
    {
        int j, n = arr.size(), key;
        for (int i = 1; i < n; i++)
        {
            key = arr[i];
            j = i - 1;
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
    void selectionSort(vector<int> &arr)
    {
        int j, n = arr.size(), mini;
        for (int i{}; i < n; i++)
        {
            mini = j = i;
            while (j < n)
            {
                if (arr[j] < arr[mini])
                {
                    mini = j;
                }
                j++;
            }
            if (mini != i)
            {
                swap(arr[i], arr[mini]);
            }
        }
    }
    int partition(vector<int> &arr, int low, int high)
    {
        int pivot = arr[low];
        int i = low + 1, j = high;
        do
        {
            while (arr[i] < pivot)
            {
                i++;
            }
            while (arr[j] > pivot)
            {
                j--;
            }
            if (i <= j)
            {
                swap(arr[i], arr[j]);
            }
        } while (i < j);
        swap(arr[low], arr[j]);
        return j;
    }
    void quickSort(vector<int> &arr, int low, int high)
    {
        if (low < high)
        {
            int partitionIndex = partition(arr, low, high);
            quickSort(arr, low, partitionIndex - 1);
            quickSort(arr, partitionIndex + 1, high);
        }
    }
    void merge(vector<int> &arr, int low, int mid, int high) {
        int i = low, j = mid + 1;
        vector<int> temp;
        
        while (i <= mid && j <= high) {
            if (arr[i] < arr[j]) {
                temp.push_back(arr[i]);
                i++;
            } else {
                temp.push_back(arr[j]);
                j++;
            }
        }
        while (i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }
        while(j <= high) {
            temp.push_back(arr[j]);
            j++;
        }
        for (int k = 0; k < temp.size(); k++) {
            arr[low + k] = temp[k];
        }
    }
    void mergeSort(vector<int> &arr, int low, int high) {
        if (low < high) {
            int mid = (low + high) / 2;
            mergeSort(arr, low, mid);
            mergeSort(arr, mid + 1, high);
            merge(arr, low, mid, high);
        }
    }
    void countSort(vector<int> &arr) {
        if (arr.size() == 0) return;
        int maxi = arr[0];
        for (int num : arr) {
            maxi = max(maxi, num);
        }
        vector<int> count(maxi + 1, 0);
        for (int i{}; i < arr.size(); i++) {
            count[arr[i]]++;
        }
        for (int i{}, k = 0; i < count.size(); i++) {
            while (count[i] > 0) {
                arr[k] = i;
                k++;
                count[i]--;
            }
        }
    }
};

int main()
{
    SortingAlgos sorter;
    vector<int> arr = {8, 2, 3, 5, 7, 6, 1, 4, 10, 9};
    cout << "Original: ";
    sorter.printArray(arr);
    // sorter.bubbleSort(arr);
    // sorter.insertionSort(arr);
    // sorter.selectionSort(arr);
    // sorter.quickSort(arr, 0, arr.size() - 1);
    // sorter.mergeSort(arr, 0, arr.size() - 1);
    sorter.countSort(arr);
    cout << "\nSorted: ";
    sorter.printArray(arr);
}