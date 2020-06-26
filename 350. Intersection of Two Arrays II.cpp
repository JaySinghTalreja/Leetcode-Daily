class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_multiset<int> s(nums1.begin(), nums1.end());
        vector<int> result;
        for(int i=0;i<nums2.size();i++) {
            auto it = s.find(nums2[i]);
            if(it != s.end()) {
                result.push_back(*it);
                s.erase(it);
            }        
        }
        return result;
    }
};


//My Alternative
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        for(auto A : nums1) {
            m[A]++;
        }
        vector<int> result;
        for(int i=0;i<nums2.size();i++) {
            if(m[nums2[i]] > 0) {
                result.push_back(nums2[i]);
                m[nums2[i]]--;
            }
        }
        return result; 
    }
};

//Alternative
Hash table solution:
Time: O(m + n) Space: O(m + n)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dict;
        vector<int> res;
        for(int i = 0; i < (int)nums1.size(); i++) dict[nums1[i]]++;
        for(int i = 0; i < (int)nums2.size(); i++)
            if(--dict[nums2[i]] >= 0) res.push_back(nums2[i]);
        return res;
    }
};


Based on C++ map mechanism, if a key is not exist, access the key will assign a default value to the key. 
so if you simply test if map[key] is 0 
or not by using "if (map[key] == 0)" without testing if the key is in the map. you will consume extra space....
you could avoid allocate extra space either by find or count method. I usually use count, it is more concise.


//Alternative 2 Better Optimised Space Complexity
Hash table solution2:
Time: O(m + n) Space: O(m)

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dict;
        vector<int> res;
        for(int i = 0; i < (int)nums1.size(); i++) dict[nums1[i]]++;
        for(int i = 0; i < (int)nums2.size(); i++)
            if(dict.find(nums2[i]) != dict.end() && --dict[nums2[i]] >= 0) res.push_back(nums2[i]);
        return res;
    }
};


Sort and two pointers Solution:
Time: O(max(m, n) log(max(m, n))) Space: O(m + n)

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1 = (int)nums1.size(), n2 = (int)nums2.size();
        int i1 = 0, i2 = 0;
        vector<int> res;
        while(i1 < n1 && i2 < n2){
            if(nums1[i1] == nums2[i2]) {
                res.push_back(nums1[i1]);
                i1++;
                i2++;
            }
            else if(nums1[i1] > nums2[i2]){
                i2++;
            }
            else{
                i1++;
            }
        }
        return res;
    }
};



I think we usually dont consider the output into space complexity. So sort and two pointers solution space complexity should be O(1). 
Thats why we should use this method instead of hashmap method when array is already sorted.


https://leetcode.com/problems/intersection-of-two-arrays-ii/discuss/82263/C%2B%2B-hash-table-solution-and-sort-%2B-two-pointers-solution-with-time-and-space-complexity

