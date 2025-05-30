class Solution {
public:
    int trap(vector<int>& height) {
        int  n= height.size();
        vector<int> post(n);;
        int premaxi = 0, postmaxi = 0;
        for(int i = 0; i<n; i++){
            postmaxi = max(postmaxi,height[n-i-1]);
            post[n-i-1] = postmaxi;
        }

        int result = 0;
        for(int i = 0; i<n; i++){
            premaxi = max(premaxi,height[i]);
            result += min(premaxi,post[i]) - height[i];
        }
        return result;
    }
};