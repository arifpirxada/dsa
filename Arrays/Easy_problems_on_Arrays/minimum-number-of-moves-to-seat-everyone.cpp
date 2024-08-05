// https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int moves = 0;
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        for (int i{}; i < seats.size(); i++) {
            moves += abs(students[i] - seats[i]);
        }

        return moves;
    }
};