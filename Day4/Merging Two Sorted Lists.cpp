//Given two lists of integers a and b sorted in ascending order, merge them into one large sorted list.
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  vector<int> solve(vector<int>& a, vector<int>& b) {
    vector<int> res;
    for(int i=0; i<a.size(); i++){
        res.push_back(a[i]);
    }

    for(int i=0; i<b.size(); i++){
        res.push_back(b[i]);
    }

    sort(res.begin(), res.end());
    return res;
}
