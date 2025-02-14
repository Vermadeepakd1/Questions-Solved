class ProductOfNumbers {
public:
    vector<int> prefixProduct;
    ProductOfNumbers() { prefixProduct.push_back(1); }

    void add(int num) {
        if (num == 0) {
            prefixProduct.clear();
            prefixProduct.push_back(1); // Reset due to zero
        } else {
            prefixProduct.push_back(prefixProduct.back() * num);
        }
    }

    int getProduct(int k) {
        int n = prefixProduct.size();
        if (k >= n)
            return 0; // If k exceeds stored products, a zero must be present.
        return prefixProduct[n - 1] / prefixProduct[n - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */