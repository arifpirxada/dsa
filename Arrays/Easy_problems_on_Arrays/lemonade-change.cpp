// https://leetcode.com/problems/lemonade-change/

class Solution {
private:
    bool getChange(int &five, int &ten, int bill) {
        if (bill == 5) {
            five++;
            return true;
        }
        if (bill == 10 && five > 0) {
            ten++;
            five--;
            return true;
        }
        if (bill == 20) {
            if (ten >= 1 && five >= 1) {
                five--;
                ten--;
                return true;
            } else if (five >= 3) {
                five -= 3;
                return true;
            }
        }
        return false;
    }
public:
    bool lemonadeChange(vector<int>& bills) {
        if (bills[0] != 5) return false;
        int five = 0, ten = 0;

        for (int i{}; i < bills.size(); i++) {
            if (!getChange(five, ten, bills[i])) {
                return false;   
            }
        }

        return true;
    }
};