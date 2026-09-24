class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int> p;
        p.push_back(a[0]);
        for(int i=0;i<n;i++){
            if(a[i]==p.back())continue;
            else if(a[i]>p.back()) p.push_back(a[i]);
            else{
                int lo = 0;
                int hi = p.size()-1;
                while(lo<=hi){
                    int mid = lo + (hi-lo)/2;
                    if(p[mid]<a[i])lo=mid+1;
                    else hi=mid-1;
                }
                p[lo]=a[i];
            }
        }
        return p.size();
    }
};