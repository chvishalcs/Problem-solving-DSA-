class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> incLeft(n, 1), incRight(n, 1);
        
        // Increasing lengths ending at i
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) incLeft[i] = incLeft[i - 1] + 1;
        }
        
        // Increasing lengths starting at i
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) incRight[i] = incRight[i + 1] + 1;
        }
        
        int maxK = 0;
        for (int i = 0; i < n - 1; ++i) {
            maxK = max(maxK, min(incLeft[i], incRight[i + 1]));
        }
        
        return maxK;
    }
};
