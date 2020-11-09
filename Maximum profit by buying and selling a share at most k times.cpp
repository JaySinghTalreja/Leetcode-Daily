#include<bits/stdc++.h>
using namespace std;
int maxProfit = INT_MIN;
unordered_map<string, int> CACHE;
int solve(vector<int> &A, int K, int index, int minElement = -1, int profit=0) {
    string key = to_string(index) + to_string(minElement) + '#' +to_string(profit);  
    //CACHE CHECK

    if(K==0) {

        return profit;

    }

    if(index == int(A.size())) {

        return profit;

    }

    if(CACHE.find(key) != CACHE.end()) {
        cout<<"\nCache Hits";
        return CACHE[key];
    }
    
    if(minElement == -1) {

        return CACHE[key] = max(solve(A, K, index+1, A[index], profit), solve(A, K, index+1, -1, profit));

    }

    else{

        return CACHE[key] = max(solve(A, K-1, index+1, -1, profit + A[index] - minElement), solve(A, K, index+1, minElement, profit));

    }
}
int main()
 {
     vector<int> A{100, 30, 15, 10, 8, 25, 80};
     int K;
     cin>>K;
     cout<<solve(A, K, 0);
     //maxProfit < 0 ? cout<<0 : cout<<maxProfit;
     return 0;
 }