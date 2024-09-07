// https://leetcode.com/problems/reveal-cards-in-increasing-order/

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        if (deck.size() == 1) return deck;
        queue<int> que;
        sort(deck.begin(), deck.end());
        int k = deck.size() - 1;

        que.push(deck[k]);
        k--;
        while (k >= 0) {
            que.push(que.front());
            que.pop();
            que.push(deck[k]);
            k--;
        }

        vector<int> ans(deck.size(), 0);
        k = deck.size() - 1;

        while (!que.empty()) {
            ans[k] = que.front();
            que.pop();
            k--;
        }
        return ans;
    }
};