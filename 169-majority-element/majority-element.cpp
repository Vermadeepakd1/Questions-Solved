class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = (nums.size()+1)/2;
        int ans = -1;
        unordered_map<int,int> freq;
        for(int num : nums){
            freq[num]++;
            if(freq[num] >= n){
                ans = num;
                break;
            }
        }
        return ans;
    }
};