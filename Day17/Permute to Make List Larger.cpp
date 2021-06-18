// You are given two lists of integers a and b, both of the same length. 
// Given that you can first permute a in any order, 
// return the maximum number of indices where a[i] > b[i].

////////////////////////////////////////////////////////////////////////////////

int solve(vector<int>& a, vector<int>& b) {
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    int res = 0, i =0 , j = 0;
    while(j < b.size()){
        // cout << i << " " << j << "\n";
        if(a[i] > b[j]){
            res++;
            i++;
            j++;
        }else{
            j++;
        }
    }
    return res;
}
