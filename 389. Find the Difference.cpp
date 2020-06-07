class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_multiset<char> v;
        for(auto a : s){
            v.insert(a);
        }
        char ans;
        unordered_multiset<char>::iterator it;
        for(auto a : t) {
            it = v.find(a);
            if(it!= v.end()) {
                v.erase(it);
            }
            else{
                ans = a;
            }
            
        }
        return ans;
    }
};