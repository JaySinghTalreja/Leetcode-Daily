class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        if(nums.size() < 3) {
            return output;
        }
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++) {
            //int sum = nums[i];
            if(i>0 && nums[i] == nums[i-1])
                continue;
            int left = i+1;
            int right = nums.size() - 1;
            while(left < right) {
                int newSum = nums[left] + nums[right] + nums[i];
                if(newSum < 0) {
                    left++;
                }
                else if(newSum > 0) {
                    right--;
                }
                else{
                    output.push_back({nums[i], nums[left], nums[right]});
                    while(left<right && nums[left] == nums[left+1]) left++;
                    while(left<right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                }
            }
        }
        //output.erase(unique(output.begin(), output.end()), output.end());
        return output;
    }
};

//Special test Case
/*


1.Duplicates
[-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6]
Output
[[-4,-2,6],[-4,0,4],[-4,1,3],[-4,2,2],[-2,-2,4],[-2,0,2],[-2,-2,4],[-2,0,2]]
Expected
[[-4,-2,6],[-4,0,4],[-4,1,3],[-4,2,2],[-2,-2,4],[-2,0,2]]

2. Duplicates
[0, 0, 0, 0]
[]


*/