class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for (int n : nums) {
            int cnt = 0;
            int sum = 1 + n;

            for (int d = 2; d * d <= n; d++) {
                if (n % d == 0) {
                    int other = n / d;

                    if (d == other) { // perfect square
                        cnt++;
                        sum += d;
                    } else {
                        cnt += 2;
                        sum += d + other;
                    }

                    if (cnt > 2) break; // more than 4 divisors
                }
            }

            if (cnt == 2) {
                ans += sum;
            }
        }
        return ans;
    }
};
