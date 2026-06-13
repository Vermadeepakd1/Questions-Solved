class Solution {
public:
    int findweight(string &w, vector<int>& weights){
        int wt = 0;
        for(char &ch : w){
            wt = (wt + weights[ch-'a'])%26;
        }
        return wt%26;
    }

    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(string w : words){
            int wt = findweight(w,weights);
            ans +=  'a'+ 26-wt-1;
        }
        return ans;
    }
};