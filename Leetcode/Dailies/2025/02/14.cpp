// Problem: 1352. Product of the Last K Numbers (Medium)
// Link: https://leetcode.com/problems/product-of-the-last-k-numbers

class ProductOfNumbers {
public:
    int n;
    vector<int> nums;
    ProductOfNumbers() {
        nums = {1};
        n = 1;
    }
    
    void add(int num) {
        if (num == 0) {
            nums = {1};
            n = 0;
        } else nums.push_back(nums.back() * num);
        n++;
    }
    
    int getProduct(int k) {
        return k >= n ? 0: nums[n-1]/nums[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */