// TC - O(logN) 
// SC - O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid;

        while (l <= r){
            mid = l + (r-l) / 2;
            int comp = nums[mid];
            if ((target < nums[0]) && (nums[mid] < nums[0]) || target >= nums[0] && nums[mid] >= nums[0]){
                comp = nums[mid];
            } else {
                if (nums[0] > target){
                    comp = INT_MIN;
                } else {
                    comp = INT_MAX;
                }
            }
            if (comp == target){
                return mid;
            } else if (comp < target){
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return -1;
    }
};
