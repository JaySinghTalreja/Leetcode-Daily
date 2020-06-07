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


//Alternaitve
The trick is to notice that string t and string s differ by only 1 extra character, which means that if you combine both the strings, all characters have an even count, except for the unique one.

This is great since XOR operator (^) has the property that a ^ a = 0. and a ^ 0 = a. This implies that all even count characters XOR ed together will cancel out.

Thus,. if you xor all characters in s and t with 0, you end up with the unique character since all other characters have even count and thus cancel out.

class Solution {
public:
    char findTheDifference(string s, string t) {
        int x = 0;
        for(auto n: s += t) {
            x ^= (int) n;
        }
		
        return x;
    }
};
