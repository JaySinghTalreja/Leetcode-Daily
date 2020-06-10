//NAIVE SOLUTION
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        int m = n/2;
        for(int i=m; i>0; i--){
            if(n % i == 0) {
                int k = n/i;
                string temp = s.substr(0, i);
                string finalOutput = "";
                for(int j=0;j<k;j++) {
                    finalOutput.append(temp);
                }
                if(s.compare(finalOutput) == 0) return true;
            }
        }
        return false;
    }
};