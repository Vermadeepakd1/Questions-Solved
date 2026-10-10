class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {
        priority_queue<int> pq;
        int n = nums1.size();
        unordered_map<int,int> mp;
        for (int i = 0; i < n; i++) {
            mp[abs(nums1[i] - nums2[i])]++;
        }
        for(auto it: mp){
            pq.push(it.first);
        }
        long long x = k1 + k2;
        while (x) {
            int t = pq.top();
            if(t==0)break;
            pq.pop();
            int req = mp[t];
            if (x > req) {
                x -= req;
                if(!mp.count(t-1))pq.push(t-1);
                mp[t-1]+=mp[t];
                mp.erase(t);
            } else {
                if(!mp.count(t-1))pq.push(t-1);
                mp[t-1]+=x;
                mp[t]-=x;
                pq.push(t);
                break;
            }
        }
        long long ans = 0;
        while (!pq.empty()) {
            int t = pq.top();
            pq.pop();
            ans += 1ll*t * t*mp[t];
        }
        return ans;
    }
};