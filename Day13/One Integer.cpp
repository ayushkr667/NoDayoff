// You are given a list of integers nums. 
// You can reduce the length of nums by taking any two integers, 
// removing them, and appending their sum to the end. The cost of
// doing this is the sum of the two integers you removed.

// Return the minimum total cost of reducing nums to one integer.

/////////////////////////////////////////////////////////////////////

int solve(vector<int>& nums) {
    priority_queue<int, vector<int>, greater<int>>pq;
    for(int num:nums){
        pq.push(num);
    }
    int res = 0;
    while(pq.size()>1){
        int num1 = pq.top();    pq.pop();
        int num2 = pq.top();    pq.pop();
        res += (num1 + num2);
        pq.push(num1+num2);
    }
    return res;
}
