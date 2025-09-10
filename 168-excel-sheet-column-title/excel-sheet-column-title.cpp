class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        while(columnNumber > 0){
            columnNumber--;
            res.push_back('A' + (columnNumber % 26));
            columnNumber /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};