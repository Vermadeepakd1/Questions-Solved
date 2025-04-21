class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long x = 1;
        long long mini = 1, maxi = 1;
        for(auto diff:differences){
            x+=diff;
            mini = min(mini,x);
            maxi = max(maxi,x);
        }
        int result = (upper - lower +1) - (maxi - mini);
        if(result < 0){
            return 0;
        }
        return result;
    }
};