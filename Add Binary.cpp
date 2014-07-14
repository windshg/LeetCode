// Add Binary

class Solution {
public:
    string addBinary(string a, string b) {
        int del = a.size() > b.size() ? a.size() - b.size() : b.size() - a.size();
        string fill(del, '0');
        if(a.size() < b.size()) a = fill + a;
        else  b = fill + b;
        string ret = "";
        int carry = 0;
        for(int i = a.size()-1; i >= 0; --i) {
            int x = (a[i] - '0') + (b[i] - '0') + carry;
            ret = (char)(x % 2 + '0') + ret;
            carry = x / 2;
        }
        while(carry > 0) {
            ret = (char)(carry % 2 + '0') + ret;
            carry /= 2;
        }
        return ret;
    }
};

// For scale-univesal summation of string numbers

class Solution {
public:
    string addBinary(string a, string b) {
        return addNumber(a, b, 2);
    }
    
    string addNumber(string a, string b, int scale) {
        if (a.size() < b.size()) return addNumber(b, a, scale);
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        while (i >= 0 && j >= 0) {
            int sum = a[i] - '0' + b[j] - '0' + carry;
            a[i] = sum % scale + '0';
            carry = sum / scale;
            -- i; -- j;
        }
        if (carry == 0) return a;
        while (i >= 0) {
            int sum = a[i] - '0' + carry;
            a[i] = sum % scale + '0';
            carry = sum / scale;
            -- i;
        }
        while (carry) {
            a = string(1, carry % scale + '0') + a;
            carry /= scale;
        }
        return a;
    }
};