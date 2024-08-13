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
