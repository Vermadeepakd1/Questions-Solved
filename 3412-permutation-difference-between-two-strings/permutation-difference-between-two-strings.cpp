class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char,int> pos;
        for(int i=0; i< t.length(); i++){
            pos[t[i]] = i;
        }
        int result =0;
        for(int i =0; i<s.length(); i++){
            result+= abs(pos[s[i]] - i);
        }
        return result;
    }
};