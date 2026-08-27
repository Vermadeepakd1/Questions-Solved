class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<int,long long> mp;

        for(auto &s : segments){
            int u = s[0], v = s[1], c = s[2];
            mp[u] += c;
            mp[v] -= c;
        }

        int st = -1;
        vector<vector<long long>> result;
        long long curr = 0;
        
        for(auto it: mp){
            if(st == -1){
                st = it.first;
            }else{
                if(curr != 0)
                result.push_back({st,it.first,curr});
                st = it.first;
            }
            curr += it.second;
            
        }
        return result;
    }
};