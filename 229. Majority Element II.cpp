//Appears More than N/3 Times
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int majority = -1;
        int cnt = 0;
        vector<int> ans;
        unordered_map<int, int> varMap;
        for(int i=0;i<nums.size();i++) {
            varMap[nums[i]]++;
        }
        for(auto var : varMap) {
            if(var.second > nums.size()/3) {
                ans.push_back(var.first);
            }
        }
        return ans;
    }
};



//Efficitne O(N) Time O(1) Space
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int c1=0,c2=0,num1=-1,num2=-1;
        
        // there will be at most two majority element
        // so keep track of two number which can not be elemenated.
        for(auto x:nums)
        {
            if(num1 == x)
            {
                c1++;
            }
            else if(num2 == x)
            {
                c2++;
            }
            else if(c1 == 0)
            {
                num1 = x;
                c1 = 1;
            }
            else if(c2 == 0)
            {
                num2 = x;
                c2 = 1;
            }
            else
            {
                c1--;
                c2--;
            }
        }
        
        //check num1 and num2 are majority element or not...
        c1=0,c2=0;
        for(auto x:nums)
        {
            if(x==num1)
                c1++;
            else if(x == num2)
                c2++;
        }
        if(c1 > n/3)
            ans.push_back(num1);
        if(c2 > n/3)
            ans.push_back(num2);
        return ans;
    }
};
