class Solution {
public:
    string convert(string s, int numRows) {
        vector<string>ans(numRows,"");

        int dir = 1;
        int row = 0;
        
        for(char ch : s){
            ans[row] += ch;
            if(numRows == 1)continue;
            row += dir;
            if(row == numRows-1)dir=-1;
            else if(row == 0)dir=1;
        }

        string result = "";
        for(string k : ans){
            result += k;
        }
        return result;
    }
};