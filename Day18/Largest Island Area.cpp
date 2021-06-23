// You are given a two-dimensional integer matrix of 1s and 0s. 
// A 1 represents land and 0 represents water, so an island is a group of 1s 
// that are neighboring whose perimeter is surrounded by water. 
// You can assume that the edges of the matrix are surrounded by water.

// Return the area of the largest island in matrix.

// Constraints

// n, m ≤ 250 where n and m are the number of rows and columns in matrix
// Example 1
// Input
// matrix = [
//     [0, 0, 0, 1, 1, 1, 1],
//     [0, 0, 0, 0, 0, 0, 0],
//     [0, 1, 1, 1, 1, 1, 0],
//     [0, 0, 1, 1, 0, 0, 0],
//     [0, 0, 0, 0, 0, 1, 1],
//     [0, 0, 0, 0, 0, 0, 0]
// ]
// Output
// 7

////////////////////////////////////////////////////////////////////////////

int dfs(vector<vector<int>>& matrix, int i, int j) {
    if (i < 0 or j < 0 or i > matrix.size() - 1 or j > matrix[i].size() - 1 or matrix[i][j] == 0)
        return 0;
    matrix[i][j] = 0;
    return 1 + dfs(matrix, i - 1, j) + dfs(matrix, i, j + 1) + dfs(matrix, i + 1, j) +
           dfs(matrix, i, j - 1);
}

int solve(vector<vector<int>>& matrix) {
    int ans = 0;
    for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix[i].size(); j++) ans = max(ans, dfs(matrix, i, j));
    return ans;
}
