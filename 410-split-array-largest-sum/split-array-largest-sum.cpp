class Solution {
    bool isvalid(vector<int>& nums, int k, int maxsum){
        int parts = 1;
        int currsum = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(currsum + nums[i] > maxsum){
                currsum = 0;
                i--;
                parts++;
            }else{
                currsum += nums[i];
            }
            // if(i==n-1)parts++;

            // cout << currsum << " " << parts << " "<< maxsum  <<endl;

            if(parts > k)return false;
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        int sum = accumulate(nums.begin(),nums.end(),0);
        int s = 0, e = sum;

        int ans = e;
        while(s <= e){
            int mid = s+(e-s)/2;
            if(isvalid(nums,k,mid)){
                ans = mid;
                e= mid-1;
            }else s = mid+1;
        }
        return ans;
    }
};