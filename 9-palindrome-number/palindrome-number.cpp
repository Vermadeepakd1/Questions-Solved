class Solution
{
    public:
        bool isPalindrome(int x)
        {
            if (x < 0) return false;
            int n = x, rem = 0;
            double inv = 0;
            while (n != 0)
            {
                rem = n % 10;
                inv = inv *10 + rem;
                n = n / 10;
            }
            return x == inv;
        }
};