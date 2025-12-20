class Solution {
    bool check(vector<string> &strs, int idx){
        int n = strs.size();
        for(int i = 1; i<n; i++){
            if(strs[i][idx] < strs[i-1][idx])return false;
        }
        return true;
    }
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].length();
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(!check(strs,i))cnt++;
        }
        return cnt;
    }
};