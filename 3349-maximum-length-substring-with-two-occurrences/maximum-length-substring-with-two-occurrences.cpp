class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> mp;

        int j = 0;
        int i = 0;
        int  n = s.length();

        int maxi = 1;

        while(j < n){
            mp[s[j]]++;
            while(mp[s[j]]>2){
                mp[s[i]]--;
                i++;
            }
            maxi = max(maxi, j-i+1);
            j++;
        }
        return maxi;
    }
};