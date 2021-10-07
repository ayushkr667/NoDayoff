// You are given a list of integers nums. Return a new list of the 
// same length where the value at index i is set to the next 
// element greater than nums[i] to its right, 
// circling back to the front of the list if necessary. 
// If there's no number that's greater, then it should be set to -1.

// Input
// nums = [3, 4, 0, 2]
// Output
// [4, -1, 2, 3]


//////////////////////////////////////////////////////////////////////////

vector<int> solve(vector<int>& nums) {
    int n = nums.size();
    nums.insert(nums.end(), nums.begin(), nums.end());
    vector<int> ans(n, -1);
    stack<int> st;
    for (int i = 0; i < n * 2; ++i) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            if (st.top() < n) ans[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}


