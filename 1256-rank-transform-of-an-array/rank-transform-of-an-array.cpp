class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> st(arr.begin(),arr.end());
        int i = 1;
        unordered_map<int,int> mp;
        for(auto it: st){
            mp[it] = i;
            i++;
        }
        vector<int> result;
        for(auto i: arr){
            result.push_back(mp[i]);
        }
        return result;
    }
};