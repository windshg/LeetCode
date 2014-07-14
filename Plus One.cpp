class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 1, n = digits.size();
        for (int i = n - 1; i >= 0; --i) {
            int t = digits[i] + carry;
            digits[i] = t % 10;
            carry = t / 10;
        }
        if (carry) digits.insert(digits.begin(), carry);
        return digits;
    }
};