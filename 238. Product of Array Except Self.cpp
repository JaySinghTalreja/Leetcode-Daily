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

// Slightly Better
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
    
    void solve(vector<int> &nums, int index, vector<int> &ans) {
        int leftProduct = 1;
        for(int i=index;i<nums.size();i++) {
            ans.push_back(leftProduct * findRightProduct(nums, i+1));
            leftProduct = leftProduct * nums[i];
        }
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        solve(nums, 0, ans);
        return ans;
    }
};



//Ierative Solution More Better
class Solution {
public:
    void solve(vector<int> &nums,vector<int> &ans) {
        int product = 1;
        int zeroCount = 0;
        for(int i=0;i<nums.size();i++) {
            if(!nums[i]) {
                zeroCount++;
            }
            else{
                product *= nums[i];
            }
        }
        if(zeroCount > 1) {
            for(int i=0;i<nums.size();i++) {
                ans.push_back(0);
            }
        }
        else if(zeroCount == 1){
            for(int i=0;i<nums.size();i++) {
                if(nums[i] == 0) {
                    ans.push_back(product);
                }
                else{
                    ans.push_back(0);
                }
            }
        }
        else{
            for(int i=0;i<nums.size();i++) {
                ans.push_back(product / nums[i]);
            }
        }
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        solve(nums,ans);
        return ans;
    }
};


//Leetcode O(n) Time and O(1) Space
public class Solution {
public int[] productExceptSelf(int[] nums) {
    int n = nums.length;
    int[] res = new int[n];
    res[0] = 1;
    for (int i = 1; i < n; i++) {
        res[i] = res[i - 1] * nums[i - 1];
    }
    int right = 1;
    for (int i = n - 1; i >= 0; i--) {
        res[i] *= right;
        right *= nums[i];
    }
    return res;
}