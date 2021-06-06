//Given a two-dimensional square matrix, rotate in-place it 90 degrees counter-clockwise.
//
Input
matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]
Output
[
    [3, 6, 9],
    [2, 5, 8],
    [1, 4, 7]
]

////////////////////////////////////////////////////////////////////////
vector<vector<int>> solve(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    for(int i=0; i<n; i++){
        for(int j=0; j<m/2; j++){
            swap(matrix[i][j], matrix[i][m-j-1]);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    return matrix;
}
