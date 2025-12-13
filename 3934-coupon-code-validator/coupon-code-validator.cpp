class Solution {
    bool isCode(string code){
        for(char c : code){
            if(!isalnum(c) && c != '_')return false;
        }
        return true;
    }

    bool isBL(string bl){
        if(bl == "electronics" || bl == "grocery" || bl == "pharmacy" || bl == "restaurant")return true;
        return false;
    }

public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<string,string>> result;
        int n = code.size();
        for(int i = 0; i<n; i++){
            if(isActive[i] && isCode(code[i]) && isBL(businessLine[i]))result.push_back({businessLine[i], code[i] });
        }

        sort(result.begin(),result.end());

        vector<string> ans;
        for(auto &i : result){
            if(i.second != "")
            ans.push_back(i.second);
        }

        return ans;
    }
};