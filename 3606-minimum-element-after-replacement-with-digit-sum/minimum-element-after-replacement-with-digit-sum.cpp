class Solution {
    int digitsum(int n){
        int sum = 0;
        while(n!=0){
            sum += (n%10);
            n/=10;
        }
        return sum;
    }
public:
    int minElement(vector<int>& nums) {
        int result = INT_MAX;
        for(int i : nums){
            result = min(result,digitsum(i));
        }
        return result;
    }
};