// First Missing Positive 

class Solution {
public:
    int firstMissingPositive(int a[], int n) {
        if(n < 0) return 1;
        for(int i = 0; i < n; ++i) {
            if(a[i] > 0 && a[i] <= n && a[i] != i+1 && a[a[i]-1] != a[i]) {
                swap(a[a[i] - 1], a[i]);
                --i;
            }
        }
        for(int i = 0; i < n; ++i) if(a[i] != i+1) return i+1;
        return n+1;
    }
};