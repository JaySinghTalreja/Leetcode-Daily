#include<bits/stdc++.h>
using namespace std;
int doBruteForce(vector<int> &A, int K,int index, bool flag = false,int currentHeight = 0) {

    if(index == 0) {
        if(flag == false) {
            return A[index];
        }
        else{
            return max(abs(abs( A[index] + K) - abs(currentHeight) ), abs( abs(A[index] - K) - abs(currentHeight)) );
        }
    }
    
    int maxDiff = 0;
    
    if(flag == false) {
        maxDiff = min(doBruteForce(A, K, index-1, true , A[index] + K), min(doBruteForce(A, K, index-1, true, A[index] - K),
        doBruteForce(A, K, index-1, false)));
    }
    else{
        int currentMax = max(abs(abs( A[index] + K) - abs(currentHeight) ), abs( abs(A[index] - K) - abs(currentHeight)) );
        maxDiff = min(currentMax, doBruteForce(A, K, index-1, true, currentHeight));
    }

    return maxDiff;

}

void solve() {

    vector<int> A{4, 6};
    int K = 6;
    cout<<doBruteForce(A, K, A.size()-1);
}

int main()
{
    solve();
    return 0;
}