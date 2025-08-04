class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> f1(26,0),f2(26,0);
        for(char c : s){
            f1[c-'a']++;
        }
        for(char c : t){
            f2[c-'a']++;
        }
        return f1 == f2;
    }
};