// You are given a list of integers cells, representing sizes of different cells. 
// In each iteration, the two largest cells a and b interact according to these rules:

// If a = b, they both die.
// Otherwise, the two cells merge and their size becomes floor((a + b) / 3).
// Return the size of the last cell or return -1 if there's no cell is remaining.

/////////////////////////////////////////////////////////////////////////////////////////////

int solve(vector<int>& cells) {
    priority_queue<int> pq;
    for(int i=0; i<cells.size(); i++){
        pq.push(cells[i]);
    }
    while(pq.size()>1){
        int a = pq.top();   pq.pop();
        int b = pq.top();   pq.pop();
        if(a != b){
            pq.push( floor((a+b)/3) );
        }
    }
    if( pq.empty() )
        return -1;
    return pq.top();
}
