// Time Complexity - O(N + T), Space - O(T) , where T is the length of T

class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char, int> varCount;
        for(int i=0;i<T.size();i++) {
            varCount[T[i]]++;
        }
        string ans = "";
        for(auto C: S) {
            if(varCount.find(C) != varCount.end()) {
                while(varCount[C]--) {
                    ans += C;
                }
                varCount.erase(C);
            }
        }
        for(auto D: varCount) {
            while(D.second--) {
                ans += D.first;
            }
        }
        return ans;
    }
};
