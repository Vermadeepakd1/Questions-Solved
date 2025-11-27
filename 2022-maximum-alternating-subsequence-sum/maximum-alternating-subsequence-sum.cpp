class Solution {
    int n;
    long long t[100001][2];
    // long long solve(vector<int>& nums, int idx, bool flag){
    //     if(idx >= nums.size())return 0;

    //     if(t[idx][flag] != -1)return t[idx][flag];
        
    //     long long skip = solve(nums,idx+1,flag);
    //     int val = nums[idx];
    //     if(!flag){
    //         val = -val;
    //     }
    //     long long take = solve(nums, idx+1, !flag) + val;

    //     return t[idx][flag] = max(skip,take);
    // }
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        memset(t, -1, sizeof(t));

        t[0][0] = 0; // 0 =even
        t[0][1] = nums[0];
        for(int i =1; i<n; i++){
            t[i][0] = max(t[i-1][0], t[i-1][1] - nums[i]);
            t[i][1] = max(t[i-1][1], t[i-1][0] + nums[i] );
        }

        return max(t[n-1][0], t[n-1][1]);

        // return solve(nums, 0 , true);
    }
};