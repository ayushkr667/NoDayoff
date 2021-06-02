Given strings a and b, return the length of the shortest string that has both a and b as

Input
a = "bell"
b = "yellow"
Output
7
Explanation
One possible solution is "ybellow".

/////////////////////////////////////////////////////////////////////////////////////////////////

int solve(string a, string b) {
    int n = a.size();
    int m = b.size();
    int dp[n+1][m+1];

    for(int i=0; i<=n; i++){
        dp[i][0] = 0;
    }

    for(int i=0; i<=m; i++){
        dp[0][i] = 0;
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return n + m - dp[n][m];
}
