class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int current = 1, previous = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                current++;

                if(current/2 >= k )return true;
                
            }else{
                previous = current;
                current = 1;
                
            }
            if(min(previous,current) >= k)return true;
        }
        return false;
    }
};