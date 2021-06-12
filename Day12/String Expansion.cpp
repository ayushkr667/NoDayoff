// You are given a string s consisting of lowercase alphabet characters, 
//digits, and brackets"(" and ")". s encodes a longer string and is represented
//as concatenation of n(t), where n is the number of times t is repeated, 
//and t is either a regular string or it's another encoded string recursively.

// Return the expanded version of s. Note that t can be the empty string.

// Example 1
// Input
// s = "2(ye)0(z)2(2(po)w)"
// Output
// "yeyepopowpopow"

/////////////////////////////////////////////////////////////////////////////////////

string solve(string s) {
    string res= "";
    stack<int>st;
    stack<string>str;
    for(int i=0; i<s.size(); i++){
        if(isdigit(s[i])){
            st.push(s[i]-'0');
        }
        else if(s[i] != ')'){
            string ss = "";
            ss += s[i];
            str.push(ss);
        }
        else{
            res = "";
            while(!str.empty()){
                if(str.top() == "(")
                    break;

                res = str.top() + res;
                str.pop();
            }
            str.pop();

            if(!st.empty()){
                int num = st.top();
                st.pop();

                string temp = "";
                for(int i=0; i<num; i++){
                    temp += res;
                }
                res = temp;
            }
            str.push(res);
        }
    }
    res = "";
    while(!str.empty()){
        res = str.top() + res;
        str.pop();
    }
    return res;
}
