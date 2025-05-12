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

        for(int i = 0; i < words.size(); i++){
            if(i!=0){
                temp += " ";
            }
            temp += words[words.size() - i -1];
        }
        return temp;
    }
};