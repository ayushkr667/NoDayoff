// Given a list of integers prices representing the stock prices of a company in chronological order, 
// return the maximum profit you could have made from buying and selling that stock at most two times.

// You must buy before you can sell it.

// Note: You are not required to buy or sell the stock

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// int solve(vector<int>& prices) {
//     int buy1 = INT_MIN, sale1 = 0;
//     int buy2 = INT_MIN, sale2 = 0;

//     for(int i=0; i<prices.size(); i++){
//         buy1 = max(buy1, -prices[i]); //money left after 1st buy
//         sale1 = max(sale1, prices[i] + buy1); //money after selling 1st buy
//         buy2 = max(buy2, sale1-prices[i]); //2nd buy
//         sale2 = max(sale2, prices[i] + buy2); //money after 2nd sell
//     }
//     return sale2;
// }


//another approach
int solve(vector<int>& prices) {
    if (prices.size() == 0) return 0;
    int n = prices.size();

    int dp[n];
    for (int i = 0; i < n; i++) 
        dp[i] = 0;

    //profit from right to left
    int buy1 = prices[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (buy1 < prices[i]) buy1 = prices[i];
        dp[i] = max(dp[i + 1], buy1 - prices[i]);
    }

    //profit from left to right
    int buy2 = prices[0];
    for (int i = 1; i < n; i++) {
        if (buy2 > prices[i]) buy2 = prices[i];
        dp[i] = max(dp[i - 1], dp[i] + (prices[i] - buy2));
    }

    return dp[n - 1];
}

