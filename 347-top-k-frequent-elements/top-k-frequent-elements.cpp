class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int i : nums){
            freq[i]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq; //freq,num
        for(auto it : freq){
            pq.push({it.second,it.first});
            if(pq.size() > k)pq.pop();
        }
        vector<int> result;
        while(!pq.empty()){
            int a = pq.top().second;
            pq.pop();
            result.push_back(a);
        }
        return result;
    }
};