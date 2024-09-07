// https://leetcode.com/problems/time-needed-to-buy-tickets/

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int allTickets = 0;

        for (int ticket : tickets) {
            allTickets += ticket; 
        }

        int i = 0;
        int ans = 0;
        
        while (allTickets >= 0) {
            if (tickets[i] != 0) {
                ans++;
                allTickets--;
                tickets[i]--;
            }
            if (i == k && tickets[i] == 0) {
                return ans;
            }
            i = (i + 1) % tickets.size();
        }
        return -1;
    }
};