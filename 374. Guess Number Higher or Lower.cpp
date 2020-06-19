/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        int mid = left + (right-left)/2;
        while(left<=right) {
            mid = left + (right-left)/2;
            int result = guess(mid);
            if(result == 0) {
                return mid;
            }
            else if(result == 1) {
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return mid;
    }
};


//Alternative
int guessNumber(int n) {
    int cur = (1 + n) >> 1;
    int t;
    int step = cur;
    do{
        t = guess(cur);
        step = step >> 1 ? step  >> 1 : 1;   //step >> 1 is same as step = step / 2;
        cur += t*step;
    } while(t != 0);
    
    return cur;
}
