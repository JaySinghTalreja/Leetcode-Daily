class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diffSum = INT_MAX;
        int diff = INT_MAX;
        for(int i=0;i<nums.size();i++) {
            int left = i+1, right = nums.size()-1;
            while(left < right) {
                int newSum = nums[i] + nums[left] + nums[right];
                if(abs(newSum - target) < diff) {
                    diff = abs(newSum- target);
                    diffSum = newSum;
                }
                
                if(newSum == target) {
                    diffSum = newSum;
                    break;
                }
                if(newSum < target) {
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return diffSum;
    }
};

//Easier Version
public int threeSumClosest(int[] nums, int target) {
    int result = nums[0] + nums[1] + nums[2];
    Arrays.sort(nums);
    
    for (int start = 0; start < nums.length - 2; start++) {
        int middle = start + 1;
        int end = nums.length - 1;
        while (middle < end) {
            int sum = nums[start] + nums[middle] + nums[end];  
            if (sum == target) {
                return target;
            } else if (sum > target) {
                 end--;
            } else {
                middle++;
            }
            if (Math.abs(sum - target) < Math.abs(result - target)) {
                result = sum;
            }
        }
    }
    return result;
}