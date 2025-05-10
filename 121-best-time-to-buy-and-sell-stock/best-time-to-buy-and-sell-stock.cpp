class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> minarr(n),maxarr(n);
        int maxi = prices[n-1],mini = prices[0];
        for(int i = 0; i<n; i++){
            mini = min(mini,prices[i]);
            maxi = max(maxi, prices[n-i-1]);

            minarr[i] = mini;
            maxarr[n-i-1] = maxi;
        }
        int profit = 0;
        for(int i = 0; i<n ;i++){
            profit = max(profit, maxarr[i] - minarr[i]);
        }
        return profit;
    }
};