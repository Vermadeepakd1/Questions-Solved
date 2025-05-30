class Solution {
public:
    int trap(vector<int>& height) {
        int  n= height.size();
        vector<int> pre(n),post(n);;
        int premaxi = 0, postmaxi = 0;
        for(int i = 0; i<n; i++){
            premaxi = max(premaxi,height[i]);
            pre[i] = premaxi;

            postmaxi = max(postmaxi,height[n-i-1]);
            post[n-i-1] = postmaxi;
        }

        int result = 0;
        for(int i = 0; i<n; i++){
            result += min(pre[i],post[i]) - height[i];
        }
        return result;
    }
};