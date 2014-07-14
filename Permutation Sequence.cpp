// Time: O((n-1)!), fast enough to get accepted, but not even enough to hit the best solution.
class Solution {
public:
    string getPermutation(int n, int k) {
        if (n == 1) return "1";
        int f = factorial(n - 1);
        int pfx = k / f, sno = k % f;
        if (sno == 0) {-- pfx; sno = f;}
        string s(n, '0');
        for (int i = 0; i < n; ++i) s[i] += i + 1;
        swap(s[pfx], s[0]);
        sort(s.begin() + 1, s.end());
        while (-- sno > 0) next_permutation(s.begin(), s.end());
        return s;
    }
    
    int factorial(int n) {
        if (n <= 1) return 1;
        return n * factorial(n - 1);
    }
};

// Time: O(n^2), as there is an erase process at cost of O(n) time during each iteration of the outter loop at cost of O(n) time. 
// ...
class Solution {
public:
    string getPermutation(int n, int k) {
        if (n == 1) return "1";
        int f = 1;
        string a(n, '0');
        for (int i = 0; i < n; ++i) {
            a[i] += i + 1;
            f *= i + 1;
        }
        string s(n, '0');
        int i = 0;
        while (n) {
            f /= n;
            int pfx = k / f;
            k %= f;
            if (k == 0) {-- pfx; k = f;}
            s[i++] = a[pfx];
            a.erase(pfx, 1);
            -- n;
        }
        return s;
    }
};

//