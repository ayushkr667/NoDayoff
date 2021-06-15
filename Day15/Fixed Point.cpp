// Given a list of unique integers nums sorted in ascending order, 
// return the minimum i such that nums[i] == i. If there's no solution, return -1.

// This should be done in log(n) time.

///////////////////////////////////////////////////////////////////////////////////////
int solve(vector<int>& nums) {
    if( !nums.size() )
        return -1;
    if(nums[0] == 0)
        return 0;
    int l =0; 
    int r = nums.size();
    int res_index = -1;
    while(l < r){
        int mid = (l+r) /2;
        if( nums[mid] == mid ){
            res_index = mid;
            r = mid;
        }
        else if(nums[mid] > mid){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    return res_index;
}
