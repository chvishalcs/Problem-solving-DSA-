class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 1;i++){
            if(nums[i] == nums[i+1]) return nums[i];
            if(i < nums.size() - 2 && nums[i] == nums[i + 2]) return nums[i];
            if(i < nums.size() - 3 && nums[i] == nums[i + 3]) return nums[i]; 
        }
        return -1;
    }
};