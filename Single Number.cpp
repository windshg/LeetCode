// Single Number

// O(n * log(n)) solution
class Solution {
public:
    int singleNumber(int a[], int n) {
        sort(a, a+n);
        int i = 1;
        while(a[i] == a[i-1] && i < n) i += 2;
        return a[i-1];
    }
};

// O(n) solution, with extra O(1) space
class Solution {
public:
    int singleNumber(int a[], int n) {
        int buf = 0;
        for(int i = 0; i < n; ++i) buf ^= a[i];
        return buf;
    }
};

// O(n) solution, with no extra space
class Solution {
public:
    int singleNumber(int a[], int n) {
        for(int i = 1; i < n; ++i) a[0] ^= a[i];
        return a[0];
    }
};