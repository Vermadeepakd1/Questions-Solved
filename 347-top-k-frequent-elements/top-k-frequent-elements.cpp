class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i : nums)mp[i]++;

        priority_queue<pair<int,int>> pq;
        for(auto [key,val] : mp)pq.push({val,key});

        vector<int> result;

        while(k--){
            auto [val,key] = pq.top();
            pq.pop();
            result.push_back(key);
        }

        return result;
    }
};