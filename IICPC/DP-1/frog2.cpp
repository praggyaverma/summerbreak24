// https://atcoder.jp/contests/dp/tasks/dp_b
// dp solution
#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> arr;
vector<long long> dp;

long long minCost(int i){

    // cache check
    if (dp[i] != -1) return dp[i];
    
    // calculation
    long long val = INT_MAX;
    for(int j = 1; j <= k; j++){
        if (i - j >= 0) val = min(val, abs(arr[i] - arr[i - j]) + minCost(i - j));
    }
    
    dp[i] = val;
    
    // return result
    return dp[i];
}

int main()
{
    cin >> n >> k;
    arr.resize(n);
    dp.resize(n);
    fill(dp.begin(), dp.end(), -1);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    dp[0] = 0;
    dp[1] = abs(arr[1] - arr[0]);

    cout << minCost(n-1);
    
    return 0;
}
