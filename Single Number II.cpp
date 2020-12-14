class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unsigned int finalCount = 0;
        for(int i=0;i<32;i++) {
            int count = 0;
            for(auto var : nums) {
                if(var & (1<<i)) {
                    count++;
                }
            }
            finalCount<<1;
            if(count%3 != 0) {
                finalCount |= (1<<i);
            }
        }
        return finalCount;
    }
    
};
