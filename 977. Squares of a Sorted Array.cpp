class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> P(A.size(), 0);
        int n = A.size();
        int i=0, j=n-1;
        for(int k = n-1;k>=0;k--) {
            if(abs(A[i]) > abs(A[j])) {
                P[k] = A[i] * A[i];
                i++;
            }
            else{
                P[k] = A[j] * A[j];
                j--;
            }
        }
        return P;
    }
};

//Alternative
Approach 2: Two Pointer
Intuition

Since the array A is sorted, loosely speaking it has some negative elements with squares in decreasing order, then some non-negative elements with squares in increasing order.

For example, with [-3, -2, -1, 4, 5, 6], we have the negative part [-3, -2, -1] with squares [9, 4, 1], and the positive part [4, 5, 6] with squares [16, 25, 36]. Our strategy is to iterate over the negative part in reverse, and the positive part in the forward direction.

Algorithm

We can use two pointers to read the positive and negative parts of the array - one pointer j in the positive direction, and another i in the negative direction.

Now that we are reading two increasing arrays (the squares of the elements), we can merge these arrays together using a two-pointer technique.



class Solution {
    public int[] sortedSquares(int[] A) {
        int N = A.length;
        int j = 0;
        while (j < N && A[j] < 0)
            j++;
        int i = j-1;

        int[] ans = new int[N];
        int t = 0;

        while (i >= 0 && j < N) {
            if (A[i] * A[i] < A[j] * A[j]) {
                ans[t++] = A[i] * A[i];
                i--;
            } else {
                ans[t++] = A[j] * A[j];
                j++;
            }
        }

        while (i >= 0) {
            ans[t++] = A[i] * A[i];
            i--;
        }
        while (j < N) {
            ans[t++] = A[j] * A[j];
            j++;
        }

        return ans;
    }
}


//Double Ended Queue
/* Idea ---- 
1) Store the array in a double ended queue  
2) Now the element with the largest magnitude would be at the front or at the back
3) Moreover, the element with the largest magnitude would have the largest square value
4) So, Pop it and similarly get the second largest in magnitude
5) Finally, Reverse the answer to sort in non_decreasing order
*/

class Solution
{
public:
    vector<int> sortedSquares(vector<int>& myVector);
};

/* Returns the vector of sorted square */
vector<int> Solution :: sortedSquares(vector<int>& myVector)
{
    // Declare the deque and the container to hold the answer
    vector<int> answer;
    deque<int> dq;
    
    // Fill all elements in the deque
    for(auto ele: myVector)
        dq.push_back(ele);
    
    // Keep extracting the element with the highest magnitude
    while(!dq.empty())
    {
        // Get a copy
        int front = dq.front();
        int back = dq.back();
        
        // If the largest magnitude occurs at the front, pop it and append it
        if(abs(front) > abs(back))
        {
            dq.pop_front();
            answer.push_back(front*front);
        }
        
        // Else pop the back and append it to answer
        else
        {
            dq.pop_back();
            answer.push_back(back*back);
        }
    }
    
    // Fianlly Reverse the answer to sort in non decreasing order
    reverse(answer.begin(), answer.end());
    
    // Return the new answer
    return answer;
}


//Alternative
https://leetcode.com/problems/squares-of-a-sorted-array/discuss/495394/C%2B%2B%3A-Simplest-one-pass-two-pointers