class Solution {
public:
    string rle(string temp){
        string ans = "";
        char curr = '.';
        int cnt = 0;
        for(char ch : temp){
            if(cnt == 0){
                curr = ch;
                cnt = 1;
            }else if(ch == curr){
                cnt++;
            }else{
                ans += to_string(cnt) + curr;
                curr=ch;
                cnt=1;
            }
        }
        ans += to_string(cnt) + curr;
        return ans;
    }
    string countAndSay(int n) {
        vector<string>result(n+1);
        result[1] = "1";

        for(int i = 2; i<=n; i++){
            result[i] = rle(result[i-1]);
        }
        return result[n];
    }
};