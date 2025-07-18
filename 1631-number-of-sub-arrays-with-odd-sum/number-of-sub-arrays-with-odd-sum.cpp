class Solution {
int mod = 1e9+7;    
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd = 0, even = 1; // even = 1 for prefix sum 0
        int prefix = 0, result = 0;
        
        for(int num : arr){
            prefix += num;
            if(prefix % 2 == 0){
                result = (result + odd) % mod;
                even++;
            } else {
                result = (result + even) % mod;
                odd++;
            }
        }
        return result;
    }
};