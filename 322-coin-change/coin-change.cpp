class Solution {
    int dp[10001];
    int findcoins(vector<int>& coins, int amount){
        if(amount ==0)return 0;

        if(dp[amount] != -1)return dp[amount];

        int mincoins = INT_MAX;
        for(int i : coins){
            if(amount - i >= 0){
                int rem = findcoins(coins, amount - i);
                if(rem != INT_MAX)
                mincoins =  min(1+rem,mincoins);
            }
        }
        return dp[amount] = mincoins;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));

        int n = coins.size();

        int result =  findcoins(coins,amount);
        if(result == INT_MAX)return -1;
        return result;
    }
};