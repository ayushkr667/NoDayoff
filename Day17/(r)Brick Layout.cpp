// You are given a list of integers bricks and integers width and height. 
// Each bricks[i] represents a 1 x bricks[i] size brick. Return the number of 
// ways to lay the bricks such that we get full layout of bricks with width 
// width and height height. Bricks can be reused but can only be laid horizontally.

// Answer fits within 32-bit integer.

// Example 1
// Input
// bricks = [2, 3]
// width = 5
// height = 2

// Output
// 4

// Explanation
// We can lay the first row of bricks with [2, 3] or [3, 2] and 
// we can lay the second row of bricks with [2, 3] or [3, 2].

///////////////////////////////////////////////////////////////////////////////////////////

int solve(vector<int>& nums, int w, int h) {
    vector<int> dp(w + 1);
    dp[0] = 1;

    for (int i = 1; i <= w; ++i) {
        for (const auto& num : nums) {
            if (num <= i) dp[i] += dp[i - num];
        }
    }

    return pow(dp[w], h);
}
