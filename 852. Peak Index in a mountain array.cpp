//Binary Search O(LogN)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int right = A.size() - 1;
        int left = 0;
        int mid;
        int i;
        while(left < right) {
            mid = (left+right)/2; 
            if(A[mid]< A[mid+1]) {
                left = mid+1;
            }
            else{
                right = mid;
            }
        }
        return left;
    }
};



//ALTERNATIVE O(N)
int peakIndexInMountainArray2(vector<int> A) {
        for (int i = 1; i + 1 < A.size(); ++i) if (A[i] > A[i + 1]) return i;
}


//BETTER THAN BINARY SEARHC Golden Section Search
def peakIndexInMountainArray(self, A):
    def gold1(l, r):
        return l + int(round((r - l) * 0.382))

    def gold2(l, r):
        return l + int(round((r - l) * 0.618))
    l, r = 0, len(A) - 1
    x1, x2 = gold1(l, r), gold2(l, r)
    while x1 < x2:
        if A[x1] < A[x2]:
            l = x1
            x1 = x2
            x2 = gold1(x1, r)
        else:
            r = x2
            x2 = x1
            x1 = gold2(l, x2)
    return A.index(max(A[l:r + 1]), l)