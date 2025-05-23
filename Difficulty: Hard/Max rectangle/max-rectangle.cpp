class Solution {
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prev(n), next(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        int area = 0;
        for (int i = 0; i < n; i++) {
            int width = next[i] - prev[i] - 1;
            int currArea = heights[i] * width;
            area = max(area, currArea);
        }

        return area;
    }
  public:
    int maxArea(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int area = largestRectangleArea(mat[0]);
        
        for(int i = 1; i<n; i++){
            for(int j = 0; j<m;  j++){
                if(mat[i][j] != 0){
                    mat[i][j] = mat[i-1][j] +1;
                }
            }
            area = max(area, largestRectangleArea(mat[i]));
        }
        return area;
        
    }
};