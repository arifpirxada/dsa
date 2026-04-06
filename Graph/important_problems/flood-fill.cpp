// https://leetcode.com/problems/flood-fill/

class Solution {
public:
    void fillDFS(vector<vector<int>> & image, int i, int j, int color, int stColor, vector<vector<bool>>& vis, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n || vis[i][j] == true || image[i][j] != stColor) return;

        vis[i][j] = true;
        if (image[i][j] == stColor) {
            image[i][j] = color;
        }

        fillDFS(image, i - 1, j, color, stColor, vis, m, n);
        fillDFS(image, i + 1, j, color, stColor, vis, m, n);
        fillDFS(image, i, j - 1, color, stColor, vis, m, n);
        fillDFS(image, i, j + 1, color, stColor, vis, m, n);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {\
        int m = image.size();
        int n = image[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        fillDFS(image, sr, sc, color, image[sr][sc], vis, m, n);

        return image;
    }
};

// Without visited array

class Solution {
public:
    void fillDFS(vector<vector<int>> & image, int i, int j, int color, int stColor) {
        if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] == color || image[i][j] != stColor) return;

        if (image[i][j] == stColor) {
            image[i][j] = color;
        }

        fillDFS(image, i - 1, j, color, stColor);
        fillDFS(image, i + 1, j, color, stColor);
        fillDFS(image, i, j - 1, color, stColor);
        fillDFS(image, i, j + 1, color, stColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<bool>> vis(image.size(), vector<bool>(image[0].size(), false));

        fillDFS(image, sr, sc, color, image[sr][sc]);

        return image;
    }
};