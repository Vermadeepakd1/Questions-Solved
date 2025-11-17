class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int curr = 0;
        bool found = false;

        for(int i : nums){
            if(i==1){
                if(found){
                    if(curr < k )return false;
                    curr = 0;
                }else{
                    found = true;
                }
            }else{
                if(found)curr++;
            }
        }
        return true;
    }
};