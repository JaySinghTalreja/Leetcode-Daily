//My Solution
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_multiset<char> V;
        for(int i=0;i<t.length();i++){
            V.insert(t[i]);
        }
        cout<<endl;
        for(int i=0;i<s.length();i++){
            auto it = V.find(s[i]);
            if(it != V.end()) {
                V.erase(it);
            }
            else{
                return false;
            }
        }
        return V.empty() == 1 ? 1 : 0;
    }
};


//Alternative Solutions
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int n = s.length();
        unordered_map<char, int> counts;
        for (int i = 0; i < n; i++) {
            counts[s[i]]++;
            counts[t[i]]--;
        }
        for (auto count : counts)
            if (count.second) return false;
        return true;
    }
};

//2
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int n = s.length();
        int counts[26] = {0};
        for (int i = 0; i < n; i++) { 
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
            if (counts[i]) return false;
        return true;
    }
};

//3
class Solution {
public:
    bool isAnagram(string s, string t) { 
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t; 
    }
};
