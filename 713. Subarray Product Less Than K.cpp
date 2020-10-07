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


//Much Better Sliding Window Solution
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        int cnt = 0;
        int pro = 1;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            pro *= nums[j];
            while (i <= j && pro >= k) {
                pro /= nums[i++];
            }
            cnt += j - i + 1;
        }
        return cnt;
    }
};