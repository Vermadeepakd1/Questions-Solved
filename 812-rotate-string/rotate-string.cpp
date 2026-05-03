class Solution {
public:
    bool rotateString(string s, string goal) {
        int l = s.length();
        int cnt = 0;
        if(s==goal)return true;
        while(cnt < l){
            rotate(s.begin(),s.begin()+1,s.end());
            if(s==goal)return true;
            cnt++;
        }
        return false;
    }
};