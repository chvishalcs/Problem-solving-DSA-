class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, long long> mp;
        for(int p : power) mp[p] += p;
        vector<int> vals;
        vals.reserve(mp.size());
        for(auto &it : mp) vals.push_back(it.first);
        sort(vals.begin(), vals.end());
        int n = vals.size();
        vector<long long> dp(n, 0);
        for(int i = 0; i < n; i++){
            dp[i] = mp[vals[i]];
            int j = upper_bound(vals.begin(), vals.end(), vals[i] - 3) - vals.begin() - 1;
            if(j >= 0) dp[i] += dp[j];
            if(i > 0) dp[i] = max(dp[i], dp[i - 1]);
        }
        return dp[n - 1];
    }
};