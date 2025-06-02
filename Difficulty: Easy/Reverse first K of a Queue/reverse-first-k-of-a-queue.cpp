class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        int n = q.size();
        if(n < k){
            return q;
        }
        stack<int> st;
        for(int i = 0;  i<k ; i++){
            int x = q.front();
            q.pop();
            st.push(x);
            
        }
        for(int i = 0; i<k ; i++){
            int x = st.top();
            st.pop();
            q.push(x);
        }
        for(int i = 0; i< n-k; i++){
            int x = q.front();
            q.pop();
            q.push(x);
        }
        return q;
    }
};