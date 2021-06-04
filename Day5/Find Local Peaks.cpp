// You are given a list of integers nums. Return the index of 
// every peak in the list, sorted in ascending order. 
// An index i is called a peak if

// nums[i] > nums[i + 1] if i = 0
// nums[i] > nums[i - 1] if i = n - 1
// nums[i - 1] < nums[i] > nums[i + 1] otherwise

///////////////////////////////////////////////////////////////////////////


vector<int> solve(vector<int>& nums) {
    vector<int> res;
    if(nums.size()<=1){
        return res;
    }
    for(int i=1; i<nums.size()-1; i++){
        if(nums[i] > nums[i-1] && nums[i] > nums[i+1]){
            res.push_back(i);
        }
    }
    if( nums.size() > 1){
        if(nums[0] > nums[1]){
            res.push_back(0);
        }
    }
    if( nums[nums.size()-1] > nums[nums.size()-2])
       res.push_back(nums.size()-1);

    sort(res.begin(), res.end());

    return res;
    
}

