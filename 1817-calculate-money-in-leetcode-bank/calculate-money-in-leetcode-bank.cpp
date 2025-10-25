class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int days = n % 7;
        int total = 28 * weeks + 7 * (weeks - 1) * weeks / 2;
        int start = 1 + weeks;
        total += days * start + (days * (days - 1)) / 2;
        return total;
    }
};