class Solution {
public:
    vector<vector<int>> result;
    void findcomb(int n, int k, int idx, vector<int>&curr,  int start){
        if(curr.size() == k){result.push_back(curr);
        return;}
        for(int i = start; i<=n; i++){
            // if(vis[i])continue;
            // vis[i]=true;
            curr.push_back(i);
            findcomb(n,k,idx+1,curr, i+1);
            // vis[i]=false;
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        findcomb(n,k,0,curr,1) ; // n,k,index
        return result;
    }
};