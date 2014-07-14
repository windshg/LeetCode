// Single Number II

class Solution {
public:
    int singleNumber(int a[], int n) {
        int size = sizeof(int) * 8;
        int bit[size];
        memset(bit, 0, sizeof(bit));
        for(int i = 0; i < n; ++i) {
            int t = a[i];
            for(int j = size-1; j >= 0; --j) {
                if(t & 1 == 1) bit[j] ++;
                t >>= 1;
            }
        }
        int ret = 0;
        for(int i = 0; i < size; ++i) {
            ret <<= 1;
            if(bit[i] % 3 == 1) ret |= 1;
        }
        return ret;
    }
};