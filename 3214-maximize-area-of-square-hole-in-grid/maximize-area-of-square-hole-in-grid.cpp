class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
                               vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int contl = 1;
        int maxcontl = 1;
        for (int i = 1; i < hBars.size() ; i++) {
            if(hBars[i] == 1 || hBars[i] == n+2)continue;
            if (hBars[i] == hBars[i - 1] + 1)
                contl++;
            else
                contl = 1;

            maxcontl = max(maxcontl, contl);
        }
        contl = 1;
        int maxcontb = 1;
        for (int i = 1; i < vBars.size() ; i++) {
            if(vBars[i] == 1 || vBars[i] == m+2)continue;
            if (vBars[i] == (vBars[i - 1] + 1))
                contl++;
            else
                contl = 1;

            maxcontb = max(maxcontb, contl);
        }

        cout << maxcontl << " " << maxcontb << endl;

        int maxi = min(maxcontl, maxcontb);

        return (maxi + 1) * (maxi + 1);
    }
};