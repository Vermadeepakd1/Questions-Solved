class Solution {
public:
    int digsum(int x){
        int sum = 0;
        while(x!=0){
            sum += (x%10);
            x/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> cp(nums);

        int n = nums.size();
        for(int i = 0; i<n; i++){
            mp[nums[i]]=i;
        }

        sort(cp.begin(),cp.end(),[&](int a, int b){
            int da = digsum(a), db = digsum(b);
            if(da == db)return a<b ;
            return da < db;
        });

        vector<int> parent(n,-1);

        for(int i = 0; i<n; i++){
            int x = cp[i];
            int org = mp[x];
            parent[org] = i;
        }

        int cycles = 0;

        vector<bool> visited(n,false);
        for(int i = 0; i<n; i++){
            if(visited[i])continue;

            int x = i;
            while(!visited[x]){
                visited[x] = true;
                x = parent[x];
            }
            cycles++;
        }
        return n-cycles;
    }
};