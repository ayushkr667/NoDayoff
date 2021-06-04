// Given a list of integers nums, which contains either -1 or 1, 
// return the length of the longest sublist that sums to 0.
  
// Input
// nums = [1, 1, 1, 1, -1, -1, 1, -1]

// Output
// 6

// Explanation
// The longest sublist that sums to 0 is [1, 1, -1, -1, 1, -1] which has length 6.

//////////////////////////////////////////////////////////////////////////////////////

int solve(vector<int>& nums) {
    int n = nums.size(), sum = 0;
    unordered_map<int, int> mp;
    int length = -1;
    for(int i=0; i<n; i++){
        sum += nums[i];
        if(sum == 0){
            length = max(length, i+1);
        }
        if(mp.find(sum) == mp.end()){
            mp[sum] = i;
        }
        else{
            length = max(length, i - mp[sum]);
        }
    }
    return length;
} 
