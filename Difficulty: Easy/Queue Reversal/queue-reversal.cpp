// function Template for C++

class Solution {
  public:
    queue<int> reverseQueue(queue<int> &q) {
        stack<int>st;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            st.push(front);
        }
        while(!st.empty()){
            int top = st.top();
            st.pop();
            q.push(top);
        }
        return q;
    }
};