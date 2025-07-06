class FindSumPairs {
public:
    vector<int> num1,num2;
    unordered_map<int,int> f1,f2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        num1 = nums1;
        num2 = nums2;
        for(int n : num1){
            f1[n]++;
        }
        for(int n : num2){
            f2[n]++;
        }
    }
    
    void add(int index, int val) {
        int x = num2[index];
        f2[x]--;
        if(f2[x] == 0){
            f2.erase(x);
        }
        num2[index] += val;
        f2[num2[index]]++;
    }
    
    int count(int tot) {
        int cnt = 0;
        for(auto &[x,v]: f1){
            if(x < tot && f2[tot-x] > 0){
                cnt += (v*f2[tot-x]);
            }
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */