// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 0, high = n;
        int mid = 0;
        while(low<high) {
            mid = low + (high-low)/2;
            if(isBadVersion(mid)) {
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return low; /* Because there will alway be a bad version, return lower here */
    }
};