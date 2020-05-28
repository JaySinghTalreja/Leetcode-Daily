class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> varMap;
        vector<int> varSolution;
        for(int i=0;i<nums.size();i++) {
            int varSum = target - nums[i];
            if(varMap.find(varSum) != varMap.end()) {
                varSolution.push_back(varMap[varSum]);  
                varSolution.push_back(i);
                return varSolution;
            }
            varMap[nums[i]] = i;
        }
        return varSolution;
    }
};