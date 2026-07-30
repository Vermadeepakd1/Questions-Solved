class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int mini = prices[0];

        for(int i : prices){
            ans = max(ans,i-mini);
            mini = min(mini,i);
        }

        return ans;
    }
};