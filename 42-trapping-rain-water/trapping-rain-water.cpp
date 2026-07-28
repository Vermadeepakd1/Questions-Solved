class Solution {
    //using two pointers
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftmax = height[0], rightmax = height[n-1];
        int i = 0, j = n-1;
        int area = 0;

        while(i < j){
            leftmax = max(leftmax, height[i]);
            rightmax = max(rightmax,height[j]);

            if(leftmax < rightmax){
                area += leftmax - height[i];
                i++;
            }else {
                area += rightmax - height[j];
                j--;
            }
        }
        return area;
    }
};