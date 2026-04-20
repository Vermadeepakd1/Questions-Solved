class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        vector<vector<int>> clr(101, vector<int>(2,-1));
        //min,max
        for(int i = 0; i<n; i++){
            int c = colors[i];
            if(clr[c][0] ==-1 || clr[c][0] > i){
                clr[c][0] = i;
            }
            if(clr[c][1] ==-1 || clr[c][1]<i) clr[c][1]=i;
        }

        int maxi = INT_MIN;
        for(int i = 0; i<101; i++){
            int l = clr[i][0],r = clr[i][1];
            if(l == -1)continue;
            for(int j = i+1; j<101; j++){
                if(clr[j][0] == -1)continue;
                maxi = max(maxi, abs(l-clr[j][0]));
                maxi = max(maxi, abs(l-clr[j][1]));
                maxi = max(maxi, abs(r-clr[j][1]));
                maxi = max(maxi, abs(r-clr[j][0]));
            }
        }
        return maxi;
    }
};