class Solution
{
    public:
        int subtractProductAndSum(int n)
        {
            int prod = 1, sum = 0, rem = 0;
            while (n != 0)
            {
                rem = n % 10;
                sum += rem;
                prod *= rem;
                n /= 10;
            }
            return prod - sum;
        }
};