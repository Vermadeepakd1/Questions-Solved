class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> mp(26,0);
        for(char ch: magazine)mp[ch-'a']++;
        for(char ch: ransomNote)
        {
            mp[ch-'a']--;
            if(mp[ch-'a']<0)return false;
        }
        return true;
    }
};