class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int acur = m - 1, bcur = n - 1;
        int cur = m + n - 1;
        while (acur >= 0 && bcur >= 0) {
            if (A[acur] > B[bcur]) {
                A[cur--] = A[acur--];
            } else {
                A[cur--] = B[bcur--];
            }
        }
        while (acur >= 0) A[cur--] = A[acur--];
        while (bcur >= 0) A[cur--] = B[bcur--];
    }
};