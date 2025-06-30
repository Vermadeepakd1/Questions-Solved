class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int n : nums){
            freq[n]++;
        }
        vector<int> uniq;
        for(auto &[i,v]:freq){
            uniq.push_back(i);
        }
        sort(uniq.begin(),uniq.end());
        int maxi = 0;

        for(int i = 0; i<uniq.size()-1; i++){
            if(uniq[i+1] - uniq[i] == 1){
                maxi = max(maxi, freq[uniq[i]]+freq[uniq[i+1]]);
            }
        }
        return maxi;
    }
};