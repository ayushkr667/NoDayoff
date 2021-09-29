// Given an 2D matrix of 0s and 1s, a 1 represents land and 0 represents water. 
// An island is a group of 1's that are surrounded by 0s or by the border. 
// Find all the islands that are completely surrounded by water and modify them into 0s.

// An island is completed surrounded by water if all of the neighbours are water 
// (that is, none of the neighbours are borders).

// Note: Neighbours can only be directly horizontal or vertical, not diagonal.

// Constraints

// n, m ≤ 250 where n and m are the number of rows and columns in matrix
// Example 1
// Input
// board = [
//     [1, 0, 0, 0],
//     [0, 1, 1, 0],
//     [0, 0, 0, 0]
// ]
// Output
// [
//     [1, 0, 0, 0],
//     [0, 0, 0, 0],
//     [0, 0, 0, 0]
// ]

//////////////////////////////////////////////////////////////////////////////////////////



int n, m;
void dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& mark) {
    if (i < 0 || j < 0 || i >= n || j > m || mark[i][j] || matrix[i][j] == 0) return;
    mark[i][j] = 1;
    dfs(i - 1, j, matrix, mark);
    dfs(i + 1, j, matrix, mark);
    dfs(i, j - 1, matrix, mark);
    dfs(i, j + 1, matrix, mark);
    return;
}
vector<vector<int>> solve(vector<vector<int>>& board) {
    n = board.size();
    m = board[0].size();
    vector<vector<int>> mark(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                if (mark[i][j] == 0 && board[i][j] == 1) {
                    dfs(i, j, board, mark);
                }
        }
    }
    return mark;
}
