class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxpre(n), minsuff(n);
        maxpre[0] = nums[0];
        for(int i = 1; i<n; i++)maxpre[i] = max(maxpre[i-1],nums[i]);
        minsuff[n-1]=nums[n-1];
        for(int i = n-2; i>=0; i--){
            minsuff[i] = min(nums[i],minsuff[i+1]);
        }

        vector<int> result(n);
        result[n-1] = maxpre[n-1];
        for(int i = n-2; i>=0; i--){
            if(maxpre[i] > minsuff[i+1]){
                result[i] = result[i+1];
            }else{
                result[i] = maxpre[i];
            }
        }
        return result;
    }
};