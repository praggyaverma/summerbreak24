#include <bits/stdc++.h>
using namespace std; 
/*
f(X,weight) -> f(X+1,weight - current_weight) + current_value, if weight - current_weight ≥ 0

or f(X,weight) -> f(X+1,weight) 
*/

int knapsack(int index, vector<int>&w, vector<int>&v, int W, int maxi){
    if (index >= w.size()) return 0;
    
    // pick
    int pick = INT_MIN;
    if (W - w[index] >= 0){
        pick = knapsack(index+1,w,v,W-w[index],maxi) + v[index];
    }
    //skip
    int skip = knapsack(index+1,w,v,W,maxi);
    
    maxi = max(skip,pick);
    return maxi;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, W;
    cin >> N >> W;
    vector<int> w(N), v(N);
    for(int i = 0; i < N; i++){
        cin >> w[i] >> v[i];
    }
    
    int maxi = INT_MIN;
    
    cout << knapsack(0, w, v, W, maxi) << endl;
}
