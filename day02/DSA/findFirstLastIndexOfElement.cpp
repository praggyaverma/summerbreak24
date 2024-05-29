// TC - O(logN)
// SC - O(1)

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int first = -1, last = -1, l, r, mid;

        l = 0, r = nums.size() - 1;

        while(l <= r){
            mid = l + (r - l) / 2;
            if (nums[mid] == target){
                first = mid;
                r = mid - 1;
            } else if (nums[mid] < target){
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        l = 0, r = nums.size() - 1; 
        while(l <= r){
            mid = l + (r - l) / 2;
            if (nums[mid] == target){
                last = mid;
                l = mid + 1;
            } else if (nums[mid] < target){
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        result.push_back(first);
        result.push_back(last);

        return result;
    }
};
