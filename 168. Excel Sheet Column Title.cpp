class Solution {
public:
    string convertToTitle(int n) {
        string r = "";
        while(n>0) {
            n--;
            int M = n % 26;
            n /= 26;
            r += (M + 'A');
        }
        reverse(r.begin(), r.end());
        return r;
    }
};