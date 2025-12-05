class Solution {
    int t[501][501];
    int solve(string &word1, string &word2, int i, int j){
        if(i == word1.length()){
            return word2.length() - j;
        }
        if(j == word2.length()){
            return word1.length() - i;
        }

        if(t[i][j]!=-1)return t[i][j];

        if(word1[i] == word2[j]){
            return t[i][j] = solve(word1,word2,i+1,j+1);
        }else{
            int ins = 1+solve(word1,word2,i,j+1);
            int del = 1+solve(word1,word2,i+1,j);
            int rep = 1+solve(word1,word2,i+1,j+1);
            return t[i][j]= min({ins,del,rep});
        }
        return 0;
    }
public:
    int minDistance(string word1, string word2) {
        memset(t,-1,sizeof(t));
        return solve(word1,word2,0,0);
    }
};