class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        string best = s;
        
        // Generate each unique rotation reachable by repeatedly rotating right by b
        vector<bool> seenRot(n, false);
        int shift = 0;
        while (!seenRot[shift]) {
            seenRot[shift] = true;
            // rotate right by 'shift' (equivalently rotate right by shift positions)
            string rot = s.substr(n - shift) + s.substr(0, n - shift);
            
            // Try all additions to odd indices (0..9 times)
            for (int oddAdd = 0; oddAdd < 10; ++oddAdd) {
                string t = rot;
                // apply oddAdd times adding 'a' to odd indices
                for (int i = 1; i < n; i += 2) {
                    int digit = (t[i] - '0' + oddAdd * a) % 10;
                    t[i] = char('0' + digit);
                }
                
                if (b % 2 == 0) {
                    // If b is even, parity of indices never changes, we cannot affect even indices:
                    if (t < best) best = t;
                } else {
                    // If b is odd, parity can change after rotations so we can also effectively
                    // add to even indices; try all possibilities for even additions (0..9)
                    for (int evenAdd = 0; evenAdd < 10; ++evenAdd) {
                        string u = t;
                        for (int i = 0; i < n; i += 2) {
                            int digit = (u[i] - '0' + evenAdd * a) % 10;
                            u[i] = char('0' + digit);
                        }
                        if (u < best) best = u;
                    }
                }
            }
            
            // advance shift by b (right rotation by b again)
            shift = (shift + b) % n;
        }
        
        return best;
    }
};
