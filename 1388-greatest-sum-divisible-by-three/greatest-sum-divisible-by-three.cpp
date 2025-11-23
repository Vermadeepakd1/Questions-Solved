class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        sort(nums.begin(),nums.end());
        vector<int> ones,twos;
        for(int i : nums){
            sum += i;
            if(i%3 == 1)ones.push_back(i);
            else if(i%3 == 2)twos.push_back(i);
        }
int mini = INT_MAX;
        if(sum % 3 == 0)return sum;
        else if(sum % 3 == 1){
            
            if(ones.size() >= 1)mini = min(mini,ones[0]);
            if(twos.size() >= 2){
                mini = min(mini, twos[0] + twos[1]);
            }

        }else{
            if(ones.size() >= 2){
                mini = min(mini, ones[0] + ones[1]);
            }
            if(twos.size() >= 1)mini = min(twos[0],mini);
        }

        return sum - mini;
    }
};