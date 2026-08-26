class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> mp;

        for(auto &t : trips){
            int p = t[0], f = t[1], to = t[2];
            mp[f] += p;
            mp[to] -= p;
        }
        int cur = 0;
        for(auto it: mp){
            cur += it.second;
            if(cur > capacity)return false;
        }
        return true;

    }
};