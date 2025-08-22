class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> rank(26);
        for(int i = 0; i < 26; i++) rank[order[i] - 'a'] = i;
        for(int i = 0; i + 1 < words.size(); i++){
            int j = 0;
            for(; j < min(words[i].size(), words[i+1].size()); j++){
                if(words[i][j] != words[i+1][j]){
                    if(rank[words[i][j]-'a'] > rank[words[i+1][j]-'a']) return false;
                    break;
                }
            }
            if(j == words[i+1].size() && words[i].size() > words[i+1].size()) return false;
        }
        return true;
    }
};