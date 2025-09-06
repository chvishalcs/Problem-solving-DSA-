class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(256, -1);
        int maxLen = 0, start = -1;
        for(int i = 0; i < s.size(); i++){
            if(lastIndex[s[i]] > start){
                start = lastIndex[s[i]];
            }
            lastIndex[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};