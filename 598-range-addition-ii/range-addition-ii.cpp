class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if(ops.empty()) return m * n;
        int minA = m;
        int minB = n;
        for(const auto& op : ops){
            minA = min(minA, op[0]);
            minB = min(minB, op[1]);
        }
        return minA * minB;
    }
};