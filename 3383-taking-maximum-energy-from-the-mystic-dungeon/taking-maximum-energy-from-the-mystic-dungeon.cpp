class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n,0);
        for(int i = n-1; i>=0; i--){
            if(i+k <= n-1){
                dp[i] = dp[i+k] + energy[i];
            }else{
                dp[i] = energy[i];
            }
        }

        int maix = *max_element(dp.begin(),dp.end());

        return maix;
    }
};