class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";

        for(char c: num){
            while(!ans.empty() && k>0 && c < ans.back()){
                ans.pop_back();
                k--;
            }

            if(!ans.empty() || c!= '0')ans.push_back(c);
        }
        while (k > 0 && !ans.empty()) {
            ans.pop_back();
            k--;
        }
        return (ans.empty())?"0":ans;
    }
};