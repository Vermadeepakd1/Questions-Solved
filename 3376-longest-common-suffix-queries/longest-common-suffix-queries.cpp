class Solution {
public:
    struct trieNode {
        int idx;
        trieNode* children[26];

        ~trieNode() {
            for (int i = 0; i < 26; i++) {
                if (children[i] != nullptr) {
                    delete children[i]; 
                }
            }
        }
    };

    trieNode* getNode(int i) {
        trieNode* temp = new trieNode();
        temp->idx = i;

        for (int i = 0; i < 26; i++) {
            temp->children[i] = NULL;
        }
        return temp;
    }

    void insertTrie(trieNode* root, int idx, vector<string>& wordsContainer) {
        string word = wordsContainer[idx];
        int n = word.length();

        for (int j = n - 1; j >= 0; j--) {
            int i = word[j] - 'a';

            if (root->children[i] == NULL) {
                root->children[i] = getNode(idx);
            }
            root = root->children[i];
            if (wordsContainer[root->idx].length() > n) {
                root->idx = idx;
            }
        }
    }

    int searchTrie(trieNode* root, string& word) {
        int ans = root->idx;
        int n = word.length();

        for (int i = n - 1; i >= 0; i--) {
            int ch_idx = word[i] - 'a';
            root = root->children[ch_idx];
            if (root == NULL) {
                return ans;
            }
            ans = root->idx;
        }
        return ans;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int m = wordsContainer.size(), n = wordsQuery.size();
        vector<int> result(n);

        trieNode* root = getNode(0);
        int min_idx = 0;
        for (int i = 1; i < m; i++) {
            if (wordsContainer[i].size() < wordsContainer[min_idx].size()) {
                min_idx = i;
            }
        }
        root->idx = min_idx;

        for (int i = 0; i < m; i++) {
            insertTrie(root, i, wordsContainer);
        }

        for (int i = 0; i < n; i++) {
            result[i] = searchTrie(root, wordsQuery[i]);
        }

        delete root; 

        return result;
    }
};