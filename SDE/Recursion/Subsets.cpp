class Solution {
    void helper(int idx, vector<int>& save, vector<int>& nums){
        if (idx >= n){
            output.push_back(save);
            return;
        }
        save.push_back(nums[idx]);
        helper(idx + 1, save, nums);
        save.pop_back();
        helper(idx + 1, save, nums);
    }
public:
    vector<vector<int>> output;
    int n;
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int> save;
        helper(0, save, nums);

        return output;
    }
};
