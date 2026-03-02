class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>  zeros;
        for(auto &v : grid){
            int i = n-1;
            while(i >= 0 && v[i] == 0)i--;
            int cnt = n-1-i;
            zeros.push_back(cnt);
        }
        int cnt = 0;

        for(int i = 0; i<n; i++){
            int needed = n-i-1;
            if(zeros[i] < needed){
                int idx = -1;
                for(int j=i; j<n; j++){
                    if(zeros[j] >= needed){
                        idx = j;
                        break;
                    }
                }
                if(idx == -1)return -1;
                for(int j=idx; j>i; j--){
                    swap(zeros[j],zeros[j-1]);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};