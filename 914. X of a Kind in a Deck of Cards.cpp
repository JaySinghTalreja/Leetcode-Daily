class Solution {
public:
    //No Using ComapreSecond Instead used a Lambda Function 
    struct CompareSecond{
        bool operator()(const pair<int, int> &s1, const pair<int, int> &s2) const {
            return s1.second < s2.second;
        }
    };
     bool hasGroupsSizeX(vector<int>& deck) {
        if(deck.size() <= 1) {
            return false;
        }
        unordered_map<int, int> c;
        //int minElement = INT_MAX;
        for(int i=0;i<deck.size();i++) {
            c[deck[i]]++;
        }
        pair<int, int> minElement = *min_element(c.begin(), c.end(), [](const pair<int, int> &s1, const pair<int, int> &s2) {
            return s1.second < s2.second;
        });
        cout<<minElement.first<<" ";
         //Finding Common Divisor | Good Approach | Time Complexity of Brute Force GCD is O(N) 
         //The following code runs in O(NM) Where M = Number of element in Map
        for(int i=2;i<=minElement.second;i++) {
            int count = 0;
            for(auto A: c) {
                if(A.second == 1) return false;
                if(A.second % i == 0) {
                    count++;
                }
            }
            if(count == c.size()) return true;
        }
        return false;
     }
};


class Solution{
    public:
  bool hasGroupsSizeX(vector<int>& deck) {
      unordered_map<int,int> m;
      for(int i=0;i<deck.size();i++) {
          ++m[deck[i]];
      }
      int _res = 0;
      for(auto C: m) {
          _res = __gcd(C.second, _res);
      }
      if(_res > 1) return true;
      return false;
  }
};