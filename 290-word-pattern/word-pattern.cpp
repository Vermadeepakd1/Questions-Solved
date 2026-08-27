class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> ptos;
        unordered_map<string, char> stop;

        int n = pattern.size();

        string temp = "";
        int idx = 0;

        for (char ch : s) {
            if(idx >= pattern.size())return false;
            if (ch != ' ') {
                temp += ch;
            } else {
                if (stop.count(temp) && stop[temp] != pattern[idx])
                    return false;
                if (ptos.count(pattern[idx]) && ptos[pattern[idx]] != temp)
                    return false;
                stop[temp] = pattern[idx];
                ptos[pattern[idx]] = temp;
                temp = "";
                idx++;
            }
        }
        if(idx >= pattern.size())return false;
        if (stop.count(temp) && stop[temp] != pattern[idx])
            return false;
        if (ptos.count(pattern[idx]) && ptos[pattern[idx]] != temp)
            return false;
        stop[temp] = pattern[idx];
        ptos[pattern[idx]] = temp;
        idx++;

        if(idx < pattern.size())return false;

        return true;
    }
};