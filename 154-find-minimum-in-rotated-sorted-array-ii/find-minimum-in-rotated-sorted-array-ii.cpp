class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                // Minimum in right half
                left = mid + 1;
            }
            else if (nums[mid] < nums[right]) {
                // Minimum in left half including mid
                right = mid;
            }
            else {
                // nums[mid] == nums[right]
                right--;
            }
        }

        return nums[left];
    }
};