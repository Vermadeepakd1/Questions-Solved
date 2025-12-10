class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int result = 1;
        int mod = 1e9+7;
        int n = complexity.size();
        for(int i =1; i<n; i++){
            if(complexity[i] > complexity[0]){
                result = (1LL * result*i)%mod;
            }else return 0;
        }
        return result;
    }
};