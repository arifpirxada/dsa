// https://www.geeksforgeeks.org/chocolate-distribution-problem/

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        //code
        long long minDiff = LLONG_MAX;
        std::sort(a.begin(), a.end());
        
        for (int i = 0; i + m - 1 < n; i++) {
            if (a[i + m - 1] - a[i] < minDiff) {
                minDiff = a[i + m - 1] - a[i];
            }
        }
        return minDiff;
    }   
};