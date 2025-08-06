class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bannedSet(banned.begin(), banned.end());
        unordered_map<string, int> wordCount;
        string word;
        for(char& c : paragraph){
            if(isalpha(c)){
                word += tolower(c);
            } else if (!word.empty()){
                if(!bannedSet.count(word)){
                    wordCount[word]++;
                }
                word.clear();
            }
        }
        if(!word.empty() && !bannedSet.count(word)){
            wordCount[word]++;
        }
        string result;
        int maxFreq = 0;
        for(auto& [w, count] : wordCount) {
            if(count > maxFreq){
                maxFreq = count;
                result = w;
            }
        }
        return result;
    }
};