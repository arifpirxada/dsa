// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

int maxProfit(int* prices, int pricesSize) {
    int i = 0, j, profit = 0;
    for (j = 1; j < pricesSize; j++) {
        if (prices[i] < prices[j]) {
            if (prices[j] - prices[i] > profit) {
                profit = prices[j] - prices[i];
            }
        } else {
            i = j;
        }
    }
    return profit;
}