// Given a list of positive integers nums, 
// return the largest positive integer that divides each of the integers.


///////////////////////////////////////////////////////////////////////////////

int solve(vector<int>& nums) {
    int ans = nums[0];
    for(int i=1; i<nums.size(); i++){
        ans = __gcd(ans, nums[i]);
    }
    return ans;
}
