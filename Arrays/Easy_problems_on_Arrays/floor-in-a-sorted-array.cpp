// https://bit.ly/3Cf398N

class Solution {
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> &v, long long n, long long x) {
        int low = 0, high = n - 1, mid;
        
        if (x < v[0]) return -1;
        
        while (low <= high) {
            mid = (low + high) / 2;
            if (v[mid] == x) {
                return mid;
            } else if (v[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return high;
    }
};