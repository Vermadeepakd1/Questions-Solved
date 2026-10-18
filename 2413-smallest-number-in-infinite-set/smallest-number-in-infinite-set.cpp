class SmallestInfiniteSet {
public:
    vector<bool> st;
    int sm;
    SmallestInfiniteSet() {
        st.assign(1001, true);
        st[0] = false;
        sm = 1;
    }

    int popSmallest() {
        int x = sm;
        st[sm] = false;
        while (st[sm] != true)
            sm++;
        return x;
    }

    void addBack(int num) {
        st[num] = true;
        if (sm > num)
            sm = num;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */