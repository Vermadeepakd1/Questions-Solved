class Solution {
    void generate(vector<string> &coll, int n, int idx, string curr){
        if(curr.size() == n){
            coll.push_back(curr);
            return;
        }

        for(char ch = 'a' ; ch <= 'c'; ch++){
            if(idx == 0 || ch != curr[idx-1]) {
                curr += ch;
                generate(coll,n,idx+1,curr);
                curr.pop_back();
            }
        }
    }
public:
    string getHappyString(int n, int k) {
        vector<string> coll;
        string curr = "";
        generate(coll,n,0,curr);
        sort(coll.begin(),coll.end());
        if(coll.size() >= k)return coll[k-1];
        return "";
    }
};