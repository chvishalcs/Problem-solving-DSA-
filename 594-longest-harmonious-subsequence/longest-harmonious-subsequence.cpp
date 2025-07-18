class Solution {
public:
    int findLHS(vector<int>& nums) {
        std::unordered_map<int, int> freq;
        int maxLen = 0;

        for(int num : nums){
            freq[num]++;
        }
        for(auto& [key, val] : freq){
            if(freq.find(key + 1) != freq.end()){
                maxLen = std::max(maxLen, val + freq[key + 1]);
            }
        }
        return maxLen;
    }
};