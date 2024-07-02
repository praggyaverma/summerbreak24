// codeforces 
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    vector<vector<int>> dp(n + 1, vector<int>(3, MOD));
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;

    // dp process
    for(int i = 1; i <= n; i++){
        int k = a[i-1];
        dp[i][0] = 1 + min({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
        if (k == 1 || k == 3){
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
        } else {
            dp[i][1] = dp[i-1][1] + 1;
        }
        if (k == 2 || k == 3){
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
        } else {
            dp[i][2] = dp[i-1][2] + 1;
        }
    }
    
    cout << min({dp[n][0], dp[n][1], dp[n][2]});
    
    return 0;
}
