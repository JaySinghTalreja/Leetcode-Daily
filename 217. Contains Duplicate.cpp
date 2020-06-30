class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() < 2){
            return false;
        }
        unordered_set<int> check;
        for(int i=0;i<nums.size();i++) {
            if(check.find(nums[i]) == check.end()) {
                check.insert(nums[i]);
                continue;
            }
            return true;
        }
        return false;
    }
};

//Alternative
class Solution {
  public:
    bool containsDuplicate(vector<int>& nums) {
        return set<int>(nums.begin(), nums.end()).size() < nums.size();
    }
};