//My Solution 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> check(n+1, 0);
        for(int i=0;i<n;i++) {
            check[nums[i]] = 1;
        }
        auto it = find(check.begin(), check.end(), 0);
        if(it != check.end()) {
            //return distance(check.begin(), it);
            return it - check.begin();
        }
        return 0;
    }
};



//1.XOR
public int missingNumber(int[] nums) { //xor
    int res = nums.length; //IMP  Initial Xor with the maximum element;
    for(int i=0; i<nums.length; i++){
        res ^= i;
        res ^= nums[i];
    }
    return res;
}

//2.SUM
public int missingNumber(int[] nums) { //sum
    int len = nums.length;
    int sum = (0+len)*(len+1)/2;   //n(n-1)/2 where n = len+1 and n-1 = len
    for(int i=0; i<len; i++)
        sum-=nums[i];
    return sum;
}

//3.Binary Search
public int missingNumber(int[] nums) { //binary search
    Arrays.sort(nums);
    int left = 0, right = nums.length, mid= (left + right)/2;
    while(left<right){
        mid = (left + right)/2;
        if(nums[mid]>mid) right = mid;
        else left = mid+1;
    }
    return left;
}

Summary:
If the array is in order, I prefer Binary Search method. Otherwise, the XOR method is better.