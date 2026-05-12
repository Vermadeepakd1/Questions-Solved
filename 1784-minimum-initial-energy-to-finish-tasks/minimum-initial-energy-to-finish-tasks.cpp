class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        priority_queue<pair<int,pair<int,int>>> pq;
        for(auto &v : tasks){
            pq.push({v[1]-v[0],{v[0],v[1]}});
        }
        int req = 0;
        int curr = 0;
        while(!pq.empty()){
            auto s = pq.top().second;
            pq.pop();
            if(curr < s.second){
                int diff = s.second - curr;
                req += diff;
                curr += diff;
            }
            curr -= s.first;
        }
        return req;
    }
};