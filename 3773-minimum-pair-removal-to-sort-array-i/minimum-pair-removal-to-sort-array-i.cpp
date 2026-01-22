class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(),temp.end());
        if(temp == nums)return 0 ;
        int cnt = 0;
        while(temp != nums){
            cnt++;
            int n = nums.size();
            int idx = -1;
            int minsum = INT_MAX;
            for(int i = 0; i<n-1; i++){
                if(nums[i] + nums[i+1] < minsum){
                    minsum = nums[i] + nums[i+1];
                    idx = i;
                }
            }
            nums.erase(nums.begin()+idx);
            nums[idx] = minsum;
            temp = nums;
            sort(temp.begin(),temp.end());
        }
        return cnt;
    }
};