// question - https://cses.fi/problemset/task/1633/
#include <bits/stdc++.h>
using namespace std;
int n;
#define MOD 1000000007
vector<int> dp;

int count(int num){
    // cache check
    if (dp[num] != -1) return dp[num];

    // calculation
    int cal = 0;
    for(int i = 1; i <= 6; i++){ // run from 1 to 6
        if (num - i >= 0){ // checking if throw is even possible
            cal += count(num - i); // recall or calc num - i
            cal = cal % MOD; // mod for overflow
        }
    }
    dp[num] = cal;

    // return the result
    return dp[num];
}

int main(){
    cin >> n;
    dp.resize(n+1);
    fill(dp.begin(), dp.end(), -1);
    dp[0] = 1; // number of ways to obtain 0 is 1, ie throwing no dice at all

    cout << count(n);
    
    return 0;
}
