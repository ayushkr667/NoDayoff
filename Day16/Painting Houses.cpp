// You are looking to paint a row of N fences that can be of K different colors. 
//You have a goal of minimizing cost while ensuring that no two neighboring fences are of the same color.

// Given an N by K matrix where the nth row and kth column represents the 
//cost to paint the nth fence with kth color, return the minimum cost which achieves this goal.

// Note: All costs will be integers greater than or equal to 0, and there is guaranteed to be at least 2 possible colors.

// Bonus: solve in \mathcal{O}(1)O(1) space.

// Constraints

// N, K ≤ 500
// Example 1
// Input
// matrix = [
//     [5, 3, 4],
//     [2, 1, 6],
//     [2, 3, 4],
//     [4, 3, 3]
// ]
// Output
// 10
// Explanation
// Choose the following color indices (starting from the first fence): 4 -> 1 -> 2 -> 3.

// Example 2
// Input
// matrix = [
//     [1, 1, 1],
//     [1, 1, 1],
//     [1, 1, 1],
//     [1, 1, 1],
//     [1, 1, 1]
// ]
// Output
// 5

///////////////////////////////////////////////////////////////////////////////////////////////////


int solve(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int dp[n][m];
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
        {
            if(i==0){
                dp[i][j] = matrix[i][j];
            }
            else{
                int temp = INT_MAX;
                for(int k=0; k<m; k++){
                    if(k != j)
                        temp = min(temp, dp[i-1][k]);
                }
                dp[i][j] = matrix[i][j] + temp;
            }
        } 
    }
    int res = INT_MAX;
    for(int i=0; i<m; i++){
        res = min(res, dp[n-1][i]) ;
    }
    return res;
}
