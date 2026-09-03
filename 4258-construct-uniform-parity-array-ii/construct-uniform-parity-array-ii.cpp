class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(),nums1.end());
        bool isodd =( nums1[0]&1 );
        int sodd = -1, seven = -1;
        if(isodd)sodd = nums1[0];
        else seven =  nums1[0];

        int n = nums1.size();
        for(int i = 1; i<n; i++){
            if(!isodd){
                if(nums1[i]&1){
                    if(sodd == -1)return false;
                }
            }
        }
        return true;
    }
};