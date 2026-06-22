class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int m = nums1.size();
        int n = nums2.size();
        int totalSize = m + n;
        int medianPlace = (totalSize + 1) / 2;

        int start = 0;
        int end = m;

        while (start <= end) {
            int cut1 = (start + end)/2;
            int cut2 =  medianPlace - cut1;

            int maxLeft1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int minRight1 = (cut1 == m) ? INT_MAX : nums1[cut1];
            
            int maxLeft2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int minRight2 = (cut2 == n) ? INT_MAX : nums2[cut2];

            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                if (totalSize % 2 == 0) {
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                } else {
                    return max(maxLeft1, maxLeft2);
                }
            }
            else if (maxLeft1 > minRight2)
                end = cut1 - 1;
            else
                start = cut1 + 1;
        }

        return 0.0;
    }
};
