class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n , 1);
        unordered_map<int, int> full;
        set<int> dry;
        for(int i = 0; i < n; ++i){
            if(rains[i] == 0){
                dry.insert(i);
            } else {
                ans[i] = -1;
                int lake = rains[i];
                if(full.count(lake)){
                    auto it = dry.upper_bound(full[lake]);
                    if(it == dry.end()) return {};
                    ans[*it] = lake;
                    dry.erase(it);
                }
                full[lake] = i;
            }
        }
        return ans;
    }
};