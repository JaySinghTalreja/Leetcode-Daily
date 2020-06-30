class Solution {
public:
    int firstUniqChar(string s) {
        if(s.size() < 2) {
            return s.size() ? 0 :-1;
        }
        unordered_map<char, int> m;
        for(int i=0;i<s.size();i++) {
            m[s[i]]++;
        }
        for(int i=0;i<s.size();i++) {
            if(m[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};


//BEST Alternatove Only Single Pass On S 
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mymap;
        int ans = INT_MAX;
        for(int i = 0; i < s.size(); i++){
            if(mymap.find(s[i]) == mymap.end()){
                mymap[s[i]] = i;
            }
            else{
                mymap[s[i]] = INT_MAX;
            }
        }
        for(auto it : mymap){
            ans = min(it.second, ans);
        }
        return (ans == INT_MAX)? -1 : ans;
    }
};

//Alternative
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>> m;
        int idx = s.size();
        for (int i = 0; i < s.size(); i++) {
            m[s[i]].first++;
            m[s[i]].second = i;
        }
        for (auto &p : m) {
            if (p.second.first == 1) idx = min(idx, p.second.second);
        }
        return idx == s.size() ? -1 : idx;
    }
};
