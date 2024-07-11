class Solution {
  void helper(int idx, vector<int> arr, int n, int currSum, vector<int> allSum){
        if (idx == n){
            allSum.push_back(currSum);
            return;
        }
        
        currSum += arr[idx];
        helper(idx + 1, arr, n, currSum, allSum);
        
        currSum -= arr[idx];
        helper(idx + 1, arr, n, currSum, allSum);
    }
  public:
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int> allSum;
        helper(0, arr, n, 0, allSum);
        
        return allSum;
    }
}
