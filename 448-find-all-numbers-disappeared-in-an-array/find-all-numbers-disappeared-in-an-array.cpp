class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        for(int num : nums){
            int index = abs(num) - 1;
            if(nums[index] > 0){
                nums[index] = -nums[index];
            }
        }
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > 0){
                result.push_back(i + 1);
            }
        }
        return result;
    }
};