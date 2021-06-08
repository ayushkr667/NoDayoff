//Given a list of sorted lists of integers,
//merge them into one large sorted list.

////////////////////////////////////////////////////////////////////////////////////

vector<int> solve(vector<vector<int>>& lists) {
    if(lists.size() == 1)
        return lists[0];

    vector<int> temp = lists[0];
    for(int i=1; i<lists.size(); i++){
        for(int j=0; j<lists[i].size(); j++){
            temp.push_back(lists[i][j]);
        }
    }
    sort(temp.begin(), temp.end());
    return temp;
}
