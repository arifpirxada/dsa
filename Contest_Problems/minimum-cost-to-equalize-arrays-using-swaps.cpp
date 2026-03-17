class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int, int> mp;
        unordered_map<int, int> f1;
        unordered_map<int, int> f2;
        int cost = 0;
        
        for (int i = 0; i < n; i++) {
            mp[nums1[i]]++;
            mp[nums2[i]]++;
            f1[nums1[i]]++;
            f2[nums2[i]]++;
        }

        for (auto p : mp) {
            if (p.second % 2 != 0) return -1;

            if (f1[p.first] != f2[p.first]) {
                cost += abs(f1[p.first] - f2[p.first]) / 2;
            }
        }

        return cost / 2;
    }
};