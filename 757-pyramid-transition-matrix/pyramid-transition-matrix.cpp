class Solution {
    unordered_set<string> failed;
    bool findpyramid(unordered_map<string, string>& mp, string bottom, int idx,
                     string newbase) {
        if (idx == bottom.size() - 1) {
            if (failed.count(newbase)) return false;
            if (bottom.size() == 2)
                return true;
            else
                return findpyramid(mp, newbase, 0, "");
        }

        string tofind = "";
        tofind += bottom[idx];
        tofind += bottom[idx + 1];

        if (mp.count(tofind)) {
            for (char c : mp[tofind]) {
                newbase += c;
                if (findpyramid(mp, bottom, idx + 1, newbase))
                    return true;
                newbase.pop_back();
            }
        }
        if (idx == 0) failed.insert(bottom);
        return false;
    }

public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, string> mp;

        for (string& s : allowed) {
            string base = s.substr(0, 2);
            mp[base] += s[2];
        }
        string newbase = "";
        bool ans = findpyramid(mp, bottom, 0, newbase);

        return ans;
    }
};