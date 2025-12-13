class Solution {
    int n;
    vector<vector<int>> t;
    int child1(vector<vector<int>>& fruits){
        int ans = 0;
        for(int i = 0; i<n; i++){
            ans += fruits[i][i];
        }
        return ans;
    }

    int child2(int i, int j, vector<vector<int>>& fruits){
        if(i >= n || j<0 || j>=n)return 0;

        if(i==n-1 && j== n-1)return 0;

        if(i >=j)return 0;

        if(t[i][j] != -1)return t[i][j];

        int down = fruits[i][j] + child2(i+1,j,fruits);
        int right = fruits[i][j] + child2(i+1,j+1,fruits);
        int left = fruits[i][j] + child2(i+1,j-1,fruits);

        return t[i][j] = max(down,max(left,right));

    }

    int child3(int i, int j, vector<vector<int>>& fruits){
        if(i >= n || j<0 || i< 0)return 0;

        if(i==n-1 && j== n-1)return 0;

        if(i <= j)return 0;

        if(t[i][j] != -1)return t[i][j];

        int up = fruits[i][j] + child3(i-1,j+1,fruits);
        int right = fruits[i][j] + child3(i,j+1,fruits);
        int down = fruits[i][j] + child3(i+1,j+1,fruits);

        return t[i][j] = max(down,max(up,right));
    }
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();
        t.resize(n,vector<int>(n,-1));
        int c1 = child1(fruits);
        int c2 = child2(0,n-1,fruits);
        int c3 = child3(n-1,0,fruits);

        return c1+c2+c3;
    }
};