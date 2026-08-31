class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string curr = "";

        for (char ch : path) {
            if (ch != '/') {
                curr += ch;
            } else {
                if (curr.size() > 0) {
                    if (curr == "..") {
                        if (!st.empty())
                            st.pop();
                    } else if (curr == ".") {
                        curr = "";
                    } else {
                        st.push(curr);
                    }
                }
                curr = "";
            }
        }
        if (curr.size() > 0) {
            if (curr == "..") {
                if (!st.empty())
                    st.pop();
            } else if (curr == ".") {
                curr = "";
            } else {
                st.push(curr);
            }
        }
        curr = "";
        string result = "";
        stack<string> st2;
        while (!st.empty()) {
            string t = st.top();
            st.pop();
            st2.push(t);
            st2.push("/");
        }
        while (!st2.empty()) {
            result += st2.top();
            st2.pop();
        }
        if(result == "")result = "/";
        return result;
    }
};