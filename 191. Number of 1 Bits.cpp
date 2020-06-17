class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        for(int i=0;i<32;i++) {
            if(n & (1<<i)) {
                count++;
            }
        }
        return count;
    }
};

//Alternative Short code of C++, O(m) by time, m is the count of 1's,  and another several method of O(1) time
Each time of "n &= n - 1", we delete one '1' from n.

int hammingWeight(uint32_t n)
{
    int res = 0;
    while(n)
    {
        n &= n - 1;
        ++ res;
    }
    return res;
}