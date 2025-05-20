class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int x = s.length();
        if(x==0) return 0;
        int maxlen = 0,currlen = 0;
        unordered_map<int,int> mp;
        int l = 0,r= 0;
        mp[s[r]]++;
        maxlen = max(maxlen, r-l+1);
        while(r < x -1  && l <=r){
            r++;
            mp[s[r]]++;
            if(mp[s[r]] == 2){
                while(mp[s[r]] > 1){
                    mp[s[l]]--;
                    l++;
                }
            }
            maxlen = max(maxlen, r - l + 1);
        }
        return maxlen;
    }
};