class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if (n < k) return false;

        int total = 1 << k;  // 2^k
        vector<bool> seen(total, false);

        int mask = 0;
        int count = 0;

        for (int i = 0; i < n; i++) {
            // Build rolling k-bit number
            mask = ((mask << 1) & (total - 1)) | (s[i] - '0');

            if (i >= k - 1) {
                if (!seen[mask]) {
                    seen[mask] = true;
                    count++;
                    if (count == total)
                        return true;
                }
            }
        }

        return false;
    }
};