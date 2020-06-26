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

//Alternative
https://leetcode.com/problems/squares-of-a-sorted-array/discuss/495394/C%2B%2B%3A-Simplest-one-pass-two-pointers