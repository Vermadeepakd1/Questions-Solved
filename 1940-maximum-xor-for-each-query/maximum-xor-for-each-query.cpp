class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int x = 0;
        vector<int> result;
        for(int &i : nums){
            x ^= i;

            int mask = (1<<maximumBit)-1;
            result.push_back(x^mask);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};