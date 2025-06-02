class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int ptr = 0;
        int k =1;
        for(int i = 1; i<n; i++){
            if(nums[i] == nums[i-1]){
                continue;
            }
            ptr++;
            k++;
            nums[ptr] = nums[i];
        }
        return k;
    }
};