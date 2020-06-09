//Using Kadane's Algorithm for Maximum Sum Subarray
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxCurrentSum =0;
        int maxGlobalSum = INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++){
            maxCurrentSum = max(nums[i], maxCurrentSum + nums[i]);
            if(maxCurrentSum > maxGlobalSum) {
                maxGlobalSum = maxCurrentSum;
            }
        }
        return maxGlobalSum;
    }
};