#include<bits/stdc++.h>
using namespace std;


//ORDER SHOULD BE MAINTAINED
void solve() {

    //INPUT   -5, -2, 5, 2, 4, 7, 1, 8, 0, -8
    vector<int> A{-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    //Brute Force Solution
    for(int i=0;i<A.size();i++) {
        if( i%2 == 0 && A[i] > 0) {
            int right = i + 1;
            bool flag = false;
            while(right<A.size()) {
                if(A[right] < 0) {
                    flag = true;
                    break;
                }
                right++;
            }
            if(flag) {
                int temp = right;
                int key = A[right];
                while(temp > i) {
                    A[temp] = A[temp-1];
                    temp--;
                }
                A[temp] = key;
            }
            
        }
        else if(i % 2 != 0 && A[i] < 0){
            int right = i + 1;
            bool flag = false;
            while(right < A.size()) {
                if(A[right] > 0) {
                    flag = true;
                    break;
                }
                right++;
            }
            if(flag) {
                int temp = right;
                int key = A[right];
                while(temp > i) {
                    A[temp] = A[temp-1];
                    temp--;
                }
                A[i] = key;
            }
            
        }
    }
    for(auto var: A) {
        cout<<var<<" ";
    }
    
}

int main()
{
    solve();
    return 0;
}