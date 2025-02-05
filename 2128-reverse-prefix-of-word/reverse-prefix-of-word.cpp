class Solution
{
    public:
        string reversePrefix(string word, char ch)
        {
            int ind = 0;
            for (int i = 0; i < word.length(); i++)
            {
                if (word[i] == ch)
                {
                    ind = i;
                    break;
                }
            }
            if (ind < word.length())
            {
                reverse(word.begin(), word.begin() + ind + 1);
            }
            return word;
        }
};