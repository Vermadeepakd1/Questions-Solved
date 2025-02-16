class Solution {
public:
    string reverseWords(string s) {
        vector<string> result;
        string temp = "";

        for (char ch : s) {
            if (ch == ' ') {
                if (!temp.empty()) { 
                    result.push_back(temp);
                    temp = "";
                }
            } else {
                temp += ch;
            }
        }
        
        if (!temp.empty()) {
            result.push_back(temp);
        }

        // Reverse the words
        reverse(result.begin(), result.end());

        // Construct the final string
        string final = "";
        for (int i = 0; i < result.size(); i++) {
            final += result[i];
            if (i != result.size() - 1) { // Avoid extra space at the end
                final += " ";
            }
        }

        return final;
    }
};
