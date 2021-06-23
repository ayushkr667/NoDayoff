// You are given a list of integers nums. Return the minimum positive value 
//we can append to the beginning of nums such that prefix 
//sums of the resulting list contains numbers that are all greater than 0.

// Constraints

// n ≤ 100,000 where n is the length of nums
//
// Input
// nums = [2, -5, 3, 2]

// Output
// 4

// Explanation
// If we have append 4 to the list then we have [4, 2, -5, 3, 2].

// The prefix sums are then [4, 6, 1, 4, 6], all of which are > 0.

///////////////////////////////////////////////////////////////////////////////////////////

int solve(vector<int>& nums) {
    if(!nums.size())
        return 1;
    int res = INT_MAX;
    int sum  = 0;
    for(int num:nums){
        sum += num;
        res = min(res, sum);
    }
    
    if(res > 0)
        return 1;

    return abs(res) + 1;
}
