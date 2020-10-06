O(N*N*N) = O(N^3)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4) {
            return {};
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int j=0;j<nums.size() - 3;j++) {
            for(int i=j+1;i<nums.size()-2;i++) {
                int left = i+1;
                int right = nums.size()-1; 
                while(left < right) {
                    int sum = nums[j] + nums[i] + nums[left] + nums[right];
                    if(sum == target) {
                        ans.push_back({nums[j], nums[i], nums[left], nums[right]});
                        while(left < nums.size()-1 && nums[left] == nums[left+1]) left++;
                        while(right > 0 && nums[right] == nums[right-1]) right--;
                    }
                    if(sum < target) {
                        
                        left++;
                    }
                    else{
                        
                        right--;
                    }
                    
                }
                while(i<nums.size()-1 && nums[i] == nums[i+1]) {
                    i++;
                }
            }
            while(j<nums.size()-1 && nums[j] == nums[j+1]) j++;
        }
        
        return ans;
    }
};