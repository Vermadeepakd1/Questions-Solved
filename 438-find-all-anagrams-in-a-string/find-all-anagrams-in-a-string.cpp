class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> target(26,0), curr(26,0);


        for(char ch : p)target[ch-'a']++;

        int l = p.length();
        int n = s.length();

        if(l > n)return {};
        vector<int> result;

        for(int i = 0; i<l ; i++){
            int ch = s[i]-'a';
            curr[ch]++;
            if(curr == target)result.push_back(i-l+1);
        }
        for(int i = l; i<n; i++){
            curr[s[i-l]-'a']--;
            curr[s[i]-'a']++;
            if(curr == target)result.push_back(i-l+1);
        }
        return result;
    }
};