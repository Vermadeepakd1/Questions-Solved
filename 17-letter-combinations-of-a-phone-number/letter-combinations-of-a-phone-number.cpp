class Solution {
    void findcombinations(unordered_map<char,string> &mp, string &digits, int n, int idx, vector<string>&ans, string temp){
        if(idx == n){
            ans.push_back(temp);
            return;
        }
        for(char c : mp[digits[idx]]){
            temp += c;
            findcombinations(mp,digits,n,idx+1,ans,temp);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mp;
        mp['2'] = "abc",mp['3'] = "def",mp['4']="ghi",mp['5']="jkl",mp['6']="mno",mp['7']="pqrs",mp['8']="tuv",mp['9']="wxyz";
        int n = digits.size();

        vector<string> ans;
        if(n == 0) return ans;
        string temp = "";
        findcombinations(mp,digits,n,0,ans,temp);
        return ans;
    }
};