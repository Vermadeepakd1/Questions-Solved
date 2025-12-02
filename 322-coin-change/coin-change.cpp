class Solution {
    int t[10001][13];
    int findcoins(vector<int>& coins, int amount, int idx) {
        if (idx == coins.size()) {
            if (amount == 0)
                return 0;
            else
                return INT_MAX / 2;
        }

        if(t[amount][idx] != -1)return t[amount][idx];
        int take = INT_MAX, skip = INT_MAX;
        // take
        if (coins[idx] <= amount) {
            take = 1 + findcoins(coins, amount - coins[idx], idx);
        }
        // skip
        skip = findcoins(coins, amount, idx + 1);

        return t[amount][idx] = min(take, skip);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        memset(t,-1,sizeof(t));
        int ans = findcoins(coins, amount, 0);
        if(ans >= INT_MAX/2)return -1;

        return ans;
    }
};