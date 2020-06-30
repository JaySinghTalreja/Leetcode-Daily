class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.length() != B.length()) {
            return false;
        }
        unordered_set<char> x(A.begin(), A.end());
        if(A == B && x.size() < B.size()) return true;
        int count = 0;
        //unordered_map<string , int> m;
        vector<int> check;
        for(int i=0;i<A.length();i++) {
            if(A[i] != B[i]){
                check.push_back(i);
                count++;
            }
            if(check.size() > 2) return false;
        }
        
        return count==2 && (A[check[0]] == B[check[1]] && A[check[1]] == B[check[0]]); 
        //return (count != 0 && diff != 0) ? false : true;
    }
};

//Space - O(N)
//Time - O(N)