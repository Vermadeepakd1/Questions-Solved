class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> pnums;
        int n = nums.size();
        for(int i = 0; i < n;i++){
            pnums.push_back({nums[i],i});
        }

        sort(pnums.begin(),pnums.end(),greater<>());

        pnums.resize(k);

        sort(pnums.begin(),pnums.end(),[](auto &a, auto &b){
            return a.second < b.second;
        });

        vector<int> result;

        for(auto &[val,idx]: pnums){
            result.push_back(val);
        }

        return result;
    }
};