class Solution {
public:
    int findLucky(vector<int>& arr) {
        int ans = -1;
        unordered_map<int,int> freq;
        for(int x : arr){
            freq[x]++;
        }
        for(auto &[x,v] : freq){
            if(x == v && x > ans){
                ans = x;
            }
        }
        return ans;
    }
};