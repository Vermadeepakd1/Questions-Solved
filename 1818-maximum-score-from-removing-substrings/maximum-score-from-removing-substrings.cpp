class Solution {

    string removechars(string s,string sub){
        stack<char> st;

        for(int i = 0; i < s.length(); i++){
            if(st.empty()){
                st.push(s[i]);
            }else{
                if(s[i] == sub[1] && st.top() == sub[0]){
                    st.pop();
                }else{
                    st.push(s[i]);
                }
            }
        }

        string temp = "";
        while(!st.empty()){
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(),temp.end());

        return temp;
    }
public:
    int maximumGain(string s, int x, int y) {
        int n = s.length();
        int score = 0;
        stack<char> st;

        string maxStr = (x > y )? "ab" : "ba";
        string minStr = (x > y) ? "ba" : "ab";

        string temp_first = removechars(s,maxStr);
        score = ((n - temp_first.length())/2 )* max(x,y);

        string temp_second = removechars(temp_first,minStr);
        score += ((temp_first.length() - temp_second.length())/2 )*min(x,y);

        return score;
    }
};