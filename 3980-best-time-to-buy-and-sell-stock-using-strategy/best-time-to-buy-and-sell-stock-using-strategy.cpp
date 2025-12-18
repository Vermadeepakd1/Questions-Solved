class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> preprices(n),prescore(n);
        preprices[0] = prices[0];
        prescore[0] = prices[0]*strategy[0];

        for(int i = 1; i<n; i++){
            preprices[i] = prices[i]  + preprices[i-1];
            prescore[i] = prescore[i-1] + (prices[i]*strategy[i]);
        }

        // for(int i = 0; i<n; i++){
        //     cout << preprices[i] << " " ;
        // }
        // cout << endl;
        long long ans = prescore[n-1];
        for(int i = k; i<=n; i++){
            int start = i-k;
            int end = i-1;

            long long score = 0;
            score += (start > 0)?prescore[start-1]:0;
            // cout << score << endl;
            score += ( preprices[end]- ((start -1 + k/2 >=0) ?preprices[start + k/2 -1]:0 ));
            // cout << score << endl;
            score += prescore[n-1] - prescore[end];
            // cout << score << endl;
            ans = max(ans,score);

            // cout << "---------------" << endl;
        }

        return ans;
    }
};