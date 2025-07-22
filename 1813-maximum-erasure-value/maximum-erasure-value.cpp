class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = 0;
        unordered_map<int, int> mp;
        int currsum = 0, sum = 0;

        while (e < n ) {
            int num = nums[e];
            if (mp[num] == 0) {
                mp[num]++;
                currsum += num;
                e++;
            } else {
                while (nums[s] != num) {
                    mp[nums[s]]--;
                    currsum -= nums[s];
                    s++;
                }
                mp[nums[s]]--;  
                currsum -= nums[s];
                s++;
                mp[num]++;  
                currsum += num;
                e++;
            }
            sum = max(sum, currsum);
        }
        return sum;
    }
};