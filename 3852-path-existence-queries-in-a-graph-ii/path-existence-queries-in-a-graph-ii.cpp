class Solution {
    // binary lifting
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> newarr;
        for(int i = 0; i < n; i++){
            newarr.push_back({nums[i], i});
        }

        sort(newarr.begin(), newarr.end());

        vector<int> pos(n);
        for(int i = 0; i < n; i++){
            pos[newarr[i].second] = i;
        }

        int log = 1;
        while((1 << log) < n){
            log++;
        }

        vector<vector<int>> up(n, vector<int>(log)); 
        int r = 0;
        for(int l = 0; l < n; l++){
            if(r < l) r = l;
            while((r + 1 < n) && newarr[r + 1].first - newarr[l].first <= maxDiff) r++;
            up[l][0] = r;
        }

        for(int j = 1; j < log; j++){
            for(int i = 0; i < n; i++){
                up[i][j] = up[up[i][j-1]][j-1];
            }
        }

        vector<int> result;
        for(auto &q : queries) {
            int src_pos = pos[q[0]];
            int dest_pos = pos[q[1]];
            
            if(src_pos > dest_pos) swap(src_pos, dest_pos);
            
            if(src_pos == dest_pos){
                result.push_back(0);
                continue;
            }

            int curr = src_pos;
            int jumps = 0;
            for(int j = log - 1; j >= 0; j--){
                if(up[curr][j] < dest_pos){
                    curr = up[curr][j];
                    jumps += (1 << j);
                }
            }

            if(up[curr][0] >= dest_pos){
                result.push_back(jumps + 1);
            } else {
                result.push_back(-1);
            }
        }
        return result;
    }
};
