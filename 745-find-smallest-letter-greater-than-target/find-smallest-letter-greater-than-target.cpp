class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (letters[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        
        // left is the index of first element > target
        // if not found, wrap around
        return letters[left % letters.size()];
    }
};
