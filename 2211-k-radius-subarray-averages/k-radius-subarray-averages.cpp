class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result(n,-1);
        long long sum = 0;
        for(int i = 0; i<n; i++){
            sum += nums[i];
            if(i < 2*k){
                continue;
            }
            int avg = sum/(2*k+1);
            result[i-k] = avg;
            sum -= nums[i-2*k];
        }
        return result;
    }
};