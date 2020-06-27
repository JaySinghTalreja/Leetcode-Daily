class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size()<=1){
            return false;
        }
        unordered_map<int, int> m;
        for(int i=0;i<nums.size();i++) {
            if(m.find(nums[i]) == m.end()) {
                m[nums[i]] = i;
            }
            else if(i-m[nums[i]]<=k ){
                return true;
            }
            else{
                m[nums[i]] = i;
            }
        }
        return false;
    }
};



//Alternative unordered_Set
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
       unordered_set<int> s;
       
       if (k <= 0) return false;
       if (k >= nums.size()) k = nums.size() - 1;
       
       for (int i = 0; i < nums.size(); i++)
       {
           if (i > k) s.erase(nums[i - k - 1]);
           if (s.find(nums[i]) != s.end()) return true;
           s.insert(nums[i]);
       }
       
       return false;
    }
};

Your solution is nice. The only point is that erase take extra time. In worst case it could be O(n). Here is my solution with map:

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    
    unordered_map<int,int> nmap;
    for (int i = 0; i <nums.size();i++)
    {
        if (nmap.count(nums[i]) == 0)
            nmap[nums[i]] = i;
        else if (i - nmap[nums[i]] <=k)
            return true;
        else
            nmap[nums[i]] = i;
    }
    
    return false;
    
}

But this problem can also be solved using a set. And the set will only keep the latest k elements. The insert of unordered_set returns a pair with the second element representing whether the element is actually inserted.

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                st.erase(nums[i - k - 1]);
            }
            if (!st.insert(nums[i]).second) {
                return true;
            }
        }
        return false;
    }
};