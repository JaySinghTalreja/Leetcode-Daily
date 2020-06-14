class Solution {
public:
    bool isPowerOfTwo(long long int x) {
        return (x && !(x & (x-1)));
    }
};


//Alternative
https://leetcode.com/problems/power-of-two/discuss/63966/4-different-ways-to-solve-Iterative-Recursive-Bit-operation-Math