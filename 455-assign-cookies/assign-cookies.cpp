class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ans = 0;
        int gi = 0, si =0;
        while(si < s.size() && gi < g.size()){
            if(g[gi] <= s[si]){
                gi++;
                si++;
                ans++;
            }else si++;
        }
        return ans;
    }
};