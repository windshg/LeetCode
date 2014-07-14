// Stupid Method O(n * log(n))
class Solution {

public:

    void sortColors(int a[], int n) {
        qsort(a, 0, n-1);
    }
    
private:

    void _qsort(int a[], int l, int h) {
        if (l < h) {
            int m = _partition(a, l, h);
            _qsort(a, l, m-1);
            _qsort(a, m+1, h);
        }
    }
    
    int _partition(int a[], int l, int h) {
        int pvt = a[l];
        while (l < h) {
            while (l < h && a[h] >= pvt) --h;
            a[l] = a[h];
            while (l < h && a[l] <= pvt) ++l;
            a[h] = a[l];
        }
        a[l] = pvt;
        return l;
    }
    
};


// Smarter version, O(n), constant space;
class Solution {
public:
    void sortColors(int a[], int n) {
        int mp[3] = {0};
        for (int i = 0; i < n; ++i) mp[a[i]] ++;
        int idx = 0;
        for (int i = 0; i <= 2; ++i) {
            while (mp[i]--) a[idx++] = i;
        }
    }
};

// Much smarter version, O(n), inplace;
class Solution {
public:
    void sortColors(int a[], int n) {
        int zero = -1, two = n;
        int i = 0;
        while (i < two) {
            if (a[i] == 0) swap(a[i++], a[++zero]);
            else if (a[i] == 2) swap(a[i], a[--two]);
            else i++;
        }
    }
};
