class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int> mp;
        int maxi = -1, maxnum = -1;
        for(auto num : arr){
            mp[num]++;
            if(mp[num] > maxi){
                maxi = mp[num];
                maxnum = num;
            }
        }
        return maxnum;
    }
};