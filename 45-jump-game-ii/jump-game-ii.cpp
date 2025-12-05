class Solution {
public:
    int jump(vector<int>& nums) {
        int current_end = 0, farthest = 0, jumps = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            farthest = max(farthest,i+nums[i]);
            if(i == current_end && i!= n-1){
                jumps++;
                current_end = farthest;
            }
        }
        return jumps;
    }
};