/*class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n  = nums.size();
        vector<int> ans(n, 0) ;
        for(int i=0;i<n;i++) {
            ans[(k+i)%n] = nums[i];
        }
        nums = ans;
    }
};
*/
//Juggling Algorithm
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k <=0){
            return;
        }
        int n  = nums.size();
        int ce = nums[0];
        int count=0;
        int index =0;
        int start = 0;
        while(count<n) {
            int temp = nums[(index+k)%n];
            nums[(index+k)%n] = ce;
            ce = temp;
            index = (index+k)%n;
            count++;
            if(index == start && (start+1)<n) {
                ++start;
                index = start;
                ce = nums[index];
            }
            
        }
    }
};

//Alternative
//4 lines to beat 100%

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %=nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};

//Alternative
#4. Swap the last k elements with the first k elements.
Time complexity: O(n). Space complexity: O(1).

class Solution 
{
public:
    void rotate(int nums[], int n, int k) 
    {
        for (; k = k%n; n -= k, nums += k)
        {
            // Swap the last k elements with the first k elements. 
            // The last k elements will be in the correct positions
            // but we need to rotate the remaining (n - k) elements 
            // to the right by k steps.
            for (int i = 0; i < k; i++)
            {
                swap(nums[i], nums[n - k + i]);
            }
        }
    }
};

//Alternative
#2. Start from one element and keep rotating until we have rotated n different elements.
Time complexity: O(n). Space complexity: O(1).

    class Solution 
    {
    public:
        void rotate(int nums[], int n, int k) 
        {
            if ((n == 0) || (k <= 0))
            {
                return;
            }
            
            int cntRotated = 0;
            int start = 0;
            int curr = 0;
            int numToBeRotated = nums[0];
            int tmp = 0;
            // Keep rotating the elements until we have rotated n 
            // different elements.
            while (cntRotated < n)
            {
                do
                {
                    tmp = nums[(curr + k)%n];
                    nums[(curr+k)%n] = numToBeRotated;
                    numToBeRotated = tmp;
                    curr = (curr + k)%n;
                    cntRotated++;
                } while (curr != start);
                // Stop rotating the elements when we finish one cycle, 
                // i.e., we return to start.
                
                // Move to next element to start a new cycle.
                start++;
                curr = start;
                numToBeRotated = nums[curr];
            }
        }
    };

