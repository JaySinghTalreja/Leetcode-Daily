#include<bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> A{1, 5, 10, 20, 40, 80}, 
                B{6, 7, 20, 80, 100}, 
                C{3, 4, 15, 20, 30, 70, 80, 120};

    int first = 0, mid=0, last=0;
    while(first < A.size() && mid < B.size() && last < C.size()) {
        //cout<<"P\n";
        if(A[first] == B[mid] && B[mid] == C[last]) {
            cout<<A[first]<<" ";
            first++;
            mid++;
            last++;
        }
        else{
            int maxElement = max(A[first], max(B[mid], C[last]));
            if(A[first] < maxElement) {
                //cout<<"LOOP 1\n";
                first++;
            }
            if(B[mid] < maxElement) {
                //cout<<"LOOP 2\n";
                mid++;
            }
            if(C[last] < maxElement) {
                //cout<<"LOOP 3\n";
                last++;
            }
        }
    }
}

int main()
{
    solve();
    return 0;
}