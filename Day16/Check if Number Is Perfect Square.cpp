// Given an integer n, return whether n = k * k for some integer k.

// This should be done without using built-in square root function.

/////////////////////////////////////////////////////////////////////////

bool solve(int n) {
    if (n <= 1) return true;
    int l = 1;
    int r = n / 2;

    while (l <= r) {
        long long m = l + (r - l) / 2;
        if (m * m == n) return true;
        if (m * m < n)
            l = m + 1;
        else {
            r = m - 1;
        }
    }
    return false;
}
