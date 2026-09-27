class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        int result = -1;

        int n = nums.size();

        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                for(int k = j+1; k<n; k++){
                    int sum = nums[i]+nums[j]+nums[k];
                    if(abs(sum-target) < diff){
                        diff= abs(sum-target);
                        result = sum;
                    }
                }
            }
        }
        return result;
    }
};