class Solution {
  public:
    string FirstNonRepeating(string &s) {
        string ans = "";
        unordered_map<char,int> mp;
        queue<char> q;
        
        for(char c : s){
            q.push(c);
            mp[c]++;
            while(!q.empty() && mp[q.front()] != 1){
                q.pop();
            }
            if(q.empty()){
                ans += '#';
            }else{
                ans += q.front();
            }
        }
        return ans;
    }
};