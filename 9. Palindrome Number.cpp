class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int y = x;
        int rev = 0;
        while(y >=10) {
            rev *= 10;
            rev += y % 10;
            y = y/10;
        }
        return (rev == x / 10);
    }
};