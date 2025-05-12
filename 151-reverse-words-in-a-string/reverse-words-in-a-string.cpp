class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string temp = "";
        for(char c: s){
            if(c == ' '){
                if(!temp.empty()){
                    words.push_back(temp);
                    temp = "";
                }
            } else{
                temp += c;
            }
        }
        if(!temp.empty()){
            words.push_back(temp);
            temp = "";
        }
        int n = words.size();
        for(int i = 0; i < n; i++){
            if(i!=0){
                temp += " ";
            }
            temp += words[n - i -1];
        }
        return temp;
    }
};