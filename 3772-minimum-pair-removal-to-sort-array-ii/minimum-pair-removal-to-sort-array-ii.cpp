class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        vector<long long> temp(n);

        for (int i = 0; i < n; i++)
            temp[i] = nums[i];

        set<pair<long long, int>> minPairs;

        vector<int> nextidx(n), previdx(n);

        for (int i = 0; i < n; i++) {
            nextidx[i] = i + 1;
            previdx[i] = i - 1;
        }

        int badpairs = 0;
        for (int i = 0; i < n-1; i++) {
            if (temp[i] > temp[i + 1])
                badpairs++;
            minPairs.insert({temp[i] + temp[i + 1], i});
        }

        int cnt = 0;

        while (badpairs > 0) {
            int first = minPairs.begin()->second;
            int second = nextidx[first];

            int firstleft = previdx[first];
            int secondright = nextidx[second];

            minPairs.erase(minPairs.begin());

            if (temp[first] > temp[second])
                badpairs--;

            if (firstleft >= 0) {
                if (temp[firstleft] > temp[first] &&
                    temp[firstleft] <= temp[first] + temp[second])
                    badpairs--;
                else if (temp[firstleft] <= temp[first] &&
                         temp[firstleft] > temp[first] + temp[second])
                    badpairs++;
            }

            if(secondright < n){
                if (temp[secondright] >= temp[second] &&
                    temp[secondright] < temp[first] + temp[second])
                    badpairs++;
                else if (temp[secondright] < temp[second] &&
                         temp[secondright] >= temp[first] + temp[second])
                    badpairs--;
            }

            if(firstleft >=0){
            minPairs.erase({temp[firstleft]+temp[first], firstleft});
            minPairs.insert({temp[firstleft]+temp[first]+temp[second], firstleft});}

            if(secondright < n){
                minPairs.erase({temp[second]+temp[secondright], second});
            minPairs.insert({temp[secondright]+temp[first]+temp[second], first});
            previdx[secondright] = first;
            }

            nextidx[first] = secondright;
            temp[first] += temp[second];

            cnt++;
        }

        return cnt;
    }
};