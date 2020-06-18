class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right=s.size()-1;
        while(left<right) {
            swap(s[left++], s[right--]);
        }
    }
};


//Alternative
class Solution {
public:
    string reverseString(string s) {
        int n = s.size();
        for(int i = 0; i < n/2; i++) {
            swap(s[i], s[n - 1 - i]);
        }
        return s;
    }
};


//Alternative
class Solution {
public:
    string reverseString(string s) {
        return { s.rbegin(), s.rend() };
    }
};