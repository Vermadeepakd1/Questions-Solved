class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        vector<long long> score(n, 1);
        for (int i = 1; i < n; i++) {
            if (prices[i-1] - prices[i] == 1)
                score[i] += score[i - 1];
            
            // cout << score[i] << " ";
        }

        long long sum = accumulate(score.begin(), score.end(), 0LL);

        return sum;
    }
};