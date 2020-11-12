#include<bits/stdc++.h>
using namespace std;



void solve() {
    //Input -5, 3, 4, 5, -6, -2, 8, 9, -1, -4
    vector<int> A{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //Shift All Negative Elements to the right
    int left = 0, right = A.size()-1;
    while(left <= right) {
        if(A[left] < 0) {
            swap(A[left], A[right]);
            right--;
        }
        else left++;
    }
    for(auto var : A) {
        cout<<var<<" ";
    }
    if(left == 0 || right == A.size()) return;
    right = left;
    left = 0;
    cout<<endl;
    while(left < right && right < A.size()) {
        swap(A[left], A[right]);
        left += 2;
        right++;
    }
    for(auto var : A) {
        cout<<var<<" ";
    }

}

int main()
{
    solve();
    return 0;
}