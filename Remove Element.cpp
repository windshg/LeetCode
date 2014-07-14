class Solution {
public:
    int removeElement(int a[], int n, int elem) {
        int k = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] != elem) a[k++] = a[i];
        }
        return k;
    }
};