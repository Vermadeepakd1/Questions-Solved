class Solution {
    bool  isVowel(char &c){
        string vowels = "aeiouAEIOU";
        return (vowels.find(c) != string::npos);
    }
public:
    bool isValid(string word) {
        if(word.length() >= 3){
            int v = 0, cs = 0;
            for(char &c : word){
                if(!isalnum(c)) return false;
                if(isalpha(c)){
                    if(isVowel(c)) v++;
                    else cs++;
                }
            }
            if(!(v > 0 && cs > 0)) return false;
            return true;
        }
        return false;
    }
};