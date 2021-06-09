//You are given an integer n consisting of digits 1, 2, 
//and 3 and you can flip one digit to a 3. Return the maximum number you can make.


int solve(int n) {
    vector<int>vec;
    while(n != 0){
        vec.push_back(n%10);
        n /= 10;
    }
    for(int i=vec.size()-1; i>=0; i--){
        if(vec[i] != 3){
            vec[i] = 3;
            break;
        }
    }
    int num =0;
    for(int i=vec.size()-1; i>=0; i--){
        num  = num*10 + vec[i];
    }
    return num;
}
