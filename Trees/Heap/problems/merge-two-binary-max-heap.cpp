// https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1
using namespace std;
#include <vector>

class Solution{
    public:
    void heapify(vector<int> &arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
    
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        } 
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }
    
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }
    
    void buildHeap(vector<int> &arr) {
        int n = arr.size();
        for (int i = (n / 2) - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> ans;
        
        ans.reserve(a.size() + b.size());
        ans.insert(ans.end(), a.begin(), a.end());
        ans.insert(ans.end(), b.begin(), b.end());
        
        buildHeap(ans);
        return ans;
    }
};