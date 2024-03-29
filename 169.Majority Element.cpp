
//My Solution
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> H;
        for(auto A: nums){
            H[A]++;
        }
        int maxElement = 0;
        int maxFrequency = INT_MIN;
        for(auto A:H){
            if(A.second > maxFrequency){
                maxElement = A.first;
                maxFrequency = A.second;
            }
        }
        return maxElement;
    }
};


//Using Bit Manipulation
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = 0;
        for (unsigned int i = 0, mask = 1; i < 32; i++, mask <<= 1) {
            int bits = 0;
            for (int num : nums) {
                if (num & mask) {
                    bits++;
                }
            }
            if (bits > nums.size() / 2) {
                majority |= mask;
            }
        }
        return majority;
    }
};

//Moore's Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int counter = 0, majority;
        for (int num : nums) {
            if (!counter) {
                majority = num;
            }
            counter += num == majority ? 1 : -1;
        }
        return majority;
    }
};

//Divide and Conquer
//Recursively find the majority in the two halves of nums and combine the results. The base case is that the majority element of a single-element array is just that element.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return majority(nums, 0, nums.size() - 1);
    }
private:
    int majority(vector<int>& nums, int l, int r) {
        if (l == r) {
            return nums[l];
        }
        int m = l + (r - l) / 2, lm = majority(nums, l, m), rm = majority(nums, m + 1, r);
        if (lm == rm) {
            return lm;
        }
        return count(nums.begin() + l, nums.begin() + r + 1, lm) > count(nums.begin() + l, nums.begin() + r + 1, rm) ? lm : rm;
    }
}; 
