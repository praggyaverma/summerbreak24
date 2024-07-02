#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main(){
    int n;
    cin >> n;
    vector<vector<int>> a(n+1, vector<int>(4)); // (n+1)*(4) size for easy calling as dp_matrix also has same dimensions
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 3; j++){
            cin >> a[i][j];
        }
    }
    
    vector<vector<int>> dp(n + 1, vector<int>(4));
    // base case
    dp[1][1] = a[1][1];
    dp[1][2] = a[1][2];
    dp[1][3] = a[1][3];

    // dp process
    for (int day = 2; day <= n; day++){
        for (int act = 1; act <= 3; act++){
            if (act == 1){
                dp[day][act] = a[day][act] + max(dp[day-1][act+1], dp[day-1][act+2]);
            } else if (act == 2){
                dp[day][act] = a[day][act] + max(dp[day-1][act-1], dp[day-1][act+1]);
            } else {
                dp[day][act] = a[day][act] + max(dp[day-1][act-1], dp[day-1][act-2]);
            }
        }
    }

  // find the maximum calculated fun
    int sol = dp[n][1];
    for(int i = 2; i <= 3; i++){
        sol = max(dp[n][i], sol); 
    }

    cout << sol;
    
    return 0;
}
