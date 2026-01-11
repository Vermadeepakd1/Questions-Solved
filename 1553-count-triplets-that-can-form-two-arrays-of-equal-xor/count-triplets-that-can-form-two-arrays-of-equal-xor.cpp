class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        mp[0] = 1;
        int x = 0;
        int result = 0;
        for(int i = 0;  i<n; i++){
            x = arr[i];
            int temp = 0;
            for(int j = i+1; j<n; j++){
                x ^= arr[j];
                if(x == 0)result += j-i;
            }
            
        }
        return result;
    }
};