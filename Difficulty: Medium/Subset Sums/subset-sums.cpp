class Solution {
    void findsum(int idx, vector<int> &arr, vector<int>&result, int currsum, int n){
        if(idx == n){
            result.push_back(currsum);
            return;
        }
        //exclude
        findsum(idx+1, arr, result, currsum, n);
        //include
        findsum(idx+1, arr, result, currsum + arr[idx], n);
    }
  public:
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> result;
        int currsum = 0;
        findsum(0, arr,result,currsum,n);
        return result;
    }
};