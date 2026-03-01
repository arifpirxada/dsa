// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        bool isCeleb;
        
        for (int i = 0; i < n; i++) {
            isCeleb = true;
            for (int j = 0; j < n; j++) {
                if (i != j && mat[i][j] != 0) {
                    isCeleb = false;
                    break;
                }
            }
            
            if (isCeleb) {
                for (int j = 0; j < n; j++) {
                    if (mat[j][i] != 1) {
                        isCeleb = false;
                        break;
                    }
                }
            }
            
            if (isCeleb) return i;
        }
        
        return -1;
    }
};


// Optimised

class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int candidate = 0;

        // Step 1: Find candidate
        for (int i = 1; i < n; i++) {
            if (mat[candidate][i] == 1) {
                candidate = i;
            }
        }

        // Step 2: Verify candidate
        for (int i = 0; i < n; i++) {
            if (i == candidate) continue;

            // Candidate should not know anyone
            // Everyone should know candidate
            if (mat[candidate][i] == 1 || mat[i][candidate] == 0) {
                return -1;
            }
        }

        return candidate;
    }
};


// Optimised Stack