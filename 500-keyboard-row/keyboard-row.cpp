class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> result;
        unordered_map<char, int> rowMap;

        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";

        for(char c : row1) rowMap[c] = 1;
        for(char c : row2) rowMap[c] = 2;
        for(char c : row3) rowMap[c] = 3;

        for(string word : words) {
            int row = rowMap[tolower(word[0])];
            bool sameRow = true;

            for(char c : word){
                if(rowMap[tolower(c)] != row){
                    sameRow = false;
                    break;
                }
            }
            if(sameRow) result.push_back(word);
        } 
        return result;

        
    }
};