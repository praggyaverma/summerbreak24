// TC - O(N)
// SC - O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 1, right = n - 2; // for traversal
        int maxLeft = height[0], maxRight = height[n - 1]; // for maintaining max height
        int volume = 0; // for storing water amount

        while (left <= right){
            if (maxLeft < maxRight){
                if (height[left] > maxLeft){
                    maxLeft = height[left];
                } else {
                    volume += maxLeft - height[left];
                }
                left++;
            } else {
                if (height[right] > maxRight){
                    maxRight = height[right];
                } else {
                    volume += maxRight - height[right];
                }
                right--;
            }
        }
        return volume;
    }
};
