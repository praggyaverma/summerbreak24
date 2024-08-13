class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m, j = 0;
        for(i = m; i < m + n; i++){
            nums1[i] = nums2[j++];
        }

        int gap = ceil((m + n) / 2.0);

        while (gap){
            i = 0;
            j = gap;
            while (j < m + n){
                if (nums1[i] > nums1[j]){
                    swap(nums1[i], nums1[j]);
                }
                i++;
                j++;
            }
            if (gap == 1) break;
            gap = ceil (gap / 2.0);
        }
    }
};
