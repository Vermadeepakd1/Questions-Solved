class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int n : nums) freq[n]++;
        int ans = 0;
        for(auto &[k,v]: freq){
            if(v==1){
                ans = k;
            }
        }
        return ans;
    }
};