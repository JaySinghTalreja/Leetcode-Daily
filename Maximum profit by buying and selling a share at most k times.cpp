#include<bits/stdc++.h>
using namespace std;
int maxProfit = INT_MIN;
unordered_map<string, int> CACHE;
int solve(vector<int> &A, int K, int index, bool flag = false) {
    string key = to_string(index) + '$' + to_string(K) + '$' + to_string(flag);
    //CACHE CHECK

    if(K==0) {

        return 0;

    }

    if(index == 0) {

        return flag ? -A[index] : 0;

    }
    
    if(CACHE.find(key) != CACHE.end()) {
        cout<<"\nCache Hits";
        return CACHE[key];
    }
    
    if(flag == false) {

        return CACHE[key] = max(A[index] + solve(A, K, index-1, true), solve(A, K, index-1, flag));

    }
    else{

        return CACHE[key] = max(-A[index] + solve(A, K-1, index-1, false), solve(A, K, index-1, flag));

    }
}
int main()
 {
     vector<int> A{12, 14, 17, 10, 14, 13, 12, 15};
     int K;
     cin>>K;
     cout<<solve(A, K, A.size()-1);
     //maxProfit < 0 ? cout<<0 : cout<<maxProfit;
     return 0;
 }