class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int m = nums1.size(), n = nums2.size(),k =0,l=0;
        vector<vector<int>> ans;
        while(k<m && l <n){
            if(nums1[k][0] < nums2[l][0]){
                ans.push_back(nums1[k++]);
            }
            else if(nums1[k][0] > nums2[l][0]){
                ans.push_back(nums2[l++]);
            }
            else{
                ans.push_back({nums1[k][0], nums1[k++][1] + nums2[l++][1]});
            }
        }
        while(k<m){
            ans.push_back(nums1[k++]);
        }
        while(l<n){
            ans.push_back(nums2[l++]);
        }
        return ans;
    }
};