class Solution {
public:
    bool closeStrings(string word1, string word2) {
        set<char> ac, bc;
        unordered_map<char,int> mp1,mp2;
        for(char ch : word1){
            ac.insert(ch);
            mp1[ch]++;
        }
        for(char ch: word2){
            bc.insert(ch);
            mp2[ch]++;
        }
        vector<int> acnt,bcnt;
        for(auto it: mp1){
            acnt.push_back(it.second);
        }
        for(auto it: mp2){
            bcnt.push_back(it.second);
        }

        for(char ch: ac){
            if(!bc.count(ch))return false;
        }

        sort(acnt.begin(),acnt.end());
        sort(bcnt.begin(),bcnt.end());

        return acnt == bcnt;
    }
};