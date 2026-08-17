class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<P, vector<P>, greater<P>>pq;
        set<pair<int,int>> visited;

        pq.push({nums1[0]+nums2[0],{0,0}});
        visited.insert({0,0});
        vector<vector<int>> result;

        int n = nums1.size(), m = nums2.size();

        while(k > 0){
            P t = pq.top();
            pq.pop();
            int sum = t.first;
            auto [i,j] = t.second;

            visited.insert({i,j});
            result.push_back({nums1[i],nums2[j]});
            k--;

            if(i+1 < n && !visited.count({i+1,j})){

                pq.push({nums1[i+1]+nums2[j],{i+1,j}});
                visited.insert({i+1,j});
            }

            if(j+1 < m && !visited.count({i,j+1})){
                pq.push({nums1[i]+nums2[j+1],{i,j+1}});
                visited.insert({i,j+1});
            }
        }
        return result;
    }
};