class Solution {
public:

    struct Node{
        int pre = 0;
        int suf = 0;
        int maxlen = 0;
        char leftchar = 0;
        char rightchar = 0;
    };

    int n;
    vector<Node> st;

    Node merge(const Node& l, const Node& r, int leftlen, int rightlen){
        Node res;

        res.leftchar = l.leftchar;
        res.rightchar = r.rightchar;

        res.pre = l.pre;
        res.suf = r.suf;

        if(l.pre == leftlen && l.rightchar == r.leftchar){
            res.pre = l.pre + r.pre;
        }
        if(r.suf == rightlen && l.rightchar == r.leftchar){
            res.suf = r.suf + l.suf;
        }

        res.maxlen = max(l.maxlen, r.maxlen);
        if(l.rightchar == r.leftchar){
            res.maxlen = max(res.maxlen, l.suf + r.pre);
        }

        return res;
    }

    void buildst(int i, int l, int r, string &s){
        if(l==r){
            st[i]= {1,1,1,s[l],s[l]};
            return;
        }

        int mid = l+(r-l)/2;
        buildst(2*i+1, l,mid,s);
        buildst(2*i+2, mid+1,r,s);
        st[i] = merge(st[2*i+1], st[2*i+2], mid-l+1,r-mid);
    }

    void update(int i, int l, int r, int pos, char ch){
        if(l==r){
            st[i] = {1,1,1,ch,ch};
            return;
        }
        int mid = l+(r-l)/2;
        if(pos <= mid){
            update(2*i+1, l, mid, pos,ch);
        }else {
            update(2*i+2, mid+1, r, pos,ch);
        }
        st[i] = merge(st[2*i+1], st[2*i+2], mid-l+1,r-mid);
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        n = s.size();
        st.assign(4*n, Node());

        buildst(0,0,n-1,s);

        int k = queryIndices.size();

        vector<int>result(k);
        for(int i = 0; i<k; i++){
            int pos = queryIndices[i];
            char ch = queryCharacters[i];
            update(0,0,n-1,pos,ch);

            result[i]=st[0].maxlen;
        }
        return result;
    }
};