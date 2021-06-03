//Given two lowercase alphabet strings a and b, 
//return the length of a minimum substring in a that contains all the characters of b.

//If no such substring exists, return -1.

// Input
// a = "qthequickbrownfox"
// b = "qown"

// Output
// 10

// Explanation
// The shortest substring that contains "qown" is "quickbrown" which has length of 10.
//each character is assumed as different even if they are same
////////////////////////////////////////////////////////////////////////////////////////////////

int solve(string a, string b) {
    if(a.size() < b.size()){
        return -1;
    }

    unordered_map<char, int> mp_b, mp_a;
    
    for(int i=0; i<b.size(); i++)
        mp_b[b[i]] ++;

    int st = 0, len = INT_MAX;
    bool found = false;

    int count = 0;

    for(int i=0; i<a.size(); i++){
        mp_a[a[i]]++;

        if( mp_a[a[i]] <= mp_b[a[i]] )
            count++;

        if( count == b.size() ){

            //now minimize 
            //mp_a[a[st]]>mp_b[a[st]] it ensures that 
            //first character is found somewhere in last
            while(mp_a[a[st]]>mp_b[a[st]]||mp_b[a[st]] == 0){

                if (mp_a[a[st]] > mp_b[a[st]])
                    mp_a[a[st]]--;

                st++;
            }

            int temp = i - st + 1;
            if (len > temp) {
                len = temp;
                found = true;
            }
        }
    }

    if( found == false )
        return -1;

    return len;
}

