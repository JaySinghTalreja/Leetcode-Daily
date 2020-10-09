class Solution {
public:
    unordered_map<int, int> varMap;
    
    int findRightProduct(vector<int> &nums, int index) {
        if(varMap.find(index) != varMap.end()) {
            //cout<<"\nCache";
            return varMap[index];
        }
        if(index == nums.size()) {
            return 1;
        }
        return varMap[index] = (nums[index] * findRightProduct(nums, index+1));
    }
    
    void solve(vector<int> &nums, int index, vector<int> &ans, int leftProduct) {
        if(index == nums.size()) {
            return;
        }
        int rightProduct = findRightProduct(nums, index+1);
        ans.push_back(leftProduct * rightProduct);
        solve(nums, index+1, ans, leftProduct * nums[index]);
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        solve(nums, 0, ans, 1);
        return ans;
    }
};