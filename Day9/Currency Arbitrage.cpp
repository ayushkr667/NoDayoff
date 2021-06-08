// Intuition
// Solution is based on observation. Let say if you 1currency of type A 
//then you convert it to Type B, and finally if you convert it back to 
//type A you should have 1 currency type A. 
//If somehow you can get more than 1 then simply it means you found the solution.
// Check for each pair of currency that if conversion would be equal to 1.

//means if traverse all graph any pair i,j and
//j,i must be there from there money start increasing
//if solution is there

bool solve(vector<vector<double>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] * matrix[j][i] > 1) {
                return 1;
            }
        }
    }
    return 0;
}
