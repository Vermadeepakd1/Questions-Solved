class Solution {
public:
    int mod = 1e9+7;
    int maxSum(vector<int>& nums, int k) {
        vector<int> bits(31,0);

        for(int num : nums){
            for(int i = 0; i<31; i++){
                if((num & (1<<i)) != 0 )bits[i]++;
            }
        }

        int ans = 0;

        for(int i = 0; i<k; i++){
            long long val = 0;
            for(int j = 0; j<31; j++){
                if(bits[j] > i) val |= (1<<j);
            }
            ans = (ans + (val*val)%mod)%mod;
        }
        return ans;
    }
};