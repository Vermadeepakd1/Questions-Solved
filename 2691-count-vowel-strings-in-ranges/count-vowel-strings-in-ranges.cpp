class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        
        
        vector<int> prefix(n + 1, 0); 
        for (int i = 0; i < n; i++) {
            if (vowels.count(words[i][0]) && vowels.count(words[i].back())) {
                prefix[i + 1] = prefix[i] + 1;
            } else {
                prefix[i + 1] = prefix[i];
            }
        }

        vector<int> result;
        for (auto &q : queries) {
            result.push_back(prefix[q[1] + 1] - prefix[q[0]]);
        }

        return result;
    }
};
