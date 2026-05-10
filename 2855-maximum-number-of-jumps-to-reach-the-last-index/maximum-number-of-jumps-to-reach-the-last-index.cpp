class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        // vector<vector<int>> adj;
        // for(int i = 0; i<n;i++){
        //     for(int j = i+1; j<n; j++){
        //         if(abs(nums[j] - nums[i]) <= target){
        //             adj[i].push_back(j);
        //         }
        //     }
        // }
        // int steps = -1;

        int n = nums.size();
        vector<int> maxsteps(n,0);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                if(abs(nums[j] - nums[i]) <= target ){
                    if(j == 0 ||  maxsteps[j] != 0)
                    maxsteps[i] = max(maxsteps[i],maxsteps[j]+1);
                }
            }
        }
        return( maxsteps[n-1] == 0) ? -1 : maxsteps[n-1 ];
    }
};