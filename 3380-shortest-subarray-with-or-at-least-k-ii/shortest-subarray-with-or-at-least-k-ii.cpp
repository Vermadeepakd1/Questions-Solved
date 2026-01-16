class Solution {
    void addnew(int num, vector<int> &bitcount){
        int i = 0;
        while(num != 0){
            if((num & 1) != 0) bitcount[i]++;
            num >>= 1;
            i++;
        }

    }

    void removenum(int num, vector<int> &bitcount){
        int i = 0;
        while(num != 0){
            if((num & 1) != 0) bitcount[i]--;
            num >>= 1;
            i++;
        }
    }

    int getnum(vector<int> &bitcount){
        int num = 0;
        for(int i = 0; i<32; i++){
            if(bitcount[i] >0){
                num |= (1<<i);
            }
        }
        return num;
    }
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> bitcount(32,0);
        int n = nums.size();
        int result  = INT_MAX;

        int i = 0, j = 0;

        while(j < n){
            addnew(nums[j], bitcount);

            while(i <= j && getnum(bitcount) >= k){
                result = min(result, j-i+1);
                removenum(nums[i],bitcount);
                i++;
            }
            j++;
        }

        return result == INT_MAX ? -1 : result;
    }
};