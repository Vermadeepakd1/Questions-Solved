class Solution {
    // tc - O(nlogn)
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        vector<bool> ismapped(256, false); 

        for (int i = 0; i < s.size(); i++) {
            char c1 = s[i];
            char c2 = t[i];

            if (mp.count(c1) && mp[c1] != c2) return false;

            if (!mp.count(c1) && ismapped[c2]) return false;

            mp[c1] = c2;
            ismapped[c2] = true;
        }

        return true;
    }
};