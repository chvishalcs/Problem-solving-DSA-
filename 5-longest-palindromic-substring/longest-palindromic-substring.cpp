class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), st = 0, len = 1;
        auto ex = [&](int l,int r){
            while(l>=0 && r < n && s[l] == s[r]){
                int cur = r - l + 1;
                if(cur > len) {st = l; len = cur;}
                --l; ++r;
            }
        };
        for(int i = 0; i < n; i++) ex(i,i), ex(i,i+1);
        return s.substr(st,len);
    }
};