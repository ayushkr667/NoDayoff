//Given a sorted list of integers nums0, and another sorted list nums1, 
//find the median of the list that's obtained if nums0 and nums1 were merged.

//Median of a list of size n is defined to be list[floor(n / 2)].

////////////////////////////////////////////////////////////////////////////////

int solve(vector<int>& nums0, vector<int>& nums1) {

    vector<int> res;
    for(int i=0; i<nums0.size(); i++){
        res.push_back(nums0[i]);
    }
    for(int j=0; j<nums1.size(); j++){
        res.push_back(nums1[j]);
    }
    sort(res.begin(), res.end());
    int n = res.size();
    if(n%2 != 0){
        return res[n/2];
    }
    return (res[n/2]);
    
    // int x = nums0.size();
    // int y = nums1.size();

    // //assumed size of num1 > num0
    // if( x > y ) return solve(nums1, nums0);

    // int low = 0;
    // int high = x; //maximum median

    // while(low < high){
    //     int px = (low+high)/2;
    //     int py = (x+y+1)/2 - px;

    //     int maxLeftX = (px==0) ? INT_MIN : nums0[px-1];
    //     int minRightX = (px==x) ? INT_MAX : nums0[px];

    //     int maxLeftY = (py==0) ? INT_MIN : nums1[py-1];
    //     int minRightY = (py==y) ? INT_MAX : nums1[py];

    //     if(maxLeftX <= minRightY && maxLeftY <= minRightX){
    //         if((x+y)%2 == 0){
    //             return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY))/2;
    //         }
    //         else 
    //         {
    //             return max(maxLeftX, maxLeftY);
    //         }
    //     }
    //     else if (maxLeftX > minRightY) 
    //     { //we are too far on right side for partitionX. Go on left side.
    //         high = px - 1;
    //     } 
    //     else 
    //     { //we are too far on left side for partitionX. Go on right side.
    //         low = px + 1;
    //     }
    // }
    // return 0;
}
