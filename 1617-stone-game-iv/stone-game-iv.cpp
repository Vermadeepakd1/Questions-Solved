const int MAXN = 100000;
vector<bool> dp(MAXN + 1, false);

auto init = []() {
    vector<int> squares;
    for (int i = 1; i * i <= MAXN; i++) {
        squares.push_back(i * i);
    }

    for (int i = 1; i <= MAXN; i++) {
        for (int k : squares) {
            if (k > i) break;
            if (!dp[i - k]) { 
                dp[i] = true;
                break;     
            }
        }
    }
    return 0;
}();

class Solution {
public:
    bool winnerSquareGame(int n) {
        return dp[n]; 
    }
};