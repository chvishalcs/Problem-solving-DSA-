class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        // Group 1: indices 0,2
        string a1 = {s1[0], s1[2]};
        string b1 = {s2[0], s2[2]};
        
        // Group 2: indices 1,3
        string a2 = {s1[1], s1[3]};
        string b2 = {s2[1], s2[3]};
        
        sort(a1.begin(), a1.end());
        sort(b1.begin(), b1.end());
        sort(a2.begin(), a2.end());
        sort(b2.begin(), b2.end());
        
        return (a1 == b1 && a2 == b2);
    }
};