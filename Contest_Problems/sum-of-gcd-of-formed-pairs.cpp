class Solution {
public:
    int getGcd(int a, int b) {
        while (a % b != 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }
        return b;
    }
    long long gcdSum(vector<int>& nums) {
        vector<int> prefixGcd;
        int n = nums.size();
        int mx = 0;

        int i = 0;
        int j = n - 1;
        long long ans = 0;
        
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            int gc = getGcd(mx, nums[i]);
            
            prefixGcd.push_back(gc);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        while (i < j) {
            int gc = getGcd(prefixGcd[j], prefixGcd[i]);
            ans += gc;
            i++;
            j--;
        }

        return ans;
    }
};