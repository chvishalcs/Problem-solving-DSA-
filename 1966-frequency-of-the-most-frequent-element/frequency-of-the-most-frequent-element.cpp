class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long total = 0;
        int start = 0;
        int maxFreq = 0;
        for(int i = 0;i < nums.size(); i++){
            total += (long long)nums[i];
            while((long long)nums[i] * (i - start + 1) - total > k){
                total -= nums[start];
                start++;
            }
            maxFreq = max(maxFreq, i - start + 1);
        }
        return maxFreq;
    }
};