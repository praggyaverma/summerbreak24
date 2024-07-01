#include <bits/stdc++.h>
using namespace std;

int n, W;
vector<int> w, v;
vector<vector<long long>> dp;

long long knapsack(int i, int weight) {
    if (i == n) return 0;
    
    // cache check
    if (dp[i][weight] != -1) return dp[i][weight];
    
    // do not take the item
    long long val = knapsack(i + 1, weight);
    
    // we take the item
    if (weight + w[i] <= W) 
        val = max(val, v[i] + knapsack(i + 1, weight + w[i]));
    
    // return the result
    dp[i][weight] = val;
    return val;
}

int main() {
    cin >> n >> W;
    w.resize(n);
    v.resize(n);
    dp.resize(n, vector<long long>(W + 1, -1)); 
    
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }

    cout << knapsack(0, 0);
    
    return 0;
}
