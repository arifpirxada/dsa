class Solution {
public:
    vector<vector<int>> insertionSort(vector<vector<int>>& people) {
        vector<vector<int>> sorted;

        sorted.push_back(people[0]);

        for (int i = 1; i < people.size(); i++) {
            vector<int> key = people[i];
            sorted.push_back(key);
            int j = i - 1;
            while (j >= 0) {
                if (key[0] > sorted[j][0]) {
                    swap(sorted[j], sorted[j + 1]);
                } else if (key[0] == sorted[j][0] && key[1] < sorted[j][1]) {
                    swap(sorted[j], sorted[j + 1]);
                } else {
                    break;
                }
                j--;
            }
        }

        return sorted;
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> sorted = insertionSort(people);

        vector<vector<int>> ans;

        for (auto &p : sorted) {
            ans.insert(ans.begin() + p[1], p);
        }

        return ans; 
    }
};