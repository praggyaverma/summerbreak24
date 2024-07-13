#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> dp(n + 1, INT_MAX);
    //dp[i] is no of steps to convert sum i to 0
    dp[0] = 0;
    
    for(int i = 1; i <= n; i++){
        string s = to_string(i);
        for(char c : s){
            int digit = c - '0';
            if (digit != 0){
                dp[i] = min(dp[i], dp[i - digit] + 1);
            }
        }
    }
    
    cout << dp[n] << endl;

    return 0;
}
