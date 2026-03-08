class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";
        int n = nums.size();
        for(int i =0; i<n;i++){
            int ones = 0, zeros = 0;
            for(int j=0; j<n; j++){
                if(nums[j].substr(0,i) == ans){
                    if(nums[j][i] == '0')zeros++;
                    else ones++;
                }
            }
            if(ones>zeros)ans+='0';
            else ans+='1';
        }
        return ans;
    }
};