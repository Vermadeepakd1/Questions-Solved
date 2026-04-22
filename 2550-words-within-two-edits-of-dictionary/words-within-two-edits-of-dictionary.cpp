class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
        for(string word : queries){
            for(string word2 : dictionary){
                int diffs = 0;
                for(int i = 0; i < word.length(); i++){
                    if(word[i] != word2[i]) diffs++;
                }
                
                if(diffs <= 2){
                    result.push_back(word);
                    break;
                }
            }
        }
        return result;
    }
};