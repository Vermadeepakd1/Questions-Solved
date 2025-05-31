class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common = "";
        int n = strs.size();
        bool flag = true;
        for(int i = 0; i<  strs[0].size(); i++){
            char c = strs[0][i];
            for(string str: strs){
                if(!(str.length() > i && str[i] == c)){
                    flag = false;
                    break;
                }
            }
            if(!flag){
                return common;
            }else{
                common+=c;
            }
        }
        return common;

    }
};