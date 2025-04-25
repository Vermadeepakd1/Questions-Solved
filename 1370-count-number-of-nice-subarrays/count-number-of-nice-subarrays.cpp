class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> count;
        count[0] = 1;
        int odd = 0;
        int result = 0;
        for(int num : nums){
            if(num % 2 != 0){
                odd++;
            }
            if (count.find(odd - k) != count.end()) {
                result += count[odd - k];
            }
            count[odd]++;
        }
        return result;
    }
};