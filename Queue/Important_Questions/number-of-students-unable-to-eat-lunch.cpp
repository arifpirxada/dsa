// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/

class Solution {
private:
    bool canEat(int one, int zero, int top) {
        if (top == 1 && one == 0) {
            return false;
        } else if (top == 0 && zero == 0) {
            return false;
        }
        return true;
    }
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> stud;
        stack<int> sand;
        int numOfOnes = 0, numOfZeroes = 0;

        for (int student : students) {
            if (student == 1) {
                numOfOnes++;
            } else {
                numOfZeroes++;
            }
            stud.push(student);
        }

        for (int i = sandwiches.size() - 1; i >= 0; i--) {
            sand.push(sandwiches[i]);
        }

        while (!sand.empty() && canEat(numOfOnes, numOfZeroes, sand.top())) {
            if (stud.front() == sand.top()) {
                if (stud.front() == 1) {
                    numOfOnes--;
                } else if (stud.front() == 0) {
                    numOfZeroes--;
                }
                sand.pop();
                stud.pop();
            } else {
                stud.push(stud.front());
                stud.pop();
            }
        }

        return stud.size();
    }
};