class Solution {
public:
typedef long long ll;
int n;
int mod = 1e9+7;
vector<ll> sqsumst;
vector<ll> sumst;
vector<ll> lazy;

    void lazyadd(int i, int l, int r, int val){
        int len = (r-l+1);

        sqsumst[i] += 2*val*sumst[i] + len*val*val;
        sumst[i] += (len* val);
    }

    void updaterange(int s, int e, int i, int l, int r, int val){
        if(lazy[i] !=0){
            lazyadd(i,l,r,lazy[i]);
            if(l!=r){
                lazy[2*i+1]+=lazy[i];
                lazy[2*i+2] += lazy[i];
            }
            lazy[i]=0;
        }

        // out of range
        if(l>e || r<s || l>r){
            return;
        }
        // completely in range
        if(l >=s && r <=e){
            lazyadd(i,l,r,val);
            if(l!=r){
                lazy[2*i+1]+=val;
                lazy[2*i+2] += val;
            }
            return;
        }

        int mid = l + (r-l)/2;
        updaterange(s,e,2*i+1,l,mid,val);
        updaterange(s,e,2*i+2, mid+1,r,val);

        sumst[i] = sumst[2*i+1] + sumst[2*i+2];
        sqsumst[i] = sqsumst[2*i+1] + sqsumst[2*i+2];
    }
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        sqsumst.assign(4*n,0);
        sumst.assign(4*n,0);
        lazy.assign(4*n,0);

        vector<int> lastseen(100001,-1);
        ll result = 0;

        for(int i = 0; i<n; i++){
            int s = lastseen[nums[i]]+1;
            int e = i;

            updaterange(s,e,0,0,n-1,1);

            result = (result + sqsumst[0])%mod;
            lastseen[nums[i]] = i;
        }
        return result%mod;
    }
};