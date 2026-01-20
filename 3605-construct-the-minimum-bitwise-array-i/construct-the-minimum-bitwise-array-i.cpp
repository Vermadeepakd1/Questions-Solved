class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for(int &i : nums){
            if(i == 2)ans.push_back(-1);
            else {
                int p = 0;
                int mask = 1;
                while((i & mask) != 0){
                    p++;
                    mask = (mask << 1);
                }
                mask = (1<< (p-1));
                int num = (i ^ mask);
                ans.push_back(num);
            }
        }

        return ans;
    }
};