class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        int n = code.size();

        // Define valid business lines with required order
        vector<string> order = {"electronics", "grocery", "pharmacy", "restaurant"};
        unordered_map<string, int> priority;
        for (int i = 0; i < order.size(); i++) {
            priority[order[i]] = i;
        }

        // Store valid coupons as (businessPriority, code)
        vector<pair<int, string>> valid;

        for (int i = 0; i < n; i++) {
            // Condition 3: must be active
            if (!isActive[i]) continue;

            // Condition 2: valid business line
            if (priority.find(businessLine[i]) == priority.end()) continue;

            // Condition 1: valid code (non-empty, alphanumeric + underscore)
            if (code[i].empty()) continue;

            bool ok = true;
            for (char c : code[i]) {
                if (!isalnum(c) && c != '_') {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;

            valid.push_back({priority[businessLine[i]], code[i]});
        }

        // Sort by business line order, then lexicographically by code
        sort(valid.begin(), valid.end(), [](auto &a, auto &b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first < b.first;
        });

        // Extract only codes
        vector<string> result;
        for (auto &p : valid)
            result.push_back(p.second);

        return result;
    }
};
