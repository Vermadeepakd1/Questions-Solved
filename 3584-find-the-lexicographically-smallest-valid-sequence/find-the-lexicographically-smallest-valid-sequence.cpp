class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length(), m = word2.length();

        vector<int> suffixmatch(n + 1, 0); 
        int j = m - 1;
        int matched = 0;

        for(int i = n - 1; i >= 0; i--) {
            if(j >= 0 && word1[i] == word2[j]) { 
                matched++;
                j--;
            }
            suffixmatch[i] = matched;
        }

        bool used = false;
        j = 0;
        vector<int> result;

        for(int i = 0; i < n; i++) {
            if(word1[i] == word2[j]) {
                result.push_back(i);
                j++;
            } 
            else if(!used && suffixmatch[i + 1] >= m - j - 1) { 
                used = true;
                result.push_back(i);
                j++;
            }
            
            if(j == m) return result;
        }

        return {};
    }
};