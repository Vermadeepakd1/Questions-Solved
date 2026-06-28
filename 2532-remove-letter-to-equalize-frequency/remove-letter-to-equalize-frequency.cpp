class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char, int> mp;
        for (char& ch : word)
            mp[ch]++;

        map<int, int> mp2;
        for (auto it : mp) {
            mp2[it.second]++;
        }
        if (mp2.size() > 2)
            return false;
        int a = -1, acount = 0, b = -1, bcount = 0;
        for (auto it : mp2) {
            if (a == -1) {
                a = it.first;
                acount = it.second;
            } else {
                b =it.first;
                bcount = it.second;
            }
        }
        if(bcount == 0 && a==1)return true;
        if(bcount == 0 && acount==1)return true;
        if(bcount == 1 && b==a+1)return true;
        if(a==1 && acount==1)return true;

        return false;
    }
};