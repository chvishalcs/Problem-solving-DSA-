class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> parts;
        int count = 0;
        int start = 0;

        // Split into primitive special substrings
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') count++;
            else count--;

            // Found a balanced substring
            if (count == 0) {
                // Remove outer 1 and 0 and recurse
                string inner = makeLargestSpecial(s.substr(start + 1, i - start - 1));
                parts.push_back("1" + inner + "0");
                start = i + 1;
            }
        }

        // Sort descending to maximize lexicographically
        sort(parts.begin(), parts.end(), greater<string>());

        // Concatenate
        string result;
        for (string &p : parts)
            result += p;

        return result;
    }
};