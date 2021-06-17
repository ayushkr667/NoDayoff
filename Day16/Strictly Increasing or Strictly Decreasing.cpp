Given a list of integers nums, return whether the list is strictly increasing or strictly decreasing.
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  bool solve(vector<int>& nums) {
    int flag = 1, flag1 = 1;
    for(int i=1; i<nums.size(); i++){
        if(nums[i-1] >= nums[i])
        {
            flag = 0;
        }
        if(nums[i-1] <= nums[i])
            flag1 = 0;
    }
    
    if( flag || flag1)
        return true;
    return false; 
}
  
  
