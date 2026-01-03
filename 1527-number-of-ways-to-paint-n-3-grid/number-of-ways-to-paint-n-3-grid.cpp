class Solution {
    int mod = 1e9+7;
    vector<vector<int>> t;
    string states[12] = {"RYG","RGY","RYR","RGR","YRG","YGR","YGY","YRY","GRY","GYR","GRG","GYG"};

    int solve(int rem, int lastidx){
        if(rem == 0)return 1;

        if(t[rem][lastidx] != -1)return t[rem][lastidx];

        int result = 0;

        for(int i = 0; i<12; i++){
            if(i == lastidx)continue;
            bool fault = false;
            for(int j = 0; j<3; j++){
                if(states[i][j] == states[lastidx][j]){
                    fault = true;
                    break;
                }
            }

            if(!fault){
                result = (result + solve(rem-1, i))%mod;
            }
        }
        return t[rem][lastidx] = result;
    }
public:
    int numOfWays(int n) {
        t.resize(n,vector<int>(12,-1));
        int result = 0;

        for(int i = 0; i<12; i++){
            result = (result + solve(n-1, i))%mod;
        }

        return result;
    }
};