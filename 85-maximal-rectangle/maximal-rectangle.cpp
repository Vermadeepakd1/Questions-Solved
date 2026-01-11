class Solution {
    vector<int> nsr(vector<int> &height){
        stack<int> st;
        int n = height.size();
        vector<int> ans(n);

        for(int i = n-1; i>=0; i--){
            if(st.empty()){
                ans[i] = n;
            }else{
                while(!st.empty() && height[st.top()] >= height[i])st.pop();
                if(!st.empty()){
                    ans[i] = st.top();
                }else{
                    ans[i] = n;
                }
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> nsl(vector<int> &height){
        stack<int> st;
        int n = height.size();
        vector<int> ans(n);

        for(int i = 0; i<n; i++){
            if(st.empty()){
                ans[i] = -1;
            }else{
                while(!st.empty() && height[st.top()] >= height[i])st.pop();
                if(!st.empty()){
                    ans[i] = st.top();
                }else{
                    ans[i] = -1;
                }
            }
            st.push(i);
        }
        return ans;
    }
    int findmaxarea(vector<int>&height){
        vector<int> r = nsr(height);
        vector<int> l = nsl(height);
        int n = height.size();

        int maxarea = 0;
        for(int i = 0; i<n; i++){
            int a = height[i] * (r[i]-l[i]-1);

            maxarea = max(maxarea,a);
        }

        return maxarea;

    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> height(m);
        for(int i = 0; i<m; i++){
            height[i] = (matrix[0][i] == '1')?1:0;
        }

        int maxArea = findmaxarea(height);

        for(int row = 1; row<n; row++){
            for(int col = 0; col <m; col++){
                if(matrix[row][col] == '0')height[col]=0;
                else{
                    height[col]+=1;
                }
            }
            maxArea = max(maxArea,findmaxarea(height));
        }

        return maxArea;
    }
};