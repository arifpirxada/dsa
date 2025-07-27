// https://leetcode.com/problems/xor-queries-of-a-subarray/

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        int curr;
        
        for (int i = 0; i < queries.size(); i++) {
            int j = queries[i][0];
            curr = arr[j];
            j++;
            while (j <= queries[i][1]) {
                curr = curr ^ arr[j];
                j++;
            }
            ans.push_back(curr);
        }
        return ans;
    }
};

// optimal
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;

        // calc xor
        for (int i = 1; i < arr.size(); i++) {
            arr[i] = arr[i] ^ arr[i - 1];
        }
        
        for (int i = 0; i < queries.size(); i++) {
            if (queries[i][0] == 0) {
                ans.push_back(arr[queries[i][1]]);
            } else {
                ans.push_back(arr[queries[i][1]] ^ arr[queries[i][0] - 1]);
            }
        }
        return ans;
    }
};