You are given a two-dimensional list of integers intervals and an integer point. Each element contains [start, end] represents an inclusive interval.

Return the number of intervals that are intersecting at point.

Input

intervals = [
    [1, 5],
    [3, 9],
    [4, 8],
    [10, 13]
]
point = 4

Output
3

////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int solve(vector<vector<int>>& iv, int p) {
    if(iv.size()== 0)
        return 0;

    int ans =0;

    for(int i=0; i<iv.size(); i++){
        if(iv[i][0] <= p && iv[i][1] >= p)
        {
            ans++;
        }
    }
    return ans;
}
