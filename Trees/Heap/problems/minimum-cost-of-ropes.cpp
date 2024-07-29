// https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        priority_queue<long long, vector<long long>, greater<long long>> pq; // Min heap
        
        for (int i = 0; i < n; i++) {
            pq.push(arr[i]);
        }
        
        long long cost = 0, min1, min2;
        
        while (pq.size() > 1) {
            min1 = pq.top();
            pq.pop();
            
            min2 = pq.top();
            pq.pop();
            
            cost += min1 + min2;
            
            pq.push(min1 + min2);
        }
        
        return cost;
        
    }
};