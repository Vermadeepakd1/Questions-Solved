class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                int maxi = nums1[i]*nums2[j];
                if(i >0 && j > 0){
                    maxi = max(maxi, maxi + dp[i-1][j-1]);
                }
                if(i > 0)maxi = max(maxi, dp[i-1][j]);
                if(j > 0)maxi = max(maxi, dp[i][j-1]);

                dp[i][j] = maxi;
            }
        }

        return dp[n-1][m-1];
    }
};