class Solution {
    string s;
    int n;
    
    // dp[curr][prevprev + 1][prev + 1][tight][leadingzeros]
    pair<long long, long long> dp[20][12][12][2][2];

    pair<long long, long long> solve(int curr, int prevprev, int prev, bool tight, bool leadingzeros) {
        if (curr == n) return {1, 0};

        if (dp[curr][prevprev + 1][prev + 1][tight][leadingzeros].first != -1) {
            return dp[curr][prevprev + 1][prev + 1][tight][leadingzeros];
        }

        long long totalnum = 0;
        long long wavescore = 0;

        int ub = tight ? (s[curr] - '0') : 9;

        for (int dig = 0; dig <= ub; dig++) {
            bool newleadingzeros = leadingzeros && (dig == 0);
            int newprevprev = prev;
            
            int newprev = newleadingzeros ? -1 : dig; 

            auto [remaintotalnum, remainwavescore] = solve(curr + 1, newprevprev, newprev, tight && (dig == ub), newleadingzeros);

            if (!newleadingzeros && prevprev >= 0 && prev >= 0) {
                bool ispeak = (prevprev < prev && prev > dig);
                bool isvalley = (prevprev > prev && prev < dig);

                if (ispeak || isvalley) {
                    wavescore += remaintotalnum;
                }
            }

            totalnum += remaintotalnum;
            wavescore += remainwavescore;
        }

        return dp[curr][prevprev + 1][prev + 1][tight][leadingzeros] = {totalnum, wavescore};
    }

    long long func(long long num) { 
        if (num < 100) return 0;

        s = to_string(num);
        n = s.length();

        for(int i = 0; i < 20; i++)
            for(int j = 0; j < 12; j++)
                for(int k = 0; k < 12; k++)
                    for(int t = 0; t < 2; t++)
                        for(int l = 0; l < 2; l++)
                            dp[i][j][k][t][l] = {-1, -1};

        auto [totalnum, wavescore] = solve(0, -1, -1, true, true);

        return wavescore;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return func(num2) - func(num1 - 1);
    }
};