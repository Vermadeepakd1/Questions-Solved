class Solution {
public:
    string digitSum(string s, int k) {
        while(s.length() > k){
            string newstr = "";
            for(int i = 0; i<s.length(); i+=k){
                string temp = "";
                if(i+k < s.length())
                temp = s.substr(i,k);
                else temp = s.substr(i);

                int digsum = 0;
                for(char ch : temp)digsum += (ch-'0');

                newstr += to_string(digsum);
            }
            s= newstr;
        }
        return s;
    }
};