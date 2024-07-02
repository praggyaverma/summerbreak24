#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int n, x;
vector<int> arr;
vector<int> dp; // holds the number of coins for ith sum

int main(){
    cin >> n >> x;
    arr.resize(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    dp.resize(x+1);
    fill(dp.begin(), dp.end(), 0);
    dp[0] = 1; // number of ways required to obtain sum=0 is 1, ie no coin chosen at all

    // dp process
    for(int i = 1; i <= x; i++){
        for (int j = 0; j < n; j++){
            if (i - arr[j] >= 0){ // to check if dp[-ve] value does not happen
                dp[i] = (dp[i] + dp[i - arr[j]]) % MOD; // when dealing with MOD, always work like this to avoid any error due to overflow.
            }
        }
    }
    
    cout << dp[x];
    
    return 0;
}
