class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    
    
    
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        int count = 0,maxcount = 0;
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        
        int a = 0, d = 0;
        
        int n = arr.size();
        while(a<n ){
            if(arr[a] <= dep[d]){
                a++;
                count++;
            }else{
                d++;
                count--;
            }
            maxcount = max(maxcount,count);
        }
        
        return maxcount;
    }
};
