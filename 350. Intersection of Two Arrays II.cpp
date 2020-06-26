//BEST BINARY SEARCH Solution
//https://leetcode.com/problems/intersection-of-two-arrays-ii/discuss/439955/JAVA-SOLUTION-%2B-4-FOLLOW-UPS

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

Solution 2: sort + binary search

time complexity: max(O(mlgm), O(nlgn), O(mlgn)) or max(O(mlgm),
O(nlgn), O(nlgm))
O(mlgm) <-- sort first array
O(nlgn) <--- sort second array
O(mlgn) <--- for each element in nums1, do binary search in nums2
O(nlgm) <--- for each element in nums2, do binary search in nums1
space complexity: depends on the space complexity used in your
sorting algorithm, bounded by max(O(m), O(n))
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ret;
    if(nums1.empty() || nums2.empty()) return ret;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int j=0;
    for(int i=0; i<nums1.size(); ) {
        int index = lower_bound(nums2, nums1[i]);
        int count2 = 0;
        while(index<nums2.size() && nums2[index]==nums1[i]) {
            count2++; 
            index++;
        }
        int count1 = 0;
        while(nums1[j]==nums1[i]) {
            count1++;
            j++;
        }
        ret.insert(ret.end(),min(count1,count2),nums1[i]);
        i=j;
    } 
    return ret;
}
//********************************************************IMPLEMENTED LOWER BOUND USING BINARY SEARCH *************************8
int lower_bound(const vector<int>& nums, int target) {
    int l=0, r=nums.size()-1;
    while(l<r) {
        int m=l+(r-l)/2;
        if(nums[m]<target) {l=m+1;}
        else {r=m;}
    }
    return r;
}

