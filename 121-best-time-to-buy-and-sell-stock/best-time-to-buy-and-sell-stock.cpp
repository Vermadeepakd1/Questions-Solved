class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, mini = prices[0];
        for(int p : prices){
            profit = max(p - mini, profit);
            mini = min(p,mini);
        }
        return profit;
    }
};