class Solution {
public:
    int countCollisions(string directions) {
        int ans = 0;
        stack<char> st;
        for (char i : directions) {
            if (i == 'R')
                st.push(i);
            else if (i == 'S') {

                while (!st.empty()) {
                    if (st.top() == 'R') {

                        ans += 1;
                    }
                    st.pop();
                }

                st.push('S');
            } else {
                if (st.empty()) {
                    continue;
                } else if (st.top() == 'R') {
                    st.pop();
                    ans += 2;
                    while (!st.empty()) {
                    if (st.top() == 'R') {

                        ans += 1;
                    }
                    st.pop();
                }
                    st.push('S');
                } else if (st.top() == 'S') {
                    ans += 1;
                }
            }
        }
        
        return ans;
    }
};