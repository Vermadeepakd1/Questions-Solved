class Solution {
    int dp[100001][2][3];
    int solve(vector<int>& prices, int idx, bool hasstock, int numstock) {
        if (idx == prices.size() || numstock == 2)
            return 0;
        int one = 0, two = 0, three = 0;

        if (dp[idx][hasstock][numstock] != -1)
            return dp[idx][hasstock][numstock];

        if (hasstock) {
            one = prices[idx] + solve(prices, idx + 1, false, numstock + 1);
        } else {
            if (numstock < 2)
                two = solve(prices, idx + 1, true, numstock) - prices[idx];
        }
        three = solve(prices, idx + 1, hasstock, numstock);

        return dp[idx][hasstock][numstock] = max({one, two, three});
    }

public:
    int maxProfit(vector<int>& prices) {
        memset(dp, 0, sizeof(dp));
        int n = prices.size();

        for(int i=n-1; i>=0; i--){
            for(int hasstock=0; hasstock<=1; hasstock++){
                for(int numstock = 0; numstock <2; numstock++){
                    int one = 0, two = 0, three= 0;

                    if(hasstock){
                        one = prices[i] + dp[i+1][false][numstock+1];
                    }else{
                        two = dp[i+1][true][numstock] - prices[i];
                    }
                    three = dp[i+1][hasstock][numstock];

                    dp[i][hasstock][numstock] = max({one,two,three});
                }
            }
        }

        return dp[0][0][0];
    }
};