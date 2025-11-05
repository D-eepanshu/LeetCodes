class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
      
        // Lambda function to find the k-th smallest element in two sorted arrays
        // Parameters: index1 - starting index in nums1
        //            index2 - starting index in nums2
        //            k - we want to find the k-th smallest element (1-indexed)
        function<int(int, int, int)> findKthElement = [&](int index1, int index2, int k) {
            // If nums1 is exhausted, return the k-th element from nums2
            if (index1 >= size1) {
                return nums2[index2 + k - 1];
            }
          
            // If nums2 is exhausted, return the k-th element from nums1
            if (index2 >= size2) {
                return nums1[index1 + k - 1];
            }
          
            // Base case: if k is 1, return the minimum of current elements
            if (k == 1) {
                return min(nums1[index1], nums2[index2]);
            }
          
            // Binary search approach: eliminate k/2 elements at a time
            int halfK = k / 2;
          
            // Get the element at position (index + k/2 - 1) in each array
            // If out of bounds, use INT_MAX to ensure we don't choose this array
            int value1 = (index1 + halfK - 1 < size1) ? nums1[index1 + halfK - 1] : INT_MAX;
            int value2 = (index2 + halfK - 1 < size2) ? nums2[index2 + halfK - 1] : INT_MAX;
          
            // Compare and eliminate the smaller half
            // If value1 < value2, all elements from nums1[index1] to nums1[index1 + halfK - 1]
            // are guaranteed to be among the smallest k elements
            if (value1 < value2) {
                return findKthElement(index1 + halfK, index2, k - halfK);
            } else {
                return findKthElement(index1, index2 + halfK, k - halfK);
            }
        };
      
        // Find the median elements
        // For odd total length: both leftMedian and rightMedian are the same (middle element)
        // For even total length: leftMedian is the left middle, rightMedian is the right middle
        int totalLength = size1 + size2;
        int leftMedian = findKthElement(0, 0, (totalLength + 1) / 2);
        int rightMedian = findKthElement(0, 0, (totalLength + 2) / 2);
      
        // Return the average of the two middle elements
        return (leftMedian + rightMedian) / 2.0;
    }
};
