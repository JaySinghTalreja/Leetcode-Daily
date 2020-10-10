class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0, right = 0;
        int minLength = INT_MAX;
        long int sum = 0;
        while(right<nums.size()) {
            sum += nums[right++];
            while(sum >= s) {
                minLength = min(minLength, right-left);
                sum -= nums[left];
                left++;
            }
            
        }
        return minLength == INT_MAX ? 0 : minLength;
    }
};


//O(NLogN) Solution - Refer Leetcode
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(), len = INT_MAX;
        vector<int> sums(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        for (int i = n; i >= 0 && sums[i] >= s; i--) {
            int j = upper_bound(sums.begin(), sums.end(), sums[i] - s) - sums.begin();
            len = min(len, i - j + 1);
        }
        return len == INT_MAX ? 0 : len;
    }
};