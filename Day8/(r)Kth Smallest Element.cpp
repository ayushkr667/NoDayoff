// Given a list of unsorted integers nums, and an integer k, 
// return the kth (0-indexed) smallest element in the list.

// This should be done in O(n) time on average.



// Intuition:
// Make a partition, and we get an index m. We are sure everything before m is smaller than nums[m]
// If m equals k, we are done
// If m is greater than k, we need to do partition to the range [l, m - 1]
// If m is smaller than k, we need to do partition to the range [m+1, r]
// Keep doing it until we find the answer.

// Time Complexity
// O(n)

////////////////////////////////////////////////////////////////////////////////////////////////////////

//brutforce

// int solve(vector<int>& nums, int k) {
//     sort(nums.begin(), nums.end());
//     return nums[k];
// }

int partition(vector<int>& nums, int start, int end) {
    int pivot = nums[start], j = end;
    for (int i = start + 1; i <= j;) {
        if (nums[i] >= pivot)
            swap(nums[i], nums[j--]);
        else
            i++;
    }
    swap(nums[start], nums[j]);
    return j;
}

int solve(vector<int>& nums, int k) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int m = partition(nums, l, r);
        if (m == k)
            return nums[m];
        else if (m < k)
            l = m + 1;
        else
            r = m - 1;
    }
    return nums[l];
}
