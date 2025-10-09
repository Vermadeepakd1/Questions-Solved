class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> prefix_sum_map;
        prefix_sum_map[0] = 1;
        int current_sum = 0;
        int cnt = 0;
        for(int i = 0; i<n; i++){
            current_sum += nums[i];
            if(prefix_sum_map.find(current_sum - k) != prefix_sum_map.end()){
                cnt += prefix_sum_map[current_sum - k];
            }
            prefix_sum_map[current_sum]++;
        }
        return cnt;
    }
};