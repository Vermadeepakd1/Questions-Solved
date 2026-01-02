class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> a;
        for(int &i : nums){
            a[i]++;
            if(a[i]>1)return i;
        }
        return -1;
    }
};