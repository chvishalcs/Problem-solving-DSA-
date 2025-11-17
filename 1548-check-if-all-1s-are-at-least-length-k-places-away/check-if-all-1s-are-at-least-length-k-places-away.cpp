class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last = -1; // index of last seen 1

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                if (last != -1 && i - last - 1 < k)
                    return false;  // distance between 1s is less than k
                last = i; // update last index of 1
            }
        }

        return true;
    }
};
