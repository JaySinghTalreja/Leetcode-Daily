#include<bits/stdc++.h>
using namespace std;

void findFactorial(vector<int> &A, int X) {
    int n = A.size();
    int carry = 0;
    for(int i=0;i<n;i++) {
        int indexProd = (A[i] * X) + carry;
        A[i] = indexProd % 10;
        carry = indexProd / 10;
    }
    while(carry) {
        A.push_back(carry%10);
        carry /= 10;
    }
}

void solve() {
    //Factorial of a large Number;
    int X = 10;
    if(X == 1) {
        cout<<1;
        return;
    }
    vector<int> result;
    result.push_back(1);
    for(int i=2;i<=X;i++) {
        findFactorial(result, i);
    }
    int n = result.size()-1;
    for(int i = n;i>=0;i--) {
        cout<<result[i];
    }
}

int main()
{
    solve();
    return 0;
}