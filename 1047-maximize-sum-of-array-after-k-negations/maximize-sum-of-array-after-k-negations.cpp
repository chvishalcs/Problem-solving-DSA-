class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), [](int a,int b){
            return abs(a) > abs(b);
        });
        for(int &x : nums){
            if(x < 0 && k > 0){
                x = -x;
                k--;
            }
        }
        if(k % 2 == 1)
        nums.back() = -nums.back();
        return accumulate(nums.begin(), nums.end(), 0);
    }
};