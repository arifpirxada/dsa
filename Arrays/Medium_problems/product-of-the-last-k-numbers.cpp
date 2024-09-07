// https://leetcode.com/problems/product-of-the-last-k-numbers/

class ProductOfNumbers {
private:
    vector<int> pr = { 1 };
public:
    ProductOfNumbers() {}
    
    void add(int num) {
        if (num == 0) pr = { 1 };
        else pr.push_back(pr.back() * num);
    }
    
    int getProduct(int k) {
        if (k >= pr.size()) return 0;
        return (pr.back() / pr[pr.size() - k - 1]);
    }
};