// question - https://cses.fi/problemset/task/1634/

// in this question, i have not used recursive function to find dp[i] as it was causing time limit exceeded error

/* 
  time complexity is (states)*(avg transition time per state)
                      (x)    *         (n)
                      ie (xn)

                      gives hint towards a xn solution 
*/
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
    fill(dp.begin(), dp.end(), -1); 
    dp[0] = 0; // number of coins required to obtain sum=0 is 0

    for(int i = 1; i <= x; i++){
        for (int j = 0; j < n; j++){
            if (i - arr[j] >= 0 && dp[i - arr[j]] != -1) 
                dp[i] = min(dp[i], 1 + dp[i - arr[j]]);
        }
    }
    
    cout << dp[x];
    
    return 0;
}
