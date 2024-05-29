// TC - O(n^2)
// SC - O(n^2)
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++){
            dp[i][i] = piles[i];
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n - i; j++){
                dp[j][j + i] = max(piles[j] - dp[j+1][j+i],
                                   piles[j+i] - dp[j][j+i-1]);
            }
        }
        return dp[0][n-1] > 0;
    }
};


// TC - O(1)
// SC - O(1)
class Solution {
    public boolean stoneGame(int[] piles) {
        return true;
    }
}
