class Solution {
    int n;
    int memo[101][101][2]; 

    int getstones(vector<int>& piles, int idx, int m, int turn) {
        if (idx == n) return 0;
        if (memo[idx][m][turn] != -1) return memo[idx][m][turn];

        int sum = 0;
        
        if (turn == 1) { 
            int maxAliceStones = 0;
            for (int i = idx; i <= min(idx + 2 * m - 1, n - 1); i++) {
                sum += piles[i];
                int nextM = max(m, i - idx + 1);
                maxAliceStones = max(maxAliceStones, sum + getstones(piles, i + 1, nextM, 0));
            }
            return memo[idx][m][turn] = maxAliceStones;
        } else { 
            int minAliceStones = INT_MAX;
            for (int i = idx; i <= min(idx + 2 * m - 1, n - 1); i++) {
                int nextM = max(m, i - idx + 1);
                minAliceStones = min(minAliceStones, getstones(piles, i + 1, nextM, 1));
            }
            return memo[idx][m][turn] = minAliceStones;
        }
    }

public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(memo, -1, sizeof(memo));
        return getstones(piles, 0, 1, 1);
    }
};