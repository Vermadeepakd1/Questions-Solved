class Solution {
public:
    int calculate(string s) {
        long long number = 0; int result = 0 , sign = 1;
        stack <int> st;

        for(char ch : s)   {
            if(ch>='0' && ch <= '9'){
                number = number * 10 +(ch-'0');
            }else if(ch == '+'){
                result += number * sign;
                sign = 1;
                number = 0;
            }else if(ch =='-'){
                result += number*sign;
                sign =-1;
                number = 0;
            }else if(ch == '('){
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            }else if(ch==')'){
                result += number*sign;
                number = 0;
                int stacksign = st.top(); st.pop();
                int stackresult = st.top(); st.pop();

                result *= stacksign;
                result += stackresult;
            }
        }
        result += number*sign;
        return result;
    }
};