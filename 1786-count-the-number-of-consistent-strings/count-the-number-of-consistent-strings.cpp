class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> allow(allowed.begin(),allowed.end());
        int cnt =0;
        for(auto x : words){
            bool flag = true;
            for(int i =0; i<x.length(); i++){
                if(allow.find(x[i]) == allow.end()){
                    flag = false;
                }
            }
            if(flag){
                cnt++;
            }
        }
        return cnt;
    }
};