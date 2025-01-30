class Solution {
public:
    int calcsum(vector<int>& nums,int size,int index,int currsum){
        if(index == size){
            return currsum;
        }
        //exclude
        int exclude =calcsum(nums,size,index+1,currsum);
        // include
        int include =calcsum(nums,size,index+1,currsum ^ nums[index]);

        return exclude+include;
    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int result = calcsum(nums,n,0,0);
        return result;
    }
};