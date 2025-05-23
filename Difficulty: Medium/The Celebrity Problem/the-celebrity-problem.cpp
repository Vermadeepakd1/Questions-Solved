class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n = mat.size();
        stack<int> st;
        for(int i = 0; i<n; i++){
            st.push(i);
        }
        
        while(st.size() > 1){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            
            if(mat[a][b]){
                st.push(b);
            }else{
                st.push(a);
            }
        }
        int celeb = st.top();
        
        bool flag = true;
        for(int i = 0; i<n; i++){
            if(i == celeb) continue;
            
            if(mat[celeb][i] == 1) {flag = false;
            break;}
            if(mat[i][celeb] == 0) {flag = false;
            break;}
        }
        if(flag) return celeb;
        else return -1;
    }
};