// Given a list of integers nums and an integer k, 
// return the length of the longest subsequence where the absolute 
// difference between every adjacent element is at most k.

////////////////////////////////////////////////////////////////////

int solve(vector<int>& nums, int k) {
    int n = nums.size();
    int dp[n];

    for(int i=0; i<n; i++) dp[i] = 1;

    for(int i=0; i<n; i++){
        for(int j = 0; j<i; j++){
            if(abs(nums[i] - nums[j]) <= k){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int res = dp[0];
    for(int num:dp) res = max(res, num);
    return res;
}
