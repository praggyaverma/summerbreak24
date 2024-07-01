// question link - https://atcoder.jp/contests/dp/tasks/dp_a

// dp code
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> arr;
vector<int> dp;

int minCost(int i){

    // cache check
    if (dp[i] != -1) return dp[i];
    
    // calculation
    dp[i] = min(abs(arr[i] - arr[i - 1]) + minCost(i-1),
                abs(arr[i] - arr[i - 2]) + minCost(i-2));

    // return result
    return dp[i];
}

int main()
{
    cin >> n;
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


// recursive code
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> arr;

int minCost(int i){
    // base case
    if (i == 0) return 0;
    if (i == 1) return abs(arr[1] - arr[0]);
    
    // rec for (i-1)
    int costi = abs(arr[i] - arr[i - 1]) + minCost(i-1);
    
    // rec for (i-2)
    int costi1 = abs(arr[i] - arr[i - 2]) + minCost(i-2);
    
    return min(costi, costi1);
}

int main()
{
    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    cout << minCost(n-1);
    

    return 0;
}
