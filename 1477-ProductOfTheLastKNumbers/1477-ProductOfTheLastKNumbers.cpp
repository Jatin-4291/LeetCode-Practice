// Last updated: 8/30/2025, 1:25:29 PM
class ProductOfNumbers {
public:
    vector<int> temp;
    int ans = 1;

    ProductOfNumbers() {
        temp.clear();
        temp.push_back(1); // Base case to handle division
    }
    
    void add(int num) {
        if (num == 0) {
            temp.clear();
            temp.push_back(1);
            ans = 1; 
            return;
        }
        ans *= num;
        temp.push_back(ans);
    }
    
    int getProduct(int k) {
        if (k >= temp.size()) return 0; // If k exceeds available numbers
        return temp[temp.size() - 1] / temp[temp.size() - k - 1];
    }
};
