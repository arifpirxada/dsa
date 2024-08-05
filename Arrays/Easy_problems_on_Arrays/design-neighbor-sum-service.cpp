// https://leetcode.com/problems/design-neighbor-sum-service/

class neighborSum {
private:
    vector<vector<int>> myGrid;
public:
    neighborSum(vector<vector<int>>& grid) : myGrid(grid) {}
    
    int adjacentSum(int value) {
        int adSum = 0;
        for (int i{}; i < myGrid.size(); i++) {
            for (int j{}; j < myGrid[i].size(); j++) {
                if (myGrid[i][j] == value) {
                    if (j > 0) {
                        adSum += myGrid[i][j - 1];
                    }
                    if (j < myGrid[i].size() - 1) {
                        adSum += myGrid[i][j + 1];
                    }
                    if (i > 0) {
                        adSum += myGrid[i - 1][j];
                    }
                    if (i < myGrid.size() - 1) {
                        adSum += myGrid[i + 1][j];
                    }
                    return adSum;
                }
            }
        }
        return adSum;
    }
    
    int diagonalSum(int value) {
        int diaSum = 0;
        for (int i{}; i < myGrid.size(); i++) {
            for (int j{}; j < myGrid[i].size(); j++) {
                if (myGrid[i][j] == value) {
                    if (i > 0 && j > 0) {
                        diaSum += myGrid[i - 1][j - 1];
                    }
                    if (i > 0 && j < myGrid[i].size() - 1) {
                        diaSum += myGrid[i - 1][j + 1];
                    }
                    if (i < myGrid.size() - 1 && j > 0) {
                        diaSum += myGrid[i + 1][j - 1];
                    }
                    if (i < myGrid.size() - 1 && j < myGrid[i].size() - 1) {
                        diaSum += myGrid[i + 1][j + 1];
                    }
                    return diaSum;
                }
            }
        }
        return diaSum;
    }
};