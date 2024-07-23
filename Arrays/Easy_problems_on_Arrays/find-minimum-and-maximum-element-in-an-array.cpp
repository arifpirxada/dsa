// https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/

class Solution {
  public:
    pair<long long, long long> getMinMax(vector<long long int> arr) {
        long long max = arr[0];
        long long min = arr[0];
        
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
            if (arr[i] < min) {
                min = arr[i];
            }
        }
        
        return make_pair(min, max);
    }
};