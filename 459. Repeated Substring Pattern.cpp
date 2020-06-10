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

//Alternative 1 
bool repeatedSubstringPattern(string str) 
{
    return (str + str).substr(1, str.size() * 2 - 2).find(str)!=-1;
}

Cool!
Following is my understanding:
If there is such pattern, the original string could be represented as following:

origin_str = pattern + pattern + ... + pattern =  m * pattern; 
With doubling:

origin_str + origin_str = 2 * m * pattern;
After removing head and rear:

new_str = pattern_wo_head + (2m-2) * pattern + pattern_wo_rear 
So, origin_str(m * pattern) could be found in new_str if m >= 2.




//Alternative 2 - KMP
https://leetcode.com/problems/repeated-substring-pattern/discuss/94397/C%2B%2B-O(n)-using-KMP-32ms-8-lines-of-code-with-brief-explanation.
bool repeatedSubstringPattern(string str) {
        int len = str.length(), i = 0, j = 1;
        int p[len];
        while (j < len)
            if (str[i] == str[j])
                p[j++] = ++i;
            else {
                if (!i) 
                    p[j++] = 0;
                else
                    i = p[i - 1];
            }
        return p[len - 1] && len % (len - p[len - 1]) == 0;
    }