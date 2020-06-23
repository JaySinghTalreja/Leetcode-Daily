class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int n = J.length();
        int c = 0;
        for(int i=0;i<n;i++) {
            c += count(S.begin(), S.end(), J[i]);
        }
        return c;
    }
};


//Alternative
Explanation
1.read J and build jewels hash set.
2.read S and count jewels.

    Complexity
I used hash set and it's O(1) time to check if it contains an element.
So the total time complexity will be O(J+S), instead of O(JS)
Space is O(J)
int numJewelsInStones(string J, string S) {
        int res = 0;
        unordered_set<char> setJ(J.begin(), J.end());
        for (char s : S)
            if (setJ.count(s)) res++;
        return res;
    }