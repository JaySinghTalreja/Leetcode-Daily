
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