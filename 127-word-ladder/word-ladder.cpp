class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> visited;
        unordered_set<string> validwords(wordList.begin(),wordList.end());

        if(validwords.count(endWord)==0)return 0;

        queue<pair<string,int>> q; //currstring, steps
        q.push({beginWord,1});
        int n = beginWord.length();
        visited.insert(beginWord);

        while(!q.empty()){
            auto [curr, step] = q.front();
            q.pop();

            if(curr == endWord)return step;

            for(int i = 0; i<n; i++){
                char ch = curr[i];
                for(char nch = 'a'; nch <='z'; nch++){
                    if(ch == nch)continue;
                    curr[i] = nch;
                    if(validwords.count(curr) && !visited.count(curr)){
                        q.push({curr,step+1});
                        visited.insert(curr);
                    }
                    curr[i] = ch;
                }
            }
        }
        return 0;
    }
};