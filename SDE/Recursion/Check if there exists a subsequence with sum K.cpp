//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// recursion solution
class Solution{
    bool helper(int idx, int n, vector<int>& arr, int sum, int currSum){
        if (idx == n){
            if (currSum == sum){
                return true;
            } else return false;
        }
        
        currSum += arr[idx];
        if (helper(idx + 1, n, arr, sum, currSum))
            return true;
        
        currSum -= arr[idx];
        if (helper(idx + 1, n, arr, sum, currSum))
            return true;
            
        return false;
    }
    public:
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        return helper(0, n, arr, k, 0);
    }
};
