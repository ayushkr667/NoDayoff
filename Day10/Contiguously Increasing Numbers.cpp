// Given two integers start and end, return a sorted list of integers 
// such that every number e is between start ≤ e ≤ end and the digits
// of e are contiguously increasing. For example, 
// 2345 is contiguously increasing while 135 and 321 are not.


// Input
// start = 0
// end = 100
  
// Output
// [1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 23, 34, 45, 56, 67, 78, 89]


////////////////////////////////////////////////////////////////////////////////////////////////////////////

// vector<int> solve(int start, int end) {
//     vector<int> ans;
//     vector<pair<int, int>> nums{{1, 9},
//                                 {12, 89},
//                                 {123, 789},
//                                 {1234, 6789},
//                                 {12345, 56789},
//                                 {123456, 456789},
//                                 {1234567, 3456789},
//                                 {12345678, 23456789},
//                                 {123456789, 123456789}};
//     for (int i = 0, diff = 1; i < nums.size(); i++, diff = diff * 10 + 1) {
//         if (start > nums[i].second) continue;
//         for (int val = nums[i].first; val <= nums[i].second; val += diff) {
//             if (val > end) return ans;
//             if (val >= start) ans.push_back(val);
//         }
//     }
//     return ans;
// }

vector<int>ans;
void dfs(int val,int start,int end)
{
    if(val>=start && val<=end)
    {
        ans.push_back(val);
    }
    else if(val > end)
        return;

    for(int i=1;i<=9;i++)
    {
        if(i- (val%10) == 1)
        {
            dfs((val*10+i), start, end);
        }
    }
}
vector<int> solve(int start, int end) {
   ans.clear();
   for(int i=1;i<=9;i++)
   {
        dfs(i,start,end);
   }
   sort(ans.begin(),ans.end());
    return ans;
}
