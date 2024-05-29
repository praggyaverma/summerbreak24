// TC - O(logN)
// SC - O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = -1;
        int r = nums.size();

        while (r - l > 1){
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) l = mid;
            else r = mid;
        }
        return -1;
    }
};

// TC - O(logN)
// SC - O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r){
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
};
