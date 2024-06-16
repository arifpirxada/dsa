#include <vector>
using namespace std;

// https://leetcode.com/problems/valid-mountain-array/

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) {
            return false;
        }
        int i;
        for (i = 1; i < arr.size(); i++) {
            if (arr[i] <= arr[i - 1]) {
                break;
            }
        }

        if (i == 1 || i == arr.size()) {
            return false;
        }

        for (int j = i; j < arr.size(); j++) {
            if (arr[j] >= arr[j - 1]) {
                return false;
            }
        }
        
        return true;
    }
};