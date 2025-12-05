class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>last(26,0);
        int n = s.length();
        for(int i = 0; i<n; i++){
            last[s[i]-'a']=i;
        }
        vector<int> ans;
        int end = 0,length = 0;
        for(int i = 0; i<n; i++){
            end = max(end,last[s[i]-'a']);
            length++;
            if(i == end){
                ans.push_back(length);
                length = 0;
            }
        }
        return ans;
    }
};