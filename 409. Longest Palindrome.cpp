//My Solution
class Solution {
public:
    int longestPalindrome(string s) {
        if(s.length() == 1){
            return 1;
        }
        unordered_map<char, int> m;
        int result=0;
        for(auto K: s) {
            m[K]++;
        }
        for(auto C: m){
            if(C.second % 2 == 0) {
                result+= C.second/2;
                C.second = 0;
            }
            else if(C.second > 2) {
                result+= C.second / 2;
            }
        }
        if(result*2 < s.length()) {
            return (result*2)+1;
        }
        return result*2;
    }
};


//Alternative
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> m(256, 0);        
        for (auto& c : s) m[c-'\0']++;
        int result = 0;
        for (auto& i : m) result += i%2 ? (result%2 ? i-1 : i) : i;
        return result;
    }
};


Nice idea, checking result for whether we already used an odd one. Can be a bit shorter, though:

result += i - (i & 1 & result);
or
result += i & ~(result & 1);
How I think about the first one: We can use each letters full count i, except when after pairing them up there's an odd extra one (i & 1) 
and we already used an odd extra one (& result), then we need to leave it behind.