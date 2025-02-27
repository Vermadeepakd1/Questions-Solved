class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for (string s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int first = stoi(st.top());
                st.pop();
                int second = stoi(st.top());
                st.pop();
                cout << first << " " << second << endl;
                if (s == "+") {
                    st.push(to_string(second + first));
                } else if (s == "*") {
                    st.push(to_string(second * first));
                } else if (s == "-") {
                    st.push(to_string(second - first));
                } else if (s == "/") {
                    st.push(to_string(second / first));
                }
            } else {
                st.push(s);
            }
        }
        return stoi(st.top());
    }
};