#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    vector<vector<int>> dp(n + 1, vector<int>(x + 1));
    for(int i = 0; i < n; i++){
        dp[i][0] = 1;
    } // number of ways required to obtain sum=0 is 1, ie no coin chosen at all

    // dp process
    for (int i = n - 1; i >= 0; i--){
        for (int sum = 1; sum <= x; sum++){
            int skip = dp[i+1][sum]; // we skip the current coin
            int pick = 0; 
            if (arr[i] <= sum) pick = dp[i][sum - arr[i]]; // we pick the current coin provided we have it's denomination and we submit the arr[i] from coin
            dp[i][sum] = (pick + skip) % MOD;
        }
    }
    
    cout << dp[0][x]; // starting from the 1st coin reaching to x
    
    return 0;
}
