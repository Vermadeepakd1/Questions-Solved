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
        if(n==1)return "1";
        return rle(countAndSay(n-1));
    }
};