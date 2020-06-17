class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int currentSum = 0;
        for(int i=0;i<nums.size();i++) {
            if(currentSum*2 == sum - nums[i]) return i;
            currentSum += nums[i];
        }
        return -1;
    }
};