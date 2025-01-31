class Solution
{
    public:
        string get(int n, int i)
        {
            string temp = "";
            int rem;
            while (n != 0)
            {
                rem = n % i;
                temp = to_string(rem) + temp;
                n /= i;
            }
            return temp;
        }
    bool ispal(string s)
    {
        return s == string(s.rbegin(), s.rend());
    }
    bool isStrictlyPalindromic(int n)
    {
        bool flag = true;
        for (int i = 2; i <= n - 2; i++)
        {
            string s = get(n, i);
            if (!ispal(s))
            {

                flag = false;
                break;
            }
        }
        if (flag)
            return true;
        return false;
    }
};