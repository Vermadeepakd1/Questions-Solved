class Solution {
    int m, n;
    // long long memo[501][501][3];
    // int findmaxprofit(vector<vector<int>>& coins, int i, int j, int robs) {

    //     if (i >= m || j >= n)
    //         return -1e9;
    //     if (memo[i][j][robs] != -1)
    //         return memo[i][j][robs];
    //     if (i == m - 1 && j == n - 1) {
    //         int res = coins[i][j];
    //         if (coins[i][j] < 0 && robs > 0) {
    //             res = 0;
    //         }
    //         return res;
    //     }

    //     int take = coins[i][j] +
    //                max(findmaxprofit(coins, i + 1, j, robs),
    //                    findmaxprofit(coins, i, j + 1, robs));
    //     int skip = -1e9;
    //     if (coins[i][j] < 0 && robs > 0) {
    //         skip = 0 + max(findmaxprofit(coins, i + 1, j, robs - 1),
    //                               findmaxprofit(coins, i, j + 1, robs - 1));
    //     }

    //     return memo[i][j][robs]= max(take,skip);
    // }

public:
    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size();
        n = coins[0].size();
        vector<vector<vector<long long>>> memo(m + 1, vector<vector<long long>>(n + 1, vector<long long>(3, -1e17)));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                for (int k = 0; k <= 2; k++) {
                    
                    if (i == m - 1 && j == n - 1) {
                        long long option1 = coins[i][j];
                        long long option2 = -1e17;
                        if (coins[i][j] < 0 && k > 0) option2 = 0;
                        memo[i][j][k] = max(option1, option2);
                        continue;
                    }

                    long long move_next = max(memo[i + 1][j][k], memo[i][j + 1][k]);
                    memo[i][j][k] = coins[i][j] + move_next;


                    if (coins[i][j] < 0 && k > 0) {
                        long long skip_next = max(memo[i + 1][j][k - 1], memo[i][j + 1][k - 1]);
                        memo[i][j][k] = max(memo[i][j][k], 0 + skip_next);
                    }
                }
            }
        }


        return memo[0][0][2];
        
    }
};