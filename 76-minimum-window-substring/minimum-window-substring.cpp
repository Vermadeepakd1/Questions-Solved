class Solution {
    bool isokay(unordered_map<char,int> &a, unordered_map<char,int>&b){
        for(auto &[key,val]: a){
            if(val > b[key])return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        string ans = "";
        int len = 0;

        unordered_map<char,int> target,curr;

        for(char ch : t)target[ch]++;

        int n = s.length();
        int i = 0, j = 0;

        while(j<n){
            curr[s[j]]++;

            while(curr[s[i]] > target[s[i]]){
                curr[s[i]]--;
                i++;
            }

            if(isokay(target,curr)){
                len = j-i+1;
                if(len < ans.length() || ans ==""){
                    ans = s.substr(i,len);
                }
            }
            j++;
        }
        return ans;

    }
};