class Solution {
public:
    // ranges  - 2 - a+1 - a+b - b+limit - 2*limit
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> cost(2*limit+2);

        for(int i = 0; i<n/2; i++){
            int a = min(nums[i],nums[n-i-1]);
            int b = max(nums[i],nums[n-i-1]);

            cost[2] += 2;
            cost[a+1] -=2;

            cost[a+1] += 1;
            cost[a+b] -= 1;

            cost[a+b+1] += 1;
            cost[b+limit+1] -=1;

            cost[b+limit+1] += 2;
        }
        int ans = n;
        int curr = 0;
        for(int i =2; i<=2*limit; i++){
            curr += cost[i];
            ans = min(curr,ans);
        }
        return ans;
    }
};