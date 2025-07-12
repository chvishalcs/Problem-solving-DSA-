class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> curr;
        vector<bool> used(nums.size(), false);
        backtrack(nums, used, curr, res);
        return res;
    }
    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& curr, vector<vector<int>>& res){
        if(curr.size() == nums.size()){
            res.push_back(curr);
            return ;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(used[i]) continue;
            if(i > 0 && nums[i] == nums[i-1] && !used[i-1])
            continue;
            curr.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, used, curr, res);
            curr.pop_back();
            used[i] = false;
        }
    }
};