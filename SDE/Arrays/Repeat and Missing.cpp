
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long N = A.size();
    int xr = 0;
    
    for(int i = 0; i < N; i++){
        xr = xr ^ A[i];
        xr = xr ^ (i + 1);
    }
    
    // the differentiating bit number
    int diffBit = (xr & ~(xr - 1));
    
    int zero = 0, one = 0;
    
    for(int i = 0; i < N; i++){
        // for array elements
        if ((A[i] & diffBit) != 0) {
            one = one ^ A[i];
        }
        else {
            zero = zero ^ A[i];
        }
        // for 1 2 ... n elements
        if (((i+1) & diffBit) != 0) {
            one = one ^ (i+1);
        }
        else {
            zero = zero ^ (i+1);
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == zero) cnt++;
    }
    
    //ie repeated number is zero
    if (cnt == 2) return {zero, one};
    // ie repeated number is one
    return {one, zero};
}


vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long N = A.size();
    long long sum = 0, sumN = 0, sqSum = 0, sqSumN = 0;
    long long rep, mis;
    
    for(int a : A) {
        sum += (long long)a;
        sqSum += (long long)a * (long long)a;
    }
    
    sumN = (N * (N + 1)) / 2;
    sqSumN = (N * (N + 1) * (2 * N + 1)) / 6;
    
    long long val1 = sum - sumN;
    long long val2 = (sqSum - sqSumN);
    val2 = val2 / val1;
    
    rep = ((val1 + val2) / 2);
    mis = (rep - val1);
    
    return {(int)rep, (int)mis};
}
