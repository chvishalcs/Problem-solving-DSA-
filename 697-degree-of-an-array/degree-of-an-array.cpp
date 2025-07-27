class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> count, firstIndex, lastIndex;
        int degree = 0;

        for(int i = 0; i < nums.size(); ++i){
            int num = nums[i];
            if(firstIndex.find(num) == firstIndex.end())
            firstIndex[num] = i;
            lastIndex[num] = i;
            count[num]++;
            degree = max(degree, count[num]);
        }

        int minLen = nums.size();
        for(auto& [num, freq] : count){
            if(freq == degree) {
                minLen = min(minLen, lastIndex[num] - firstIndex[num] + 1);
            }
        }
        return minLen;
    }
};