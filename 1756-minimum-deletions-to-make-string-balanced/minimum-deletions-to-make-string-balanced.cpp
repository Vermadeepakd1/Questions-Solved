class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> postasum(n+1,0);
        int cnt = 0;

        for(int i = n - 1; i >= 0; i--){
            if(s[i] == 'a') cnt++;
            postasum[i] = cnt;
        }
        vector<int>presumb(n+1,0);
        cnt=0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'b') cnt++;
            presumb[i] = cnt;
        }

        int mini = postasum[0];
        for(int i = 0; i<n; i++){
            int curr = presumb[i] + postasum[i + 1];
            mini = min(mini, curr);
        }

        return mini;
    }
};