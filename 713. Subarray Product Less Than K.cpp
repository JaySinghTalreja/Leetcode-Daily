class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left =0, right =0;
        int product = nums[0];
        int cnt = 0;
        while(left < nums.size() && right < nums.size()) {
            if(product < k) {
                right++;
                if(right >= left) {
                    cnt += right-left;
                }
                //For Last Value as it goes out of the array range
                if(right < nums.size())
                    product *= nums[right];
            }
            else{
                product /= nums[left];
                left++;
            }
        }
        return cnt;
    }
    
};